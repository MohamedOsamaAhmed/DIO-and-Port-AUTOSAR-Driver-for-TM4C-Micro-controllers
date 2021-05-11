 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Mohamed Osama
 ******************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H


/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define sPORT_DEV_ERROR_DETECT                     (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                     (STD_OFF)

/* Enables/Disables Port_SetPinDirection API */
#define PORT_SET_PIN_DIRECTION_API                STD_ON

/* Enables/Disables Port_SetPinMode API */
#define PORT_SET_PIN_MODE_API                     STD_ON


/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)


/* Pre-compile parameter for number of pins per each port */
#define PORT_NUMBER_OF_PORT_PINS                (43U)                   

/* Number of configured port modes */
#define PORT_CONFIG_MODE_NUM                    (9U)


#define PORT_MIN_PIN_NUM                          (0U)
#define PORT_MAX_PIN_NUM                          (43U) 




/*      Pin Mode Value 
*  You can select one of these values:
*                           PORT_PIN_MODE_DIO		  
*                           PORT_PIN_MODE_ADC		 
*                           PORT_PIN_MODE_CAN		 
*                           PORT_PIN_MODE_GPT		 
*                           PORT_PIN_MODE_WDG		 
*                           PORT_PIN_MODE_FLEXRAY
*                           PORT_PIN_MODE_ICU		 
*                           PORT_PIN_MODE_LIN		 
*                           PORT_PIN_MODE_MEM		 
*                           PORT_PIN_MODE_PWM		 
*                           PORT_PIN_MODE_SPI		 
*                           PORT_PIN_MODE_UART   
*
*/
#define Port_A_Pin_0_MODE           PORT_PIN_MODE_DIO
#define Port_A_Pin_1_MODE           PORT_PIN_MODE_DIO
#define Port_A_Pin_2_MODE           PORT_PIN_MODE_DIO
#define Port_A_Pin_3_MODE           PORT_PIN_MODE_DIO
#define Port_A_Pin_4_MODE           PORT_PIN_MODE_DIO
#define Port_A_Pin_5_MODE           PORT_PIN_MODE_DIO
#define Port_A_Pin_6_MODE           PORT_PIN_MODE_DIO
#define Port_A_Pin_7_MODE           PORT_PIN_MODE_DIO

#define Port_B_Pin_0_MODE           PORT_PIN_MODE_DIO
#define Port_B_Pin_1_MODE           PORT_PIN_MODE_DIO
#define Port_B_Pin_2_MODE           PORT_PIN_MODE_DIO
#define Port_B_Pin_3_MODE           PORT_PIN_MODE_DIO
#define Port_B_Pin_4_MODE           PORT_PIN_MODE_DIO
#define Port_B_Pin_5_MODE           PORT_PIN_MODE_DIO
#define Port_B_Pin_6_MODE           PORT_PIN_MODE_DIO
#define Port_B_Pin_7_MODE           PORT_PIN_MODE_DIO

#define Port_C_Pin_0_MODE           PORT_PIN_MODE_DIO
#define Port_C_Pin_1_MODE           PORT_PIN_MODE_DIO
#define Port_C_Pin_2_MODE           PORT_PIN_MODE_DIO
#define Port_C_Pin_3_MODE           PORT_PIN_MODE_DIO
#define Port_C_Pin_4_MODE           PORT_PIN_MODE_DIO
#define Port_C_Pin_5_MODE           PORT_PIN_MODE_DIO
#define Port_C_Pin_6_MODE           PORT_PIN_MODE_DIO
#define Port_C_Pin_7_MODE           PORT_PIN_MODE_DIO

#define Port_D_Pin_0_MODE           PORT_PIN_MODE_DIO
#define Port_D_Pin_1_MODE           PORT_PIN_MODE_DIO
#define Port_D_Pin_2_MODE           PORT_PIN_MODE_DIO
#define Port_D_Pin_3_MODE           PORT_PIN_MODE_DIO
#define Port_D_Pin_4_MODE           PORT_PIN_MODE_DIO
#define Port_D_Pin_5_MODE           PORT_PIN_MODE_DIO
#define Port_D_Pin_6_MODE           PORT_PIN_MODE_DIO
#define Port_D_Pin_7_MODE           PORT_PIN_MODE_DIO

