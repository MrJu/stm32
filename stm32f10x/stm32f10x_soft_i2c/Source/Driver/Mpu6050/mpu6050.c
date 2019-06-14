#include "mpu6050.h"
#include "printk.h"
#include "soft_i2c.h"

void MPU6050_Write_Reg(uint8_t reg_addr,uint8_t reg_data)
{
	Soft_I2C_Start();
	Soft_I2C_Send_Byte(MPU6050_SLAVE_ADDRESS);
	Soft_I2C_Wait_Ack();
	Soft_I2C_Send_Byte(reg_addr);
	Soft_I2C_Wait_Ack();
	Soft_I2C_Send_Byte(reg_data);
	Soft_I2C_Wait_Ack();
	Soft_I2C_Stop();
}

void MPU6050_Read_Data(uint8_t reg_addr ,uint8_t *Read, uint8_t num)
{
	unsigned char i;
	
	Soft_I2C_Start();
	Soft_I2C_Send_Byte(MPU6050_SLAVE_ADDRESS);
	Soft_I2C_Wait_Ack();
	Soft_I2C_Send_Byte(reg_addr);
	Soft_I2C_Wait_Ack();
	
	Soft_I2C_Start();
	Soft_I2C_Send_Byte(MPU6050_SLAVE_ADDRESS+1);
	Soft_I2C_Wait_Ack();
	
	for(i=0;i<(num-1);i++){
		*Read=Soft_I2C_Read_Byte(1);
		Read++;
	}
	*Read=Soft_I2C_Read_Byte(0);
	Soft_I2C_Stop();
}

void MPU6050_Init(void)
{
  int i=0,j=0;

	/* delay for hardware ready */
  for(i=0; i<1000; i++)
  {
    for(j=0; j<1000; j++)
    {
      ;
    }
  }

	MPU6050_Write_Reg(MPU6050_RA_PWR_MGMT_1, 0x00); /* wake up from hibernate */
	MPU6050_Write_Reg(MPU6050_RA_SMPLRT_DIV , 0x07); /* set sample rate 1KHz */
	MPU6050_Write_Reg(MPU6050_RA_CONFIG , 0x06); /* freq 1K, band 5K */
	MPU6050_Write_Reg(MPU6050_RA_ACCEL_CONFIG , 0x00); /* 2G mode£¬no self-check */
	MPU6050_Write_Reg(MPU6050_RA_GYRO_CONFIG, 0x18); /* typical settings 0x18(no self-check 2000deg/s) */
}

int8_t MPU6050_Read_ID(void)
{
	uint8_t Re = 0;
	MPU6050_Read_Data(MPU6050_RA_WHO_AM_I, &Re, 1); /* obtain device addr */
	if(Re != 0x68)
	{
		printf("No MPU6050 device was found!\n\r");
		return -1;
	}
	else
	{
		return 0;
	}
}

void MPU6050_Read_Acc(short *accData)
{
    u8 buf[6];
    MPU6050_Read_Data(MPU6050_ACC_OUT, buf, 6);
    accData[0] = (buf[0] << 8) | buf[1];
    accData[1] = (buf[2] << 8) | buf[3];
    accData[2] = (buf[4] << 8) | buf[5];
}

void MPU6050_Read_Gyro(short *gyroData)
{
    u8 buf[6];
    MPU6050_Read_Data(MPU6050_GYRO_OUT,buf,6);
    gyroData[0] = (buf[0] << 8) | buf[1];
    gyroData[1] = (buf[2] << 8) | buf[3];
    gyroData[2] = (buf[4] << 8) | buf[5];
}

void MPU6050_Read_Temp(short *tempData)
{
	u8 buf[2];
	MPU6050_Read_Data(MPU6050_RA_TEMP_OUT_H, buf, 2); /* temperature */
	*tempData = (buf[0] << 8) | buf[1];
}

void MPU6050_Return_Temp(float *Temperature)
{
	short temp3;
	u8 buf[2];
	
	MPU6050_Read_Data(MPU6050_RA_TEMP_OUT_H, buf, 2); /* temperature */
  temp3= (buf[0] << 8) | buf[1];	
	*Temperature=((double) temp3/340.0)+36.53;
}

int32_t MPU6050_Show_Data(void)
{
	short Accel[3];
	short Gyro[3];
	float Temp;

	if (MPU6050_Read_ID()) {
		printk("MPU6050_Read_ID error!\n\r");
		return -1;
	}

	MPU6050_Read_Acc(Accel);			
	printk("ACC\t%8d%8d%8d\n\r", Accel[0], Accel[1], Accel[2]);

	MPU6050_Read_Gyro(Gyro);
	printk("GYRO\t%8d%8d%8d\n\r", Gyro[0], Gyro[1], Gyro[2]);

	MPU6050_Return_Temp(&Temp); 
	printk("TEMP\t%8.2f\n\r", Temp);
	printk("********************************\n\r");
	
	return 0;
}
