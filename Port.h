 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Mohamed Osama
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

/* Id for the company in the AUTOSAR
 * for example Mohamed Osama's ID = 1000 :) */
#define PORT_VENDOR_ID    (1000U)

/* Port Module Id */
#define PORT_MODULE_ID    (124U)

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */

#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)


/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Port Pre-Compile Configuration Header file */
#include "Port_Cfg.h"



/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif



/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

#define PORT_PIN_INPUT                     INPUT
#define PORT_PIN_OUTPUT                    OUTPUT

/* Macros for Resistor Status*/

#define PORT_PIN_RESISTOR_OFF          OFF
#define PORT_PIN_RESISTOR_PULL_UP      PULL_UP
#define PORT_PIN_RESISTOR_PULL_DOWN    PULL_DOWN

/*  Vaild values for any pin at any port   */   
#define PORT_PIN_LEVEL_HIGH                   (STD_HIGH)
#define PORT_PIN_LEVEL_LOW                    (STD_LOW)


#include "Common_Macros.h"


/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for PORT Init */
#define PORT_INIT_SID                           (uint8)0x00

/* Service ID for PORT Set Pin Direction */
#define PORT_SET_PIN_DIRECTION_SID              (uint8)0x01

/* Service ID for Refresh Port Direction */
#define PORT_REFRESH_PORT_DIRECTION_SID         (uint8)0x02

/* Service ID for Port Get Version Info */
#define PORT_GET_VERSION_INFO_SID                 (uint8)0x03

/* Service ID for Port Set Pin Mode */
#define PORT_SET_PIN_MODE_SID                     (uint8)0x04



/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN                  (uint8)0x0A

/* DET code to report Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE     (uint8)0x0B

/* DET code to report API Port_Init service called with wrong parameter */
#define PORT_E_PARAM_CONFIG               (uint8)0x0C

/* DET code to report API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_PARAM_INVALID_MODE         (uint8)0x0D
#define PORT_E_MODE_UNCHANGEABLE          (uint8)0x0E

/* API service called without module initialization */
#define PORT_E_UNINIT                     (uint8)0x0F

/* APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER              (uint8)0x10

/*******************************************************************************
 *                              Module Definitions                             *
 *******************************************************************************/




/* GPIO Registers base addresses */
#define GPIO_PORTA_BASE_ADDRESS           0x40004000
#define GPIO_PORTB_BASE_ADDRESS           0x40005000
#define GPIO_PORTC_BASE_ADDRESS           0x40006000
#define GPIO_PORTD_BASE_ADDRESS           0x40007000
#define GPIO_PORTE_BASE_ADDRESS           0x40024000
#define GPIO_PORTF_BASE_ADDRESS           0x40025000

/* GPIO Registers offset addresses */
#define PORT_DATA_REG_OFFSET              0x3FC
#define PORT_DIR_REG_OFFSET               0x400
#define PORT_ALT_FUNC_REG_OFFSET          0x420
#define PORT_PULL_UP_REG_OFFSET           0x510
#define PORT_PULL_DOWN_REG_OFFSET         0x514
#define PORT_DIGITAL_ENABLE_REG_OFFSET    0x51C
#define PORT_LOCK_REG_OFFSET              0x520
#define PORT_COMMIT_REG_OFFSET            0x524
#define PORT_ANALOG_MODE_SEL_REG_OFFSET   0x528
#define PORT_CTL_REG_OFFSET               0x52C





/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/




/* Ports IDs Number */
#define Port_A_Num             (Port_IDType)0
#define Port_B_Num             (Port_IDType)1
#define Port_C_Num             (Port_IDType)2
#define Port_D_Num             (Port_IDType)3
#define Port_E_Num             (Port_IDType)4
#define Port_F_Num             (Port_IDType)5



/* Port Pin ID Handles */
#define Port_A_Pin_0    (Port_PinType)0
#define Port_A_Pin_1    (Port_PinType)1
#define Port_A_Pin_2    (Port_PinType)2
#define Port_A_Pin_3    (Port_PinType)3
#define Port_A_Pin_4    (Port_PinType)4
#define Port_A_Pin_5    (Port_PinType)5
#define Port_A_Pin_6    (Port_PinType)6
#define Port_A_Pin_7    (Port_PinType)7

#define Port_B_Pin_0    (Port_PinType)0
#define Port_B_Pin_1    (Port_PinType)1
#define Port_B_Pin_2    (Port_PinType)2
#define Port_B_Pin_3    (Port_PinType)3
#define Port_B_Pin_4    (Port_PinType)4
#define Port_B_Pin_5    (Port_PinType)5
#define Port_B_Pin_6    (Port_PinType)6
#define Port_B_Pin_7    (Port_PinType)7

