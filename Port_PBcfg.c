 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Mohamed Osama
 ******************************************************************************/

#include "Port.h"

/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)


/* AUTOSAR Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif


/* Software Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif


/* PB structure used with Port_Init API */
const Port_ConfigType Port_Configuration = {

		Port_A_Num,	Port_A_Pin_0, Port_A_Pin_0_MODE, Port_A_Pin_0_DIR, Port_A_Pin_0_Resistor, Port_A_Pin_0_Level, Port_A_Pin_0_DIR_CHANG, Port_A_Pin_0_MODE_CHANG,
		Port_A_Num,	Port_A_Pin_1, Port_A_Pin_1_MODE, Port_A_Pin_1_DIR, Port_A_Pin_1_Resistor, Port_A_Pin_1_Level, Port_A_Pin_1_DIR_CHANG, Port_A_Pin_1_MODE_CHANG,
		Port_A_Num,	Port_A_Pin_2, Port_A_Pin_2_MODE, Port_A_Pin_2_DIR, Port_A_Pin_2_Resistor, Port_A_Pin_2_Level, Port_A_Pin_2_DIR_CHANG, Port_A_Pin_2_MODE_CHANG,
		Port_A_Num,	Port_A_Pin_3, Port_A_Pin_3_MODE, Port_A_Pin_3_DIR, Port_A_Pin_3_Resistor, Port_A_Pin_3_Level, Port_A_Pin_3_DIR_CHANG, Port_A_Pin_3_MODE_CHANG,
		Port_A_Num,	Port_A_Pin_4, Port_A_Pin_4_MODE, Port_A_Pin_4_DIR, Port_A_Pin_4_Resistor, Port_A_Pin_4_Level, Port_A_Pin_4_DIR_CHANG, Port_A_Pin_4_MODE_CHANG,
		Port_A_Num,	Port_A_Pin_5, Port_A_Pin_5_MODE, Port_A_Pin_5_DIR, Port_A_Pin_5_Resistor, Port_A_Pin_5_Level, Port_A_Pin_5_DIR_CHANG, Port_A_Pin_5_MODE_CHANG,
		Port_A_Num,	Port_A_Pin_6, Port_A_Pin_6_MODE, Port_A_Pin_6_DIR, Port_A_Pin_6_Resistor, Port_A_Pin_6_Level, Port_A_Pin_6_DIR_CHANG, Port_A_Pin_6_MODE_CHANG,
		Port_A_Num,	Port_A_Pin_7, Port_A_Pin_7_MODE, Port_A_Pin_7_DIR, Port_A_Pin_7_Resistor, Port_A_Pin_7_Level, Port_A_Pin_7_DIR_CHANG, Port_A_Pin_7_MODE_CHANG,
	
		Port_B_Num,	Port_B_Pin_0, Port_B_Pin_0_MODE, Port_B_Pin_0_DIR, Port_B_Pin_0_Resistor, Port_B_Pin_0_Level, Port_B_Pin_0_DIR_CHANG, Port_B_Pin_0_MODE_CHANG,
		Port_B_Num,	Port_B_Pin_1, Port_B_Pin_1_MODE, Port_B_Pin_1_DIR, Port_B_Pin_1_Resistor, Port_B_Pin_1_Level, Port_B_Pin_1_DIR_CHANG, Port_B_Pin_1_MODE_CHANG,
		Port_B_Num,	Port_B_Pin_2, Port_B_Pin_2_MODE, Port_B_Pin_2_DIR, Port_B_Pin_2_Resistor, Port_B_Pin_2_Level, Port_B_Pin_2_DIR_CHANG, Port_B_Pin_2_MODE_CHANG,
		Port_B_Num,	Port_B_Pin_3, Port_B_Pin_3_MODE, Port_B_Pin_3_DIR, Port_B_Pin_3_Resistor, Port_B_Pin_3_Level, Port_B_Pin_3_DIR_CHANG, Port_B_Pin_3_MODE_CHANG,
		Port_B_Num,	Port_B_Pin_4, Port_B_Pin_4_MODE, Port_B_Pin_4_DIR, Port_B_Pin_4_Resistor, Port_B_Pin_4_Level, Port_B_Pin_4_DIR_CHANG, Port_B_Pin_4_MODE_CHANG,
		Port_B_Num,	Port_B_Pin_5, Port_B_Pin_5_MODE, Port_B_Pin_5_DIR, Port_B_Pin_5_Resistor, Port_B_Pin_5_Level, Port_B_Pin_5_DIR_CHANG, Port_B_Pin_5_MODE_CHANG,
		Port_B_Num,	Port_B_Pin_6, Port_B_Pin_6_MODE, Port_B_Pin_6_DIR, Port_B_Pin_6_Resistor, Port_B_Pin_6_Level, Port_B_Pin_6_DIR_CHANG, Port_B_Pin_6_MODE_CHANG,
		Port_B_Num,	Port_B_Pin_7, Port_B_Pin_7_MODE, Port_B_Pin_7_DIR, Port_B_Pin_7_Resistor, Port_B_Pin_7_Level, Port_B_Pin_7_DIR_CHANG, Port_B_Pin_7_MODE_CHANG,
	
		Port_C_Num,	Port_C_Pin_0, Port_C_Pin_0_MODE, Port_C_Pin_0_DIR, Port_C_Pin_0_Resistor, Port_C_Pin_0_Level, Port_C_Pin_0_DIR_CHANG, Port_C_Pin_0_MODE_CHANG,
		Port_C_Num,	Port_C_Pin_1, Port_C_Pin_1_MODE, Port_C_Pin_1_DIR, Port_C_Pin_1_Resistor, Port_C_Pin_1_Level, Port_C_Pin_1_DIR_CHANG, Port_C_Pin_1_MODE_CHANG,
		Port_C_Num,	Port_C_Pin_2, Port_C_Pin_2_MODE, Port_C_Pin_2_DIR, Port_C_Pin_2_Resistor, Port_C_Pin_2_Level, Port_C_Pin_2_DIR_CHANG, Port_C_Pin_2_MODE_CHANG,
		Port_C_Num,	Port_C_Pin_3, Port_C_Pin_3_MODE, Port_C_Pin_3_DIR, Port_C_Pin_3_Resistor, Port_C_Pin_3_Level, Port_C_Pin_3_DIR_CHANG, Port_C_Pin_3_MODE_CHANG,
		Port_C_Num,	Port_C_Pin_4, Port_C_Pin_4_MODE, Port_C_Pin_4_DIR, Port_C_Pin_4_Resistor, Port_C_Pin_4_Level, Port_C_Pin_4_DIR_CHANG, Port_C_Pin_4_MODE_CHANG,
		Port_C_Num,	Port_C_Pin_5, Port_C_Pin_5_MODE, Port_C_Pin_5_DIR, Port_C_Pin_5_Resistor, Port_C_Pin_5_Level, Port_C_Pin_5_DIR_CHANG, Port_C_Pin_5_MODE_CHANG,
		Port_C_Num,	Port_C_Pin_6, Port_C_Pin_6_MODE, Port_C_Pin_6_DIR, Port_C_Pin_6_Resistor, Port_C_Pin_6_Level, Port_C_Pin_6_DIR_CHANG, Port_C_Pin_6_MODE_CHANG,
		Port_C_Num,	Port_C_Pin_7, Port_C_Pin_7_MODE, Port_C_Pin_7_DIR, Port_C_Pin_7_Resistor, Port_C_Pin_7_Level, Port_C_Pin_7_DIR_CHANG, Port_C_Pin_7_MODE_CHANG,
	
		Port_D_Num,	Port_D_Pin_0, Port_D_Pin_0_MODE, Port_D_Pin_0_DIR, Port_D_Pin_0_Resistor, Port_D_Pin_0_Level, Port_D_Pin_0_DIR_CHANG, Port_D_Pin_0_MODE_CHANG,
		Port_D_Num,	Port_D_Pin_1, Port_D_Pin_1_MODE, Port_D_Pin_1_DIR, Port_D_Pin_1_Resistor, Port_D_Pin_1_Level, Port_D_Pin_1_DIR_CHANG, Port_D_Pin_1_MODE_CHANG,
		Port_D_Num,	Port_D_Pin_2, Port_D_Pin_2_MODE, Port_D_Pin_2_DIR, Port_D_Pin_2_Resistor, Port_D_Pin_2_Level, Port_D_Pin_2_DIR_CHANG, Port_D_Pin_2_MODE_CHANG,
		Port_D_Num,	Port_D_Pin_3, Port_D_Pin_3_MODE, Port_D_Pin_3_DIR, Port_D_Pin_3_Resistor, Port_D_Pin_3_Level, Port_D_Pin_3_DIR_CHANG, Port_D_Pin_3_MODE_CHANG,
		Port_D_Num,	Port_D_Pin_4, Port_D_Pin_4_MODE, Port_D_Pin_4_DIR, Port_D_Pin_4_Resistor, Port_D_Pin_4_Level, Port_D_Pin_4_DIR_CHANG, Port_D_Pin_4_MODE_CHANG,
		Port_D_Num,	Port_D_Pin_5, Port_D_Pin_5_MODE, Port_D_Pin_5_DIR, Port_D_Pin_5_Resistor, Port_D_Pin_5_Level, Port_D_Pin_5_DIR_CHANG, Port_D_Pin_5_MODE_CHANG,
		Port_D_Num,	Port_D_Pin_6, Port_D_Pin_6_MODE, Port_D_Pin_6_DIR, Port_D_Pin_6_Resistor, Port_D_Pin_6_Level, Port_D_Pin_6_DIR_CHANG, Port_D_Pin_6_MODE_CHANG,
		Port_D_Num,	Port_D_Pin_7, Port_D_Pin_7_MODE, Port_D_Pin_7_DIR, Port_D_Pin_7_Resistor, Port_D_Pin_7_Level, Port_D_Pin_7_DIR_CHANG, Port_D_Pin_7_MODE_CHANG,
		
		Port_E_Num,	Port_E_Pin_0, Port_E_Pin_0_MODE, Port_E_Pin_0_DIR, Port_E_Pin_0_Resistor, Port_E_Pin_0_Level, Port_E_Pin_0_DIR_CHANG, Port_E_Pin_0_MODE_CHANG,
		Port_E_Num,	Port_E_Pin_1, Port_E_Pin_1_MODE, Port_E_Pin_1_DIR, Port_E_Pin_1_Resistor, Port_E_Pin_1_Level, Port_E_Pin_1_DIR_CHANG, Port_E_Pin_1_MODE_CHANG,
		Port_E_Num,	Port_E_Pin_2, Port_E_Pin_2_MODE, Port_E_Pin_2_DIR, Port_E_Pin_2_Resistor, Port_E_Pin_2_Level, Port_E_Pin_2_DIR_CHANG, Port_E_Pin_2_MODE_CHANG,
		Port_E_Num,	Port_E_Pin_3, Port_E_Pin_3_MODE, Port_E_Pin_3_DIR, Port_E_Pin_3_Resistor, Port_E_Pin_3_Level, Port_E_Pin_3_DIR_CHANG, Port_E_Pin_3_MODE_CHANG,
		Port_E_Num,	Port_E_Pin_4, Port_E_Pin_4_MODE, Port_E_Pin_4_DIR, Port_E_Pin_4_Resistor, Port_E_Pin_4_Level, Port_E_Pin_4_DIR_CHANG, Port_E_Pin_4_MODE_CHANG,
		Port_E_Num,	Port_E_Pin_5, Port_E_Pin_5_MODE, Port_E_Pin_5_DIR, Port_E_Pin_5_Resistor, Port_E_Pin_5_Level, Port_E_Pin_5_DIR_CHANG, Port_E_Pin_5_MODE_CHANG,

		Port_F_Num,	Port_F_Pin_0, Port_F_Pin_0_MODE, Port_F_Pin_0_DIR, Port_F_Pin_0_Resistor, Port_F_Pin_0_Level, Port_F_Pin_0_DIR_CHANG, Port_F_Pin_0_MODE_CHANG,
		Port_F_Num,	Port_F_Pin_1, Port_F_Pin_1_MODE, Port_F_Pin_1_DIR, Port_F_Pin_1_Resistor, Port_F_Pin_1_Level, Port_F_Pin_1_DIR_CHANG, Port_F_Pin_1_MODE_CHANG,
		Port_F_Num,	Port_F_Pin_2, Port_F_Pin_2_MODE, Port_F_Pin_2_DIR, Port_F_Pin_2_Resistor, Port_F_Pin_2_Level, Port_F_Pin_2_DIR_CHANG, Port_F_Pin_2_MODE_CHANG,
		Port_F_Num,	Port_F_Pin_3, Port_F_Pin_3_MODE, Port_F_Pin_3_DIR, Port_F_Pin_3_Resistor, Port_F_Pin_3_Level, Port_F_Pin_3_DIR_CHANG, Port_F_Pin_3_MODE_CHANG,
		Port_F_Num,	Port_F_Pin_4, Port_F_Pin_4_MODE, Port_F_Pin_4_DIR, Port_F_Pin_4_Resistor, Port_F_Pin_4_Level, Port_F_Pin_4_DIR_CHANG, Port_F_Pin_4_MODE_CHANG
};

