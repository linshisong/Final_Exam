/**
  * @file        sysconfig.h
  * @author      陈维
  * @version     V01
  * @date        2016.09.21
  * @brief       
  * @note        系统配置相关
  *
  * @attention   COYPRIGHT INMOTION ROBOT
  **/
#ifndef _SYSCONFIG_H_
#define _SYSCONFIG_H_

#include "stm32f3xx_hal.h"
#include "pro.h" 

#define DATA_AMOUNT 4096  /* Lidar 数据总量最大值*/
#define DATA_SHIFT 3   //每个点用几个byte表示 dis:2byte , confidence : 1byte
#define DATA_BEGIN  7  //距离数据和置信度数据在待发送buffer中的起始位置

#define CONFIG_BASE_ADDRESS 0x08008000

#define PIXEL_1_FPS (1024+3) /* CCD 1 帧数据的数据量*/

typedef struct
{
	uint32_t PixOffset;
	uint32_t AngleOffset;
	uint32_t GivenSpeed;
    uint32_t KeyStore;
	uint32_t TempAdcValue;
}ConfigTypeDef;  
  
typedef struct
{
	uint8_t RxBuffer[DATA_AMOUNT];
	uint8_t TxBuffer[DATA_AMOUNT<<1];
}ComBufferTypeDef;


/**
* @breif 激光雷达每个点的数据结构,需要以压缩方式声明,否则编译器会按word对齐 
*/
__packed typedef struct
{
	uint16_t Distance;
	uint8_t  Confidence;
}LidarPointTypeDef;

__packed typedef struct
{
	uint16_t Temperature;
	uint16_t CurrSpeed;
	uint16_t GivenSpeed;
	LidarPointTypeDef PointData[360];
}LidarDataTypeDef;

extern uint32_t CCD_DataBuffer[PIXEL_1_FPS];
extern float PixOffset;
extern uint16_t Temperature;  
extern ConfigTypeDef SystemConfig;  
extern PackageDataStruct RecPackage;
extern ComBufferTypeDef ComBuffer;
extern LidarDataTypeDef LidarData;
extern uint32_t RecCounter;


void InitSystemConfig(void);


typedef enum
{
    FALSE,
    TRUE,
}BOOL;

//void WriteConfig(void);
//void ReadConfig(void);
//void CloseUsedInterrupt(void);
//void RecoverUsedInterrupt(void);

#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