#define Port_C_Pin_0    (Port_PinType)0
#define Port_C_Pin_1    (Port_PinType)1
#define Port_C_Pin_2    (Port_PinType)2
#define Port_C_Pin_3    (Port_PinType)3
#define Port_C_Pin_4    (Port_PinType)4
#define Port_C_Pin_5    (Port_PinType)5
#define Port_C_Pin_6    (Port_PinType)6
#define Port_C_Pin_7    (Port_PinType)7

#define Port_D_Pin_0    (Port_PinType)0
#define Port_D_Pin_1    (Port_PinType)1
#define Port_D_Pin_2    (Port_PinType)2
#define Port_D_Pin_3    (Port_PinType)3
#define Port_D_Pin_4    (Port_PinType)4
#define Port_D_Pin_5    (Port_PinType)5
#define Port_D_Pin_6    (Port_PinType)6
#define Port_D_Pin_7    (Port_PinType)7

#define Port_E_Pin_0    (Port_PinType)0
#define Port_E_Pin_1    (Port_PinType)1
#define Port_E_Pin_2    (Port_PinType)2
#define Port_E_Pin_3    (Port_PinType)3
#define Port_E_Pin_4    (Port_PinType)4
#define Port_E_Pin_5    (Port_PinType)5

#define Port_F_Pin_0    (Port_PinType)0
#define Port_F_Pin_1    (Port_PinType)1
#define Port_F_Pin_2    (Port_PinType)2
#define Port_F_Pin_3    (Port_PinType)3
#define Port_F_Pin_4    (Port_PinType)4


/* Port Pin MODE values  */
#define PORT_PIN_MODE_DIO		        (Port_PinModeType)0
#define PORT_PIN_MODE_ADC		        (Port_PinModeType)1
#define PORT_PIN_MODE_CAN		        (Port_PinModeType)2
#define PORT_PIN_MODE_GPT		        (Port_PinModeType)3
#define PORT_PIN_MODE_WDG		        (Port_PinModeType)4
#define PORT_PIN_MODE_SSI	          (Port_PinModeType)5
#define PORT_PIN_MODE_I2C		        (Port_PinModeType)6
#define PORT_PIN_MODE_PWM		        (Port_PinModeType)7
#define PORT_PIN_MODE_UART          (Port_PinModeType)8

/* Port pin type, pins number is MCU specific. */

typedef uint8 Port_PinType;


/* Port pin mode type, pins number is MCU specific. */

typedef uint8 Port_PinModeType;



/* Type definition for Port_ID used by the Port APIs */
typedef uint8 Port_IDType;


/* Type definition for pin levels*/
typedef uint8 Port_PinLevel;
/* Description: Enum to hold PIN direction */
typedef enum
{
    INPUT,OUTPUT
}Port_PinDirectionType;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;


/* Description: Structure to configure each individual PIN:
 *	1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *	2. the number of the pin in the PORT.
 *      3. the direction of pin --> INPUT or OUTPUT
 *      4. the internal resistor --> Disable, Pull up or Pull down
 */
typedef struct 
{
    Port_IDType Port_Num; /*Port Number*/
    Port_PinType Pin_Num; /*Pin Number*/
    Port_PinModeType Pin_Mode; /*Pin mode DIO, ADC, UART ... etc*/
    Port_PinDirectionType Pin_Direction; /*Pin Direction Input or Output */
    Port_InternalResistor Pin_Resistor; /* Pin Resistor Status OFF, PULL_UP or PULL_DOWN*/
    Port_PinLevel Pin_InitialLevel; /* Pin Initial Value STD_HIGH or STD_LOW*/
	  uint8 Pin_Dir_Change; /* Pin direction changeable during runtime? */
	  uint8 Pin_Mode_Change; /* Pin mode changeable during runtime?.*/
}Port_Pin_ConfigType;

 /*Type of the external data structure containing the initialization data for this module*/
typedef struct {
	 Port_Pin_ConfigType Pin_config[PORT_MAX_PIN_NUM];

 }Port_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: Port_SetPinMode
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Pin - Port Pin ID number
* Parameters (in): Mode - New Port Pin mode to be set on port pin
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin mode
************************************************************************************/
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode);



/************************************************************************************
* Service Name: Port_Init
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr - Pointer to configuration set
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the Port Driver module.
************************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr);



/************************************************************************************
* Service Name: Port_SetPinDirection
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number
* Parameters (in): Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin direction
************************************************************************************/
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);


/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Refreshes port direction.
************************************************************************************/
void Port_RefreshPortDirection(void);


extern const Port_ConfigType Port_Configuration;

/* Function for Port Get Version Info API */
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif


#endif /* PORT_H */