#define Port_E_Pin_0_MODE           PORT_PIN_MODE_DIO
#define Port_E_Pin_1_MODE           PORT_PIN_MODE_DIO
#define Port_E_Pin_2_MODE           PORT_PIN_MODE_DIO
#define Port_E_Pin_3_MODE           PORT_PIN_MODE_DIO
#define Port_E_Pin_4_MODE           PORT_PIN_MODE_DIO
#define Port_E_Pin_5_MODE           PORT_PIN_MODE_DIO

#define Port_F_Pin_0_MODE           PORT_PIN_MODE_DIO
#define Port_F_Pin_1_MODE           PORT_PIN_MODE_DIO
#define Port_F_Pin_2_MODE           PORT_PIN_MODE_DIO
#define Port_F_Pin_3_MODE           PORT_PIN_MODE_DIO
#define Port_F_Pin_4_MODE           PORT_PIN_MODE_DIO


/* Pin Direction Value, Values: [ PORT_PIN_OUTPUT or PORT_PIN_INPUT ]*/
#define Port_A_Pin_0_DIR           PORT_PIN_OUTPUT
#define Port_A_Pin_1_DIR           PORT_PIN_OUTPUT
#define Port_A_Pin_2_DIR           PORT_PIN_OUTPUT
#define Port_A_Pin_3_DIR           PORT_PIN_OUTPUT
#define Port_A_Pin_4_DIR           PORT_PIN_OUTPUT
#define Port_A_Pin_5_DIR           PORT_PIN_OUTPUT
#define Port_A_Pin_6_DIR           PORT_PIN_OUTPUT
#define Port_A_Pin_7_DIR           PORT_PIN_OUTPUT

#define Port_B_Pin_0_DIR           PORT_PIN_OUTPUT
#define Port_B_Pin_1_DIR           PORT_PIN_OUTPUT
#define Port_B_Pin_2_DIR           PORT_PIN_OUTPUT
#define Port_B_Pin_3_DIR           PORT_PIN_OUTPUT
#define Port_B_Pin_4_DIR           PORT_PIN_OUTPUT
#define Port_B_Pin_5_DIR           PORT_PIN_OUTPUT
#define Port_B_Pin_6_DIR           PORT_PIN_OUTPUT
#define Port_B_Pin_7_DIR           PORT_PIN_OUTPUT

#define Port_C_Pin_0_DIR           PORT_PIN_OUTPUT
#define Port_C_Pin_1_DIR           PORT_PIN_OUTPUT
#define Port_C_Pin_2_DIR           PORT_PIN_OUTPUT
#define Port_C_Pin_3_DIR           PORT_PIN_OUTPUT
#define Port_C_Pin_4_DIR           PORT_PIN_OUTPUT
#define Port_C_Pin_5_DIR           PORT_PIN_OUTPUT
#define Port_C_Pin_6_DIR           PORT_PIN_OUTPUT
#define Port_C_Pin_7_DIR           PORT_PIN_OUTPUT

#define Port_D_Pin_0_DIR           PORT_PIN_OUTPUT
#define Port_D_Pin_1_DIR           PORT_PIN_OUTPUT
#define Port_D_Pin_2_DIR           PORT_PIN_OUTPUT
#define Port_D_Pin_3_DIR           PORT_PIN_OUTPUT
#define Port_D_Pin_4_DIR           PORT_PIN_OUTPUT
#define Port_D_Pin_5_DIR           PORT_PIN_OUTPUT
#define Port_D_Pin_6_DIR           PORT_PIN_OUTPUT
#define Port_D_Pin_7_DIR           PORT_PIN_OUTPUT

#define Port_E_Pin_0_DIR           PORT_PIN_OUTPUT
#define Port_E_Pin_1_DIR           PORT_PIN_OUTPUT
#define Port_E_Pin_2_DIR           PORT_PIN_OUTPUT
#define Port_E_Pin_3_DIR           PORT_PIN_OUTPUT
#define Port_E_Pin_4_DIR           PORT_PIN_OUTPUT
#define Port_E_Pin_5_DIR           PORT_PIN_OUTPUT

