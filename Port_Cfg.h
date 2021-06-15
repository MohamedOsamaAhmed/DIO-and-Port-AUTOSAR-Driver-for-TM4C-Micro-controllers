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
#define PORT_CONFIG_MODE_NUM                    (21U)


#define PORT_MIN_PIN_NUM                          (0U)
#define PORT_MAX_PIN_NUM                          (43U) 


/* Modes Defines */

/*      Pin Mode Value 
*  You can select one of these values:
*       PORT_PIN_MODE_DIO		
*       PORT_PIN_MODE_ADC		
*       PORT_PIN_MODE_COMP	
*       PORT_PIN_MODE_CAN		
*       PORT_PIN_MODE_I2C		
*       PORT_PIN_MODE_USB		
*       PORT_PIN_MODE_M0PWMx
*       PORT_PIN_MODE_M1PWMx
*       PORT_PIN_MODE_TxCCPx
*       PORT_PIN_MODE_SSI1	
*       PORT_PIN_MODE_SSI2	
*       PORT_PIN_MODE_SSI3	
*       PORT_PIN_MODE_UART  
*       PORT_PIN_MODE_U1CTS 
*       PORT_PIN_MODE_U1RTS 
*       PORT_PIN_MODE_U1Rx  
*       PORT_PIN_MODE_U1Tx  
*       PORT_PIN_MODE_CORE	
*       PORT_PIN_MODE_NMI		
*       PORT_PIN_MODE_QEI		
*       PORT_PIN_MODE_JTAG	
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



/* Possible values of the GPIO_Type {PORT_GPIO_DISABLED, PORT_GPIO_ENABLED} */
#define Port_A_Pin_0_GPIO_Type          PORT_GPIO_ENABLED
#define Port_A_Pin_1_GPIO_Type          PORT_GPIO_ENABLED
#define Port_A_Pin_2_GPIO_Type          PORT_GPIO_ENABLED
#define Port_A_Pin_3_GPIO_Type          PORT_GPIO_ENABLED
#define Port_A_Pin_4_GPIO_Type          PORT_GPIO_ENABLED
#define Port_A_Pin_5_GPIO_Type          PORT_GPIO_ENABLED
#define Port_A_Pin_6_GPIO_Type          PORT_GPIO_ENABLED
#define Port_A_Pin_7_GPIO_Type          PORT_GPIO_ENABLED

#define Port_B_Pin_0_GPIO_Type          PORT_GPIO_ENABLED
#define Port_B_Pin_1_GPIO_Type          PORT_GPIO_ENABLED
#define Port_B_Pin_2_GPIO_Type          PORT_GPIO_ENABLED
#define Port_B_Pin_3_GPIO_Type          PORT_GPIO_ENABLED
#define Port_B_Pin_4_GPIO_Type          PORT_GPIO_ENABLED
#define Port_B_Pin_5_GPIO_Type          PORT_GPIO_ENABLED
#define Port_B_Pin_6_GPIO_Type          PORT_GPIO_ENABLED
#define Port_B_Pin_7_GPIO_Type          PORT_GPIO_ENABLED

#define Port_C_Pin_0_GPIO_Type          PORT_GPIO_ENABLED
#define Port_C_Pin_1_GPIO_Type          PORT_GPIO_ENABLED
#define Port_C_Pin_2_GPIO_Type          PORT_GPIO_ENABLED
#define Port_C_Pin_3_GPIO_Type          PORT_GPIO_ENABLED
#define Port_C_Pin_4_GPIO_Type          PORT_GPIO_ENABLED
#define Port_C_Pin_5_GPIO_Type          PORT_GPIO_ENABLED
#define Port_C_Pin_6_GPIO_Type          PORT_GPIO_ENABLED
#define Port_C_Pin_7_GPIO_Type          PORT_GPIO_ENABLED

