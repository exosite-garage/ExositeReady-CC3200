#include <stdbool.h>
#include <stdint.h>
#include "hw_types.h"
#include "gpio.h"
#include "led_ring.h"


//================================
void SendLedDataRes(void)
//================================
{
unsigned int i;
//RES
for(i=0;i<400;i++)
	{
	GPIOPinWrite(0x40005000,0x02,0x00); 	//Off
	}
}
#define		LED_DATA_HIGH	GPIOPinWrite(0x40005000,0x02,0x02)	//GPIO9
#define 	LED_DATA_LOW	GPIOPinWrite(0x40005000,0x02,0x00)	//GPIO9
//================================
void SendOneLedData( unsigned long LedData)
//================================
{
	//bit23
	LED_DATA_HIGH;
	if(LedData&0x00800000)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit22
	LED_DATA_HIGH;
	if(LedData&0x00400000)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit21
	LED_DATA_HIGH;
	if(LedData&0x00200000)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit20
	LED_DATA_HIGH;
	if(LedData&0x00100000)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit19
	LED_DATA_HIGH;
	if(LedData&0x00080000)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit18
	LED_DATA_HIGH;
	if(LedData&0x00040000)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit17
	LED_DATA_HIGH;
	if(LedData&0x00020000)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit16
	LED_DATA_HIGH;
	if(LedData&0x00010000)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit15
	LED_DATA_HIGH;
	if(LedData&0x00008000)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit14
	LED_DATA_HIGH;
	if(LedData&0x00004000)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit13
	LED_DATA_HIGH;
	if(LedData&0x00002000)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit12
	LED_DATA_HIGH;
	if(LedData&0x00001000)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit11
	LED_DATA_HIGH;
	if(LedData&0x00000800)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit10
	LED_DATA_HIGH;
	if(LedData&0x00000400)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit9
	LED_DATA_HIGH;
	if(LedData&0x00000200)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit8
	LED_DATA_HIGH;
	if(LedData&0x00000100)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit7
	LED_DATA_HIGH;
	if(LedData&0x00000080)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit6
	LED_DATA_HIGH;
	if(LedData&0x00000040)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit5
	LED_DATA_HIGH;
	if(LedData&0x00000020)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit4
	LED_DATA_HIGH;
	if(LedData&0x00000010)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit3
	LED_DATA_HIGH;
	if(LedData&0x00000008)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit2
	LED_DATA_HIGH;
	if(LedData&0x00000004)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit1
	LED_DATA_HIGH;
	if(LedData&0x00000002)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;
	//bit0
	LED_DATA_HIGH;
	if(LedData&0x00000001)	LED_DATA_HIGH;		else	LED_DATA_LOW;
	LED_DATA_LOW;

}

//================================
void Send24LedData(unsigned char Percent)
//================================
{
	unsigned char i,j;
	unsigned long data[24];

//				 G R B
	data[0] =0x0000ff00;
	data[1] =0x0000ff00;
	data[2] =0x0000ff00;
	data[3] =0x0000ff00;
	data[4] =0x00ffff00;
	data[5] =0x00ffff00;
	data[6] =0x00ffff00;
	data[7] =0x00ffff00;
	data[8] =0x00ff0000;
	data[9] =0x00ff0000;
	data[10]=0x00ff0000;
	data[11]=0x00ff0000;
	data[12]=0x00ff00ff;
	data[13]=0x00ff00ff;
	data[14]=0x00ff00ff;
	data[15]=0x00ff00ff;
	data[16]=0x0000ffff;
	data[17]=0x0000ffff;
	data[18]=0x0000ffff;
	data[19]=0x0000ffff;
	data[20]=0x00ffffff;
	data[21]=0x00ffffff;
	data[22]=0x00ffffff;
	data[23]=0x00ffffff;
	j=Percent>>2;
	for(i=0;i<24;i++)
		{
		if(j==0)
			data[i]=0;
		else
			j--;
		}
	SendLedDataRes();
	for(i=0;i<24;i++)
		{
		SendOneLedData(data[i]);
		}
	LED_DATA_HIGH;
}

//=========================
void LedRingLine(void)
//=========================
{
	unsigned int i,j;
	for(i=0;i<100;i++)
	{
		for(j=0;j<10;j++)
		{
		Send24LedData(i);
		}
	}
	for(i=100;i>0;i--)
	{
		for(j=0;j<10;j++)
		{
		Send24LedData(i);
		}
	}

}