#define Port_F_Pin_0_DIR           PORT_PIN_OUTPUT
#define Port_F_Pin_1_DIR           PORT_PIN_OUTPUT /* Led Pin */
#define Port_F_Pin_2_DIR           PORT_PIN_OUTPUT
#define Port_F_Pin_3_DIR           PORT_PIN_OUTPUT
#define Port_F_Pin_4_DIR           PORT_PIN_INPUT  /* Button Pin */



/* Pin Resistor Value, Values:  PORT_PIN_RESISTOR_OFF, PORT_PIN_RESISTOR_PULL_UP or PORT_PIN_RESISTOR_PULL_DOWN */
#define Port_A_Pin_0_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_A_Pin_1_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_A_Pin_2_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_A_Pin_3_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_A_Pin_4_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_A_Pin_5_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_A_Pin_6_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_A_Pin_7_Resistor          PORT_PIN_RESISTOR_OFF

#define Port_B_Pin_0_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_B_Pin_1_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_B_Pin_2_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_B_Pin_3_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_B_Pin_4_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_B_Pin_5_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_B_Pin_6_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_B_Pin_7_Resistor          PORT_PIN_RESISTOR_OFF

#define Port_C_Pin_0_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_C_Pin_1_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_C_Pin_2_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_C_Pin_3_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_C_Pin_4_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_C_Pin_5_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_C_Pin_6_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_C_Pin_7_Resistor          PORT_PIN_RESISTOR_OFF

#define Port_D_Pin_0_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_D_Pin_1_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_D_Pin_2_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_D_Pin_3_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_D_Pin_4_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_D_Pin_5_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_D_Pin_6_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_D_Pin_7_Resistor          PORT_PIN_RESISTOR_OFF

#define Port_E_Pin_0_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_E_Pin_1_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_E_Pin_2_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_E_Pin_3_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_E_Pin_4_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_E_Pin_5_Resistor          PORT_PIN_RESISTOR_OFF

#define Port_F_Pin_0_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_F_Pin_1_Resistor          PORT_PIN_RESISTOR_OFF     /* LED Pin */
#define Port_F_Pin_2_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_F_Pin_3_Resistor          PORT_PIN_RESISTOR_OFF
#define Port_F_Pin_4_Resistor          PORT_PIN_RESISTOR_PULL_UP /* Button Pin */


/* Pin Level Value, Values: [ PORT_PIN_LEVEL_LOW or PORT_PIN_LEVEL_HIGH ] */
#define Port_A_Pin_0_Level          PORT_PIN_LEVEL_LOW
#define Port_A_Pin_1_Level          PORT_PIN_LEVEL_LOW
#define Port_A_Pin_2_Level          PORT_PIN_LEVEL_LOW
#define Port_A_Pin_3_Level          PORT_PIN_LEVEL_LOW
#define Port_A_Pin_4_Level          PORT_PIN_LEVEL_LOW
#define Port_A_Pin_5_Level          PORT_PIN_LEVEL_LOW
#define Port_A_Pin_6_Level          PORT_PIN_LEVEL_LOW
#define Port_A_Pin_7_Level          PORT_PIN_LEVEL_LOW

#define Port_B_Pin_0_Level          PORT_PIN_LEVEL_LOW
#define Port_B_Pin_1_Level          PORT_PIN_LEVEL_LOW
#define Port_B_Pin_2_Level          PORT_PIN_LEVEL_LOW
#define Port_B_Pin_3_Level          PORT_PIN_LEVEL_LOW
#define Port_B_Pin_4_Level          PORT_PIN_LEVEL_LOW
#define Port_B_Pin_5_Level          PORT_PIN_LEVEL_LOW
#define Port_B_Pin_6_Level          PORT_PIN_LEVEL_LOW
#define Port_B_Pin_7_Level          PORT_PIN_LEVEL_LOW

#define Port_C_Pin_0_Level          PORT_PIN_LEVEL_LOW
#define Port_C_Pin_1_Level          PORT_PIN_LEVEL_LOW
#define Port_C_Pin_2_Level          PORT_PIN_LEVEL_LOW
#define Port_C_Pin_3_Level          PORT_PIN_LEVEL_LOW
#define Port_C_Pin_4_Level          PORT_PIN_LEVEL_LOW
#define Port_C_Pin_5_Level          PORT_PIN_LEVEL_LOW
#define Port_C_Pin_6_Level          PORT_PIN_LEVEL_LOW
#define Port_C_Pin_7_Level          PORT_PIN_LEVEL_LOW