#define Port_D_Pin_0_GPIO_Type          PORT_GPIO_ENABLED
#define Port_D_Pin_1_GPIO_Type          PORT_GPIO_ENABLED
#define Port_D_Pin_2_GPIO_Type          PORT_GPIO_ENABLED
#define Port_D_Pin_3_GPIO_Type          PORT_GPIO_ENABLED
#define Port_D_Pin_4_GPIO_Type          PORT_GPIO_ENABLED
#define Port_D_Pin_5_GPIO_Type          PORT_GPIO_ENABLED
#define Port_D_Pin_6_GPIO_Type          PORT_GPIO_ENABLED
#define Port_D_Pin_7_GPIO_Type          PORT_GPIO_ENABLED

#define Port_E_Pin_0_GPIO_Type          PORT_GPIO_ENABLED
#define Port_E_Pin_1_GPIO_Type          PORT_GPIO_ENABLED
#define Port_E_Pin_2_GPIO_Type          PORT_GPIO_ENABLED
#define Port_E_Pin_3_GPIO_Type          PORT_GPIO_ENABLED
#define Port_E_Pin_4_GPIO_Type          PORT_GPIO_ENABLED
#define Port_E_Pin_5_GPIO_Type          PORT_GPIO_ENABLED

#define Port_F_Pin_0_GPIO_Type          PORT_GPIO_ENABLED
#define Port_F_Pin_1_GPIO_Type          PORT_GPIO_ENABLED  /* LED Pin */
#define Port_F_Pin_2_GPIO_Type          PORT_GPIO_ENABLED
#define Port_F_Pin_3_GPIO_Type          PORT_GPIO_ENABLED
#define Port_F_Pin_4_GPIO_Type          PORT_GPIO_ENABLED  /* Button Pin */


/* Possible values of the Digital Enable Type{ PORT_DIGITAL_DISABLED, PORT_DIGITAL_ENABLED} */
#define Port_A_Pin_0_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_A_Pin_1_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_A_Pin_2_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_A_Pin_3_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_A_Pin_4_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_A_Pin_5_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_A_Pin_6_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_A_Pin_7_Port_DigitalEnableType         PORT_DIGITAL_ENABLED

#define Port_B_Pin_0_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_B_Pin_1_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_B_Pin_2_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_B_Pin_3_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_B_Pin_4_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_B_Pin_5_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_B_Pin_6_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_B_Pin_7_Port_DigitalEnableType         PORT_DIGITAL_ENABLED

#define Port_C_Pin_0_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_C_Pin_1_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_C_Pin_2_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_C_Pin_3_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_C_Pin_4_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_C_Pin_5_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_C_Pin_6_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_C_Pin_7_Port_DigitalEnableType         PORT_DIGITAL_ENABLED

#define Port_D_Pin_0_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_D_Pin_1_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_D_Pin_2_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_D_Pin_3_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_D_Pin_4_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_D_Pin_5_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_D_Pin_6_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_D_Pin_7_Port_DigitalEnableType         PORT_DIGITAL_ENABLED

#define Port_E_Pin_0_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_E_Pin_1_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_E_Pin_2_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_E_Pin_3_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_E_Pin_4_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_E_Pin_5_Port_DigitalEnableType         PORT_DIGITAL_ENABLED

#define Port_F_Pin_0_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_F_Pin_1_Port_DigitalEnableType         PORT_DIGITAL_ENABLED  /* LED Pin */
#define Port_F_Pin_2_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_F_Pin_3_Port_DigitalEnableType         PORT_DIGITAL_ENABLED
#define Port_F_Pin_4_Port_DigitalEnableType         PORT_DIGITAL_ENABLED  /* Button Pin */

/* Possible values of  Analog Enable Type { PORT_ANALOG_DISABLED, PORT_ANALOG_ENABLED } */
#define Port_A_Pin_0_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_A_Pin_1_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_A_Pin_2_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_A_Pin_3_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_A_Pin_4_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_A_Pin_5_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_A_Pin_6_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_A_Pin_7_Port_AnalogEnableType         PORT_ANALOG_DISABLED

#define Port_B_Pin_0_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_B_Pin_1_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_B_Pin_2_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_B_Pin_3_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_B_Pin_4_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_B_Pin_5_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_B_Pin_6_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_B_Pin_7_Port_AnalogEnableType         PORT_ANALOG_DISABLED

