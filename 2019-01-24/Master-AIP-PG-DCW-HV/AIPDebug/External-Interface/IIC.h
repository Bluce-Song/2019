#ifndef __I2C_H__
#define __I2C_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef 	unsigned char			BYTE;
typedef 	unsigned char			UCHAR;
typedef 	unsigned short int		WORD;
typedef 	unsigned int			HANDLE;
typedef 	unsigned int			BOOL;

/*
SlaveAddr： 要操作的I2C器件的设备物理地址
RegAddr：   要操作的设备的存贮器地址
pInData：   要写入/读出的数据
BUFFiDLen： 要写入/读出的数据的字节长度
*/

typedef struct 
{
	BYTE 	SlaveAddr;
	WORD 	RegAddr;
	BYTE 	*pDataBuff;
	int  	iDLen;
} I2CParameter, *pI2CParameter;



int  I2COpen();

int GPIO_OutEnable(unsigned int dwEnBits);
int GPIO_OutDisable(unsigned int dwDisBits);
int GPIO_OutSet(unsigned int dwSetBits);
int GPIO_OutClear(unsigned int dwClearBits);
int GPIO_PinState(unsigned int* dwClearBits);


void DS1302ByteWrite(unsigned char dat);
unsigned char DS1302ByteRead();
void DS1302SingleWrite(unsigned char reg, unsigned char dat);
unsigned char DS1302SingleRead(unsigned char reg);



#ifdef __cplusplus
}
#endif
#endif