#define Port_D_Pin_0_Level          PORT_PIN_LEVEL_LOW
#define Port_D_Pin_1_Level          PORT_PIN_LEVEL_LOW
#define Port_D_Pin_2_Level          PORT_PIN_LEVEL_LOW
#define Port_D_Pin_3_Level          PORT_PIN_LEVEL_LOW
#define Port_D_Pin_4_Level          PORT_PIN_LEVEL_LOW
#define Port_D_Pin_5_Level          PORT_PIN_LEVEL_LOW
#define Port_D_Pin_6_Level          PORT_PIN_LEVEL_LOW
#define Port_D_Pin_7_Level          PORT_PIN_LEVEL_LOW

#define Port_E_Pin_0_Level          PORT_PIN_LEVEL_LOW
#define Port_E_Pin_1_Level          PORT_PIN_LEVEL_LOW
#define Port_E_Pin_2_Level          PORT_PIN_LEVEL_LOW
#define Port_E_Pin_3_Level          PORT_PIN_LEVEL_LOW
#define Port_E_Pin_4_Level          PORT_PIN_LEVEL_LOW
#define Port_E_Pin_5_Level          PORT_PIN_LEVEL_LOW

#define Port_F_Pin_0_Level          PORT_PIN_LEVEL_LOW
#define Port_F_Pin_1_Level          PORT_PIN_LEVEL_LOW  /* LED Pin */
#define Port_F_Pin_2_Level          PORT_PIN_LEVEL_LOW
#define Port_F_Pin_3_Level          PORT_PIN_LEVEL_LOW
#define Port_F_Pin_4_Level          PORT_PIN_LEVEL_LOW  /* Button Pin */




/* Pin change direction during runtime, Values: [STD_ON or STD_OFF] */
#define Port_A_Pin_0_DIR_CHANG          STD_OFF
#define Port_A_Pin_1_DIR_CHANG          STD_OFF
#define Port_A_Pin_2_DIR_CHANG          STD_OFF
#define Port_A_Pin_3_DIR_CHANG          STD_OFF
#define Port_A_Pin_4_DIR_CHANG          STD_OFF
#define Port_A_Pin_5_DIR_CHANG          STD_OFF
#define Port_A_Pin_6_DIR_CHANG          STD_OFF
#define Port_A_Pin_7_DIR_CHANG          STD_OFF

#define Port_B_Pin_0_DIR_CHANG          STD_OFF
#define Port_B_Pin_1_DIR_CHANG          STD_OFF
#define Port_B_Pin_2_DIR_CHANG          STD_OFF
#define Port_B_Pin_3_DIR_CHANG          STD_OFF
#define Port_B_Pin_4_DIR_CHANG          STD_OFF
#define Port_B_Pin_5_DIR_CHANG          STD_OFF
#define Port_B_Pin_6_DIR_CHANG          STD_OFF
#define Port_B_Pin_7_DIR_CHANG          STD_OFF

#define Port_C_Pin_0_DIR_CHANG          STD_OFF
#define Port_C_Pin_1_DIR_CHANG          STD_OFF
#define Port_C_Pin_2_DIR_CHANG          STD_OFF
#define Port_C_Pin_3_DIR_CHANG          STD_OFF
#define Port_C_Pin_4_DIR_CHANG          STD_OFF
#define Port_C_Pin_5_DIR_CHANG          STD_OFF
#define Port_C_Pin_6_DIR_CHANG          STD_OFF
#define Port_C_Pin_7_DIR_CHANG          STD_OFF

#define Port_D_Pin_0_DIR_CHANG          STD_OFF
#define Port_D_Pin_1_DIR_CHANG          STD_OFF
#define Port_D_Pin_2_DIR_CHANG          STD_OFF
#define Port_D_Pin_3_DIR_CHANG          STD_OFF
#define Port_D_Pin_4_DIR_CHANG          STD_OFF
#define Port_D_Pin_5_DIR_CHANG          STD_OFF
#define Port_D_Pin_6_DIR_CHANG          STD_OFF
#define Port_D_Pin_7_DIR_CHANG          STD_OFF