#define Port_C_Pin_0_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_C_Pin_1_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_C_Pin_2_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_C_Pin_3_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_C_Pin_4_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_C_Pin_5_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_C_Pin_6_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_C_Pin_7_Port_AnalogEnableType         PORT_ANALOG_DISABLED

#define Port_D_Pin_0_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_D_Pin_1_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_D_Pin_2_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_D_Pin_3_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_D_Pin_4_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_D_Pin_5_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_D_Pin_6_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_D_Pin_7_Port_AnalogEnableType         PORT_ANALOG_DISABLED

#define Port_E_Pin_0_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_E_Pin_1_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_E_Pin_2_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_E_Pin_3_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_E_Pin_4_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_E_Pin_5_Port_AnalogEnableType         PORT_ANALOG_DISABLED

#define Port_F_Pin_0_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_F_Pin_1_Port_AnalogEnableType         PORT_ANALOG_DISABLED  /* LED Pin */
#define Port_F_Pin_2_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_F_Pin_3_Port_AnalogEnableType         PORT_ANALOG_DISABLED
#define Port_F_Pin_4_Port_AnalogEnableType         PORT_ANALOG_DISABLED  /* Button Pin */



/* Possible values of the Open Drain Select Type {PORT_OPEN_DRAIN_DISABLED, PORT_OPEN_DRAIN_ENABLED}*/
#define Port_A_Pin_0_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_A_Pin_1_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_A_Pin_2_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_A_Pin_3_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_A_Pin_4_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_A_Pin_5_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_A_Pin_6_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_A_Pin_7_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED

#define Port_B_Pin_0_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_B_Pin_1_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_B_Pin_2_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_B_Pin_3_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_B_Pin_4_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_B_Pin_5_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_B_Pin_6_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_B_Pin_7_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED

#define Port_C_Pin_0_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_C_Pin_1_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_C_Pin_2_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_C_Pin_3_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_C_Pin_4_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_C_Pin_5_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_C_Pin_6_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_C_Pin_7_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED

#define Port_D_Pin_0_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_D_Pin_1_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_D_Pin_2_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_D_Pin_3_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_D_Pin_4_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_D_Pin_5_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_D_Pin_6_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_D_Pin_7_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED

#define Port_E_Pin_0_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_E_Pin_1_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_E_Pin_2_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_E_Pin_3_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_E_Pin_4_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_E_Pin_5_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED

#define Port_F_Pin_0_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_F_Pin_1_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED  /* LED Pin */
#define Port_F_Pin_2_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_F_Pin_3_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED
#define Port_F_Pin_4_OpenDrainSelectType          PORT_OPEN_DRAIN_DISABLED  /* Button Pin */






/* Possible values of the Slew Rate Select Type {PORT_SLEW_RATE_DISABLED, PORT_SLEW_RATE_ENABLED} */
#define Port_A_Pin_0_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_A_Pin_1_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_A_Pin_2_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_A_Pin_3_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_A_Pin_4_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_A_Pin_5_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_A_Pin_6_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_A_Pin_7_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED

#define Port_B_Pin_0_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_B_Pin_1_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_B_Pin_2_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_B_Pin_3_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_B_Pin_4_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_B_Pin_5_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_B_Pin_6_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_B_Pin_7_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED

#define Port_C_Pin_0_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_C_Pin_1_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_C_Pin_2_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_C_Pin_3_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_C_Pin_4_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_C_Pin_5_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_C_Pin_6_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_C_Pin_7_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED

#define Port_D_Pin_0_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_D_Pin_1_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_D_Pin_2_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_D_Pin_3_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_D_Pin_4_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_D_Pin_5_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_D_Pin_6_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_D_Pin_7_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED

#define Port_E_Pin_0_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_E_Pin_1_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_E_Pin_2_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_E_Pin_3_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_E_Pin_4_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_E_Pin_5_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED

#define Port_F_Pin_0_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_F_Pin_1_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED  /* LED Pin */
#define Port_F_Pin_2_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_F_Pin_3_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED
#define Port_F_Pin_4_Port_SlewRateSelectType         PORT_SLEW_RATE_DISABLED  /* Button Pin */






#endif