/* PB structure used with Port_Init API for Modes */
const Port_ConfiguredModesType Port_ConfigurationModes = {

	Port_A_Pin_0_GPIO_Type,Port_A_Pin_0_Port_DigitalEnableType,Port_A_Pin_0_Port_AnalogEnableType, Port_A_Pin_0_OpenDrainSelectType,Port_A_Pin_0_Port_SlewRateSelectType,
	Port_A_Pin_1_GPIO_Type,Port_A_Pin_1_Port_DigitalEnableType,Port_A_Pin_1_Port_AnalogEnableType, Port_A_Pin_1_OpenDrainSelectType,Port_A_Pin_1_Port_SlewRateSelectType,
	Port_A_Pin_2_GPIO_Type,Port_A_Pin_2_Port_DigitalEnableType,Port_A_Pin_2_Port_AnalogEnableType, Port_A_Pin_2_OpenDrainSelectType,Port_A_Pin_2_Port_SlewRateSelectType,
	Port_A_Pin_3_GPIO_Type,Port_A_Pin_3_Port_DigitalEnableType,Port_A_Pin_3_Port_AnalogEnableType, Port_A_Pin_3_OpenDrainSelectType,Port_A_Pin_3_Port_SlewRateSelectType,
	Port_A_Pin_4_GPIO_Type,Port_A_Pin_4_Port_DigitalEnableType,Port_A_Pin_4_Port_AnalogEnableType, Port_A_Pin_4_OpenDrainSelectType,Port_A_Pin_4_Port_SlewRateSelectType,
	Port_A_Pin_5_GPIO_Type,Port_A_Pin_5_Port_DigitalEnableType,Port_A_Pin_5_Port_AnalogEnableType, Port_A_Pin_5_OpenDrainSelectType,Port_A_Pin_5_Port_SlewRateSelectType,
	Port_A_Pin_6_GPIO_Type,Port_A_Pin_6_Port_DigitalEnableType,Port_A_Pin_6_Port_AnalogEnableType, Port_A_Pin_6_OpenDrainSelectType,Port_A_Pin_6_Port_SlewRateSelectType,
	Port_A_Pin_7_GPIO_Type,Port_A_Pin_7_Port_DigitalEnableType,Port_A_Pin_7_Port_AnalogEnableType, Port_A_Pin_7_OpenDrainSelectType,Port_A_Pin_7_Port_SlewRateSelectType,
	
	Port_B_Pin_0_GPIO_Type,Port_B_Pin_0_Port_DigitalEnableType,Port_B_Pin_0_Port_AnalogEnableType, Port_B_Pin_0_OpenDrainSelectType,Port_B_Pin_0_Port_SlewRateSelectType,
	Port_B_Pin_1_GPIO_Type,Port_B_Pin_1_Port_DigitalEnableType,Port_B_Pin_1_Port_AnalogEnableType, Port_B_Pin_1_OpenDrainSelectType,Port_B_Pin_1_Port_SlewRateSelectType,
	Port_B_Pin_2_GPIO_Type,Port_B_Pin_2_Port_DigitalEnableType,Port_B_Pin_2_Port_AnalogEnableType, Port_B_Pin_2_OpenDrainSelectType,Port_B_Pin_2_Port_SlewRateSelectType,
	Port_B_Pin_3_GPIO_Type,Port_B_Pin_3_Port_DigitalEnableType,Port_B_Pin_3_Port_AnalogEnableType, Port_B_Pin_3_OpenDrainSelectType,Port_B_Pin_3_Port_SlewRateSelectType,
	Port_B_Pin_4_GPIO_Type,Port_B_Pin_4_Port_DigitalEnableType,Port_B_Pin_4_Port_AnalogEnableType, Port_B_Pin_4_OpenDrainSelectType,Port_B_Pin_4_Port_SlewRateSelectType,
	Port_B_Pin_5_GPIO_Type,Port_B_Pin_5_Port_DigitalEnableType,Port_B_Pin_5_Port_AnalogEnableType, Port_B_Pin_5_OpenDrainSelectType,Port_B_Pin_5_Port_SlewRateSelectType,
	Port_B_Pin_6_GPIO_Type,Port_B_Pin_6_Port_DigitalEnableType,Port_B_Pin_6_Port_AnalogEnableType, Port_B_Pin_6_OpenDrainSelectType,Port_B_Pin_6_Port_SlewRateSelectType,
	Port_B_Pin_7_GPIO_Type,Port_B_Pin_7_Port_DigitalEnableType,Port_B_Pin_7_Port_AnalogEnableType, Port_B_Pin_7_OpenDrainSelectType,Port_B_Pin_7_Port_SlewRateSelectType,
	
	Port_C_Pin_0_GPIO_Type,Port_C_Pin_0_Port_DigitalEnableType,Port_C_Pin_0_Port_AnalogEnableType, Port_C_Pin_0_OpenDrainSelectType,Port_C_Pin_0_Port_SlewRateSelectType,
	Port_C_Pin_1_GPIO_Type,Port_C_Pin_1_Port_DigitalEnableType,Port_C_Pin_1_Port_AnalogEnableType, Port_C_Pin_1_OpenDrainSelectType,Port_C_Pin_1_Port_SlewRateSelectType,
	Port_C_Pin_2_GPIO_Type,Port_C_Pin_2_Port_DigitalEnableType,Port_C_Pin_2_Port_AnalogEnableType, Port_C_Pin_2_OpenDrainSelectType,Port_C_Pin_2_Port_SlewRateSelectType,
	Port_C_Pin_3_GPIO_Type,Port_C_Pin_3_Port_DigitalEnableType,Port_C_Pin_3_Port_AnalogEnableType, Port_C_Pin_3_OpenDrainSelectType,Port_C_Pin_3_Port_SlewRateSelectType,
	Port_C_Pin_4_GPIO_Type,Port_C_Pin_4_Port_DigitalEnableType,Port_C_Pin_4_Port_AnalogEnableType, Port_C_Pin_4_OpenDrainSelectType,Port_C_Pin_4_Port_SlewRateSelectType,
	Port_C_Pin_5_GPIO_Type,Port_C_Pin_5_Port_DigitalEnableType,Port_C_Pin_5_Port_AnalogEnableType, Port_C_Pin_5_OpenDrainSelectType,Port_C_Pin_5_Port_SlewRateSelectType,
	Port_C_Pin_6_GPIO_Type,Port_C_Pin_6_Port_DigitalEnableType,Port_C_Pin_6_Port_AnalogEnableType, Port_C_Pin_6_OpenDrainSelectType,Port_C_Pin_6_Port_SlewRateSelectType,
	Port_C_Pin_7_GPIO_Type,Port_C_Pin_7_Port_DigitalEnableType,Port_C_Pin_7_Port_AnalogEnableType, Port_C_Pin_7_OpenDrainSelectType,Port_C_Pin_7_Port_SlewRateSelectType,

	Port_D_Pin_0_GPIO_Type,Port_D_Pin_0_Port_DigitalEnableType,Port_D_Pin_0_Port_AnalogEnableType, Port_D_Pin_0_OpenDrainSelectType,Port_D_Pin_0_Port_SlewRateSelectType,
	Port_D_Pin_1_GPIO_Type,Port_D_Pin_1_Port_DigitalEnableType,Port_D_Pin_1_Port_AnalogEnableType, Port_D_Pin_1_OpenDrainSelectType,Port_D_Pin_1_Port_SlewRateSelectType,
	Port_D_Pin_2_GPIO_Type,Port_D_Pin_2_Port_DigitalEnableType,Port_D_Pin_2_Port_AnalogEnableType, Port_D_Pin_2_OpenDrainSelectType,Port_D_Pin_2_Port_SlewRateSelectType,
	Port_D_Pin_3_GPIO_Type,Port_D_Pin_3_Port_DigitalEnableType,Port_D_Pin_3_Port_AnalogEnableType, Port_D_Pin_3_OpenDrainSelectType,Port_D_Pin_3_Port_SlewRateSelectType,
	Port_D_Pin_4_GPIO_Type,Port_D_Pin_4_Port_DigitalEnableType,Port_D_Pin_4_Port_AnalogEnableType, Port_D_Pin_4_OpenDrainSelectType,Port_D_Pin_4_Port_SlewRateSelectType,
	Port_D_Pin_5_GPIO_Type,Port_D_Pin_5_Port_DigitalEnableType,Port_D_Pin_5_Port_AnalogEnableType, Port_D_Pin_5_OpenDrainSelectType,Port_D_Pin_5_Port_SlewRateSelectType,
	Port_D_Pin_6_GPIO_Type,Port_D_Pin_6_Port_DigitalEnableType,Port_D_Pin_6_Port_AnalogEnableType, Port_D_Pin_6_OpenDrainSelectType,Port_D_Pin_6_Port_SlewRateSelectType,
	Port_D_Pin_7_GPIO_Type,Port_D_Pin_7_Port_DigitalEnableType,Port_D_Pin_7_Port_AnalogEnableType, Port_D_Pin_7_OpenDrainSelectType,Port_D_Pin_7_Port_SlewRateSelectType,
	
	Port_E_Pin_0_GPIO_Type,Port_E_Pin_0_Port_DigitalEnableType,Port_E_Pin_0_Port_AnalogEnableType, Port_E_Pin_0_OpenDrainSelectType,Port_E_Pin_0_Port_SlewRateSelectType,
	Port_E_Pin_1_GPIO_Type,Port_E_Pin_1_Port_DigitalEnableType,Port_E_Pin_1_Port_AnalogEnableType, Port_E_Pin_1_OpenDrainSelectType,Port_E_Pin_1_Port_SlewRateSelectType,
	Port_E_Pin_2_GPIO_Type,Port_E_Pin_2_Port_DigitalEnableType,Port_E_Pin_2_Port_AnalogEnableType, Port_E_Pin_2_OpenDrainSelectType,Port_E_Pin_2_Port_SlewRateSelectType,
	Port_E_Pin_3_GPIO_Type,Port_E_Pin_3_Port_DigitalEnableType,Port_E_Pin_3_Port_AnalogEnableType, Port_E_Pin_3_OpenDrainSelectType,Port_E_Pin_3_Port_SlewRateSelectType,
	Port_E_Pin_4_GPIO_Type,Port_E_Pin_4_Port_DigitalEnableType,Port_E_Pin_4_Port_AnalogEnableType, Port_E_Pin_4_OpenDrainSelectType,Port_E_Pin_4_Port_SlewRateSelectType,
	Port_E_Pin_5_GPIO_Type,Port_E_Pin_5_Port_DigitalEnableType,Port_E_Pin_5_Port_AnalogEnableType, Port_E_Pin_5_OpenDrainSelectType,Port_E_Pin_5_Port_SlewRateSelectType,
	
	Port_F_Pin_0_GPIO_Type,Port_F_Pin_0_Port_DigitalEnableType,Port_F_Pin_0_Port_AnalogEnableType, Port_F_Pin_0_OpenDrainSelectType,Port_F_Pin_0_Port_SlewRateSelectType,
	Port_F_Pin_1_GPIO_Type,Port_F_Pin_1_Port_DigitalEnableType,Port_F_Pin_1_Port_AnalogEnableType, Port_F_Pin_1_OpenDrainSelectType,Port_F_Pin_1_Port_SlewRateSelectType,
	Port_F_Pin_2_GPIO_Type,Port_F_Pin_2_Port_DigitalEnableType,Port_F_Pin_2_Port_AnalogEnableType, Port_F_Pin_2_OpenDrainSelectType,Port_F_Pin_2_Port_SlewRateSelectType,
	Port_F_Pin_3_GPIO_Type,Port_F_Pin_3_Port_DigitalEnableType,Port_F_Pin_3_Port_AnalogEnableType, Port_F_Pin_3_OpenDrainSelectType,Port_F_Pin_3_Port_SlewRateSelectType,
	Port_F_Pin_4_GPIO_Type,Port_F_Pin_4_Port_DigitalEnableType,Port_F_Pin_4_Port_AnalogEnableType, Port_F_Pin_4_OpenDrainSelectType,Port_F_Pin_4_Port_SlewRateSelectType


};