#define Port_E_Pin_0_DIR_CHANG          STD_OFF
#define Port_E_Pin_1_DIR_CHANG          STD_OFF
#define Port_E_Pin_2_DIR_CHANG          STD_OFF
#define Port_E_Pin_3_DIR_CHANG          STD_OFF
#define Port_E_Pin_4_DIR_CHANG          STD_OFF
#define Port_E_Pin_5_DIR_CHANG          STD_OFF

#define Port_F_Pin_0_DIR_CHANG          STD_OFF
#define Port_F_Pin_1_DIR_CHANG          STD_OFF  /* LED Pin */
#define Port_F_Pin_2_DIR_CHANG          STD_OFF
#define Port_F_Pin_3_DIR_CHANG          STD_OFF
#define Port_F_Pin_4_DIR_CHANG          STD_OFF  /* Button Pin */



/* Pin change mode during runtime, Values: [STD_ON or STD_OFF] */
#define Port_A_Pin_0_MODE_CHANG          STD_OFF
#define Port_A_Pin_1_MODE_CHANG          STD_OFF
#define Port_A_Pin_2_MODE_CHANG          STD_OFF
#define Port_A_Pin_3_MODE_CHANG          STD_OFF
#define Port_A_Pin_4_MODE_CHANG          STD_OFF
#define Port_A_Pin_5_MODE_CHANG          STD_OFF
#define Port_A_Pin_6_MODE_CHANG          STD_OFF
#define Port_A_Pin_7_MODE_CHANG          STD_OFF

#define Port_B_Pin_0_MODE_CHANG          STD_OFF
#define Port_B_Pin_1_MODE_CHANG          STD_OFF
#define Port_B_Pin_2_MODE_CHANG          STD_OFF
#define Port_B_Pin_3_MODE_CHANG          STD_OFF
#define Port_B_Pin_4_MODE_CHANG          STD_OFF
#define Port_B_Pin_5_MODE_CHANG          STD_OFF
#define Port_B_Pin_6_MODE_CHANG          STD_OFF
#define Port_B_Pin_7_MODE_CHANG          STD_OFF

#define Port_C_Pin_0_MODE_CHANG          STD_OFF
#define Port_C_Pin_1_MODE_CHANG          STD_OFF
#define Port_C_Pin_2_MODE_CHANG          STD_OFF
#define Port_C_Pin_3_MODE_CHANG          STD_OFF
#define Port_C_Pin_4_MODE_CHANG          STD_OFF
#define Port_C_Pin_5_MODE_CHANG          STD_OFF
#define Port_C_Pin_6_MODE_CHANG          STD_OFF
#define Port_C_Pin_7_MODE_CHANG          STD_OFF

#define Port_D_Pin_0_MODE_CHANG          STD_OFF
#define Port_D_Pin_1_MODE_CHANG          STD_OFF
#define Port_D_Pin_2_MODE_CHANG          STD_OFF
#define Port_D_Pin_3_MODE_CHANG          STD_OFF
#define Port_D_Pin_4_MODE_CHANG          STD_OFF
#define Port_D_Pin_5_MODE_CHANG          STD_OFF
#define Port_D_Pin_6_MODE_CHANG          STD_OFF
#define Port_D_Pin_7_MODE_CHANG          STD_OFF

#define Port_E_Pin_0_MODE_CHANG          STD_OFF
#define Port_E_Pin_1_MODE_CHANG          STD_OFF
#define Port_E_Pin_2_MODE_CHANG          STD_OFF
#define Port_E_Pin_3_MODE_CHANG          STD_OFF
#define Port_E_Pin_4_MODE_CHANG          STD_OFF
#define Port_E_Pin_5_MODE_CHANG          STD_OFF

#define Port_F_Pin_0_MODE_CHANG          STD_OFF
#define Port_F_Pin_1_MODE_CHANG          STD_OFF  /* LED Pin */
#define Port_F_Pin_2_MODE_CHANG          STD_OFF
#define Port_F_Pin_3_MODE_CHANG          STD_OFF
#define Port_F_Pin_4_MODE_CHANG          STD_OFF  /* Button Pin */


#endif