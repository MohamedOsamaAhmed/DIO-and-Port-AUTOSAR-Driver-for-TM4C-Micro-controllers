/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Mohamed Osama
 ******************************************************************************/

#include "Port.h"
#include "tm4c123gh6pm_registers.h"

/************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): VersionInfo - Pointer to where to store the version information of this module.
* Return value: None
* Description: Function to get the version information of this module.
************************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
void PORT_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if input pointer is not Null pointer */
    if (NULL_PTR == versioninfo)
    {
        /* Report to DET  */
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
    }
    else
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
    {
        /* Copy the vendor Id */
        versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
        /* Copy the module Id */
        versioninfo->moduleID = (uint16)PORT_MODULE_ID;
        /* Copy Software Major Version */
        versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
        /* Copy Software Minor Version */
        versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
        /* Copy Software Patch Version */
        versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
    }
}
#endif

#if (PORT_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
/* AUTOSAR Version checking between Det and PORT Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION) || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION) || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif

#endif
STATIC void Port_SetAlternativeFunction(Port_PinType Pin);
STATIC const Port_Pin_ConfigType *Port_Pin_Config = NULL_PTR;

extern const Port_ConfiguredModesType Port_ConfigurationModes;
STATIC const Port_ConfigMode *Port_ConfiguredModes = (&Port_ConfigurationModes)->modes;
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;

/************************************************************************************
* Service Name: Port_Init
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr - Pointer to configuration set
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the Port Driver module
************************************************************************************/
void Port_Init(const Port_ConfigType *ConfigPtr)
{

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* check if the input configuration pointer is not a NULL_PTR */
    if (NULL_PTR == ConfigPtr)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
                        PORT_E_PARAM_CONFIG);
    }
    else
#endif
    {
        volatile uint32 delay = 0;
        volatile uint32 *PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */

        Port_Pin_Config = ConfigPtr->Pin_config;
        for (uint8 i = PORT_MIN_PIN_NUM; i < PORT_MAX_PIN_NUM; i++)
        {

            switch (Port_Pin_Config[i].Port_Num)
            {
            case 0:
                PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                break;
            case 1:
                PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                break;
            case 2:
                PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                break;
            case 3:
                PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                break;
            case 4:
                PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                break;
            case 5:
                PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                break;
            }
            /* Enable clock for PORT and allow time for clock to start*/
            SYSCTL_REGCGC2_REG |= (1 << Port_Pin_Config[i].Port_Num);
            delay = SYSCTL_REGCGC2_REG;

            if (((Port_Pin_Config[i].Port_Num == 3) && (Port_Pin_Config[i].Pin_Num == 7)) || ((Port_Pin_Config[i].Port_Num == 5) && (Port_Pin_Config[i].Pin_Num == 0))) /* PD7 or PF0 */
            {
                *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;                           /* Unlock the GPIOCR register */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET), Port_Pin_Config[i].Pin_Num); /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
            }
            else if ((Port_Pin_Config[i].Port_Num == 2) && (Port_Pin_Config[i].Pin_Num <= 3)) /* PC0 to PC3 */
            {
                /* Do Nothing ...  this is the JTAG pins */
                continue;
            }
            else
            {
                /* Do Nothing ... No need to unlock the commit register for this pin */
            }

            /*
            Set Pin Mode 
            */
            /* GPIO or Alternate function */
            if (Port_ConfiguredModes[i].Gpio_Enable == PORT_GPIO_ENABLED)
            {
                /* GPIO Enabled */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), Port_Pin_Config[i].Pin_Num);
                /* Clear the PMCx bits for this pin No need for alternate function */
                *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << Port_Pin_Config[i].Pin_Num);
            }
            else if (Port_ConfiguredModes[i].Gpio_Enable == PORT_GPIO_DISABLED)
            {
                /* Enable Alternate Function  */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), Port_Pin_Config[i].Pin_Num);
                Port_SetAlternativeFunction(Port_Pin_Config[i].Pin_Num);
            }
            else
            {
                /* Do Nothing */
            }

      
            /* Digital enable or disable */
            if (Port_ConfiguredModes[i].Digital_Enable == PORT_DIGITAL_DISABLED)
            {
                /* Disable Digital */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Port_Pin_Config[i].Pin_Num);
            }
            else if (Port_ConfiguredModes[i].Digital_Enable == PORT_DIGITAL_ENABLED)
            {
                /* Enable Digital */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Port_Pin_Config[i].Pin_Num);
            }
            else
            {
                /* Do Nothing */
            }

                  /* check if Analog mode is enabled or disabled */
            if (Port_ConfiguredModes[i].Analog_Enable == PORT_ANALOG_DISABLED)
            {
                /*  Disable Analog */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Port_Pin_Config[i].Pin_Num);
            }
            else if (Port_ConfiguredModes[i].Analog_Enable == PORT_ANALOG_ENABLED)
            {
                /* Enanle Analog */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Port_Pin_Config[i].Pin_Num);
            }
            else
            {
                /* Do Nothing */
            }


            /* Open Drain enable or disable */
            if (Port_ConfiguredModes[i].Open_Drain == PORT_OPEN_DRAIN_ENABLED)
            {
                /* Enable Open Drain  */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_OPEN_DRAIN_REG_OFFSET), Port_Pin_Config[i].Pin_Num);
            }
            else if (Port_ConfiguredModes[i].Open_Drain == PORT_OPEN_DRAIN_DISABLED)
            {
                /* Disable Open Drain  */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_OPEN_DRAIN_REG_OFFSET), Port_Pin_Config[i].Pin_Num);
            }
            else
            {
                /* Do Nothing */
            }

            /* Slew Rate Select*/
            if (Port_ConfiguredModes[i].Slew_Rate == TRUE)
            {
                /* Enable Slew Rate  */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_SLEW_RATE_REG_OFFSET), Port_Pin_Config[i].Pin_Num);
            }
            else if (Port_ConfiguredModes[i].Slew_Rate == FALSE)
            {
                /* Disable Slew Rate  */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_SLEW_RATE_REG_OFFSET), Port_Pin_Config[i].Pin_Num);
            }
            else
            {
                /* Do Nothing */
            }

            /* Set Pin Direction    */

            if (Port_Pin_Config[i].Pin_Direction == PORT_PIN_OUTPUT)
            {
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), Port_Pin_Config[i].Pin_Num); /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
                if (Port_Pin_Config[i].Pin_InitialLevel == STD_HIGH)
                {
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET), Port_Pin_Config[i].Pin_Num); /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
                }
                else
                {
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET), Port_Pin_Config[i].Pin_Num); /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
                }
            }
            else if (Port_Pin_Config[i].Pin_Direction == PORT_PIN_INPUT)
            {
                /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), Port_Pin_Config[i].Pin_Num);

                if (Port_Pin_Config[i].Pin_Resistor == PULL_UP)
                {
                    /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET), Port_Pin_Config[i].Pin_Num);
                }
                else if (Port_Pin_Config[i].Pin_Resistor == PULL_DOWN)
                {
                    /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET), Port_Pin_Config[i].Pin_Num);
                }
                else
                {
                    /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET), Port_Pin_Config[i].Pin_Num);
                    /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET), Port_Pin_Config[i].Pin_Num);
                }
            }
            else
            {
                /* Do Nothing */
            }
        }
        /*
		 * Set the module state to initialized and point to the PB configuration structure using a global pointer.
		 * This global pointer is global to be used by other functions to read the PB configuration structures
		 */
        Port_Status = PORT_INITIALIZED;
    }
}

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
#if (STD_ON == PORT_SET_PIN_MODE_API)
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
    boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)

    /* Check if the Driver is initialized before using this function */
    if (PORT_NOT_INITIALIZED == Port_Status)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
        error = TRUE;
    }
    /* Check if the used pin number is within the valid range */
    if (Pin >= PORT_NUMBER_OF_PORT_PINS)
    {

        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
        error = TRUE;
    }
    else
    {
        /* No Action Required */
    }
    /* Check if the used pin mode is with in valid modes  */
    if (PORT_CONFIG_MODE_NUM <= Mode)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
        error = TRUE;
    }

    /* Check if the entered pin has a changeable mode */
    if (STD_OFF == Port_Pin_Config[Pin].Pin_Mode_Change)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
        error = TRUE;
    }
    else
    {
        /* No Action Required */
    }

#endif

    /* In-case there are no errors */
    if (FALSE == error)
    {
        /* Calculate Port number from the given pin number*/
        volatile uint32 *PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
        switch (Port_Pin_Config[Pin].Port_Num)
        {
        case 0:
            PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
            break;
        case 1:
            PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
            break;
        case 2:
            PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
            break;
        case 3:
            PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
            break;
        case 4:
            PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
            break;
        case 5:
            PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
            break;
        }

        /* GPIO or Alternate function */
        if (Port_ConfiguredModes[Pin].Gpio_Enable == PORT_GPIO_ENABLED)
        {
            /* Enable GPIO  */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);
            /* Clear the PMCx bits for this pin No need for alternate function */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << Port_Pin_Config[Pin].Pin_Num);
        }
        else if (Port_ConfiguredModes[Pin].Gpio_Enable == PORT_GPIO_DISABLED)
        {
            /* Enable Alternate Function  */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);
            Port_SetAlternativeFunction(Port_Pin_Config[Pin].Pin_Num);
        }
        else
        {
            /* Do Nothing */
        }

        /* Digital enable or disable */
        if (Port_ConfiguredModes[Pin].Digital_Enable == PORT_DIGITAL_DISABLED)
        {
            /* Digital Disabled*/
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);
        }
        else if (Port_ConfiguredModes[Pin].Digital_Enable == PORT_DIGITAL_ENABLED)
        {
            /* Digital Enabled*/
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);
        }
        else
        {
            /* Do Nothing */
        }

        /* enable Analog  or disable */
        if (Port_ConfiguredModes[Pin].Analog_Enable == PORT_ANALOG_DISABLED)
        {
            /*  Disable Analog */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);
        }
        else if (Port_ConfiguredModes[Pin].Analog_Enable == PORT_ANALOG_ENABLED)
        {
            /* enable Analog  */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);
        }
        else
        {
            /* Do Nothing */
        }

       

        /* enable Open Drain or disable */
        if (Port_ConfiguredModes[Pin].Open_Drain == PORT_OPEN_DRAIN_ENABLED)
        {
            /* enable Open Drain */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_OPEN_DRAIN_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);
        }
        else if (Port_ConfiguredModes[Pin].Open_Drain == PORT_OPEN_DRAIN_DISABLED)
        {
            /* disable Open Drain  */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_OPEN_DRAIN_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);
        }
        else
        {
            /* Do Nothing */
        }

        /* Select Slew Rate */
        if (Port_ConfiguredModes[Pin].Slew_Rate == TRUE)
        {
            /* Enable Slew Rate  */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_SLEW_RATE_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);
        }
        else if (Port_ConfiguredModes[Pin].Slew_Rate == FALSE)
        {
            /* Disable Slew Rate  */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_SLEW_RATE_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);
        }
        else
        {
            /* Do Nothing */
        }
    }
}

#endif

STATIC void Port_SetAlternativeFunction(Port_PinType Pin)
{

    /* Calculate Port number from the given pin number*/
    volatile uint32 *PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
    switch (Port_Pin_Config[Pin].Port_Num)
    {
    case 0:
        PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
        break;
    case 1:
        PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
        break;
    case 2:
        PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
        break;
    case 3:
        PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
        break;
    case 4:
        PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
        break;
    case 5:
        PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
        break;
    }
    switch (Port_Pin_Config[Pin].Pin_Mode)
    {

    case PORT_PIN_MODE_DIO:
        break;

    case PORT_PIN_MODE_ADC:
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0xF << (Port_Pin_Config[Pin].Pin_Num) * 4);
        break;

    case PORT_PIN_MODE_M0PWMx:
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0xF << (Port_Pin_Config[Pin].Pin_Num) * 4);
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (4 << (Port_Pin_Config[Pin].Pin_Num) * 4);
        break;

    case PORT_PIN_MODE_M1PWMx:
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0xF << (Port_Pin_Config[Pin].Pin_Num) * 4);
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (5 << (Port_Pin_Config[Pin].Pin_Num) * 4);
        break;    

    case PORT_PIN_MODE_SSI3:
    case PORT_PIN_MODE_JTAG:
    case PORT_PIN_MODE_UART:
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0xF << (Port_Pin_Config[Pin].Pin_Num) * 4);
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (1 << (Port_Pin_Config[Pin].Pin_Num) * 4);
        break;

    case PORT_PIN_MODE_SSI1:
    case PORT_PIN_MODE_SSI2:
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0xF << (Port_Pin_Config[Pin].Pin_Num) * 4);
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (2 << (Port_Pin_Config[Pin].Pin_Num) * 4);
        break;

    case PORT_PIN_MODE_CORE:
    case PORT_PIN_MODE_I2C:
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0xF << (Port_Pin_Config[Pin].Pin_Num) * 4);
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (3 << (Port_Pin_Config[Pin].Pin_Num) * 4);
        break;

    case PORT_PIN_MODE_CAN:
        if (Port_Pin_Config[Pin].Port_Num == Port_F_Num)
        {
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0xF << (Port_Pin_Config[Pin].Pin_Num) * 4);
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (3 << (Port_Pin_Config[Pin].Pin_Num) * 4);
        }
        else if (Port_Pin_Config[Pin].Port_Num == Port_F_Num)
        {
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0xF << (Port_Pin_Config[Pin].Pin_Num) * 4);
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (8 << (Port_Pin_Config[Pin].Pin_Num) * 4);
        }
        break;

    case PORT_PIN_MODE_U1Rx:
    case PORT_PIN_MODE_U1Tx:
        if (Port_Pin_Config[Pin].Port_Num == Port_F_Num)
        {
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0xF << (Port_Pin_Config[Pin].Pin_Num) * 4);
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (2 << (Port_Pin_Config[Pin].Pin_Num) * 4);
        }
        else if (Port_Pin_Config[Pin].Port_Num == Port_F_Num)
        {
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0xF << (Port_Pin_Config[Pin].Pin_Num) * 4);
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (1 << (Port_Pin_Config[Pin].Pin_Num) * 4);
        }
        break;
    
    case PORT_PIN_MODE_USB:
        if ((Port_Pin_Config[Pin].Port_Num == Port_D_Num && Port_Pin_Config[Pin].Pin_Num == Port_D_Pin_5) 
        ||  (Port_Pin_Config[Pin].Port_Num == Port_B_Num && Port_Pin_Config[Pin].Pin_Num == Port_B_Pin_1) 
        ||  (Port_Pin_Config[Pin].Port_Num == Port_D_Num && Port_Pin_Config[Pin].Pin_Num == Port_D_Pin_1))
        {
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0xF << (Port_Pin_Config[Pin].Pin_Num) * 4);
        }
        else
        {
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0xF << (Port_Pin_Config[Pin].Pin_Num) * 4);
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (8 << (Port_Pin_Config[Pin].Pin_Num) * 4);
        }
        break;    

    case PORT_PIN_MODE_QEI:
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0xF << (Port_Pin_Config[Pin].Pin_Num) * 4);
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (6 << (Port_Pin_Config[Pin].Pin_Num) * 4);
        break;

    case PORT_PIN_MODE_TxCCPx:
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0xF << (Port_Pin_Config[Pin].Pin_Num) * 4);
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (7 << (Port_Pin_Config[Pin].Pin_Num) * 4);
        break;

    case PORT_PIN_MODE_NMI:
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0xF << (Port_Pin_Config[Pin].Pin_Num) * 4);
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (8 << (Port_Pin_Config[Pin].Pin_Num) * 4);
        break;

    case PORT_PIN_MODE_COMP:
        if (Port_Pin_Config[Pin].Port_Num == Port_F_Num)
        {
            /* C0+, C0-, C1+, C1- */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0xF << (Port_Pin_Config[Pin].Pin_Num) * 4);
        }
        else if (Port_Pin_Config[Pin].Port_Num == Port_F_Num)
        {
            /*C0o, C1o*/
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0xF << (Port_Pin_Config[Pin].Pin_Num) * 4);
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (9 << (Port_Pin_Config[Pin].Pin_Num) * 4);
        }
        else
        {
            /* Do nothing */
        }
        break;

    case PORT_PIN_MODE_U1CTS:
    case PORT_PIN_MODE_U1RTS:
        if (Port_Pin_Config[Pin].Port_Num == Port_C_Num)
        {
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0xF << (Port_Pin_Config[Pin].Pin_Num) * 4);
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (8 << (Port_Pin_Config[Pin].Pin_Num) * 4);
        }
        else if (Port_Pin_Config[Pin].Port_Num == Port_F_Num)
        {
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0xF << (Port_Pin_Config[Pin].Pin_Num) * 4);
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (1 << (Port_Pin_Config[Pin].Pin_Num) * 4);
        }
        break;

    default:
        break;
    }
}

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
void Port_RefreshPortDirection(void)
{
    boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the Driver is initialized before using this function */
    if (PORT_NOT_INITIALIZED == Port_Status)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
        error = TRUE;
    }
    else
    {
        /* No Action Required */
    }

#endif

    /* In-case there are no errors */
    if (FALSE == error)
    {

        volatile uint32 *PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
        for (uint8 i = PORT_MIN_PIN_NUM; i < PORT_MAX_PIN_NUM; i++)
        {
            /* Check if the entered pin has a changeable mode */
            if (STD_OFF == Port_Pin_Config[i].Pin_Dir_Change)
            {
                switch (Port_Pin_Config[i].Port_Num)
                {
                case 0:
                    PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                    break;
                case 1:
                    PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                    break;
                case 2:
                    PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                    break;
                case 3:
                    PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                    break;
                case 4:
                    PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                    break;
                case 5:
                    PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                    break;
                }

                if (Port_Pin_Config[i].Pin_Direction == PORT_PIN_OUTPUT)
                {
                    /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), Port_Pin_Config[i].Pin_Num);
                }
                else if (Port_Pin_Config[i].Pin_Direction == PORT_PIN_INPUT)
                {
                    /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), Port_Pin_Config[i].Pin_Num);
                }

                else
                {
                    /* Do Nothing */
                }
            }

            else
            {
                /* No Action Required*/
            }
        }
    }

    else
    {
        /* No Action Required */
    }
}

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
#if (STD_ON == PORT_SET_PIN_DIRECTION_API)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{

    boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the Driver is initialized before using this function */
    if (PORT_NOT_INITIALIZED == Port_Status)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
        error = TRUE;
    }
    else
    {
        /* No Action Required */
    }
    /* Check if the used pin number is within the valid range */
    if (PORT_NUMBER_OF_PORT_PINS <= Pin)
    {

        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
        error = TRUE;
    }
    else
    {
        /* No Action Required */
    }

    /* Check if the entered pin has a changeable mode */
    if (STD_OFF == Port_Pin_Config[Pin].Pin_Dir_Change)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        PORT_SET_PIN_DIRECTION_SID, PORT_E_DIRECTION_UNCHANGEABLE);
        error = TRUE;
    }
    else
    {
        /* No Action Required */
    }

#endif

    /* In-case there are no errors */
    if (FALSE == error)
    {
        /* Calculate Port number from the given pin number*/
        volatile uint32 *PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
        switch (Port_Pin_Config[Pin].Port_Num)
        {
        case 0:
            PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
            break;
        case 1:
            PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
            break;
        case 2:
            PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
            break;
        case 3:
            PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
            break;
        case 4:
            PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
            break;
        case 5:
            PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
            break;
        }
        if (Direction == PORT_PIN_OUTPUT)
        {
            /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);
            if (Port_Pin_Config[Pin].Pin_InitialLevel == STD_HIGH)
            {
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num); /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
            }
            else
            {
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num); /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
            }
        }
        else if (Direction == PORT_PIN_INPUT)
        {
            /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

            if (Port_Pin_Config[Pin].Pin_Resistor == PULL_UP)
            {
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num); /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
            }
            else if (Port_Pin_Config[Pin].Pin_Resistor == PULL_DOWN)
            {
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num); /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
            }
            else
            {
                /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);
                /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);
            }
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        /* No Action Required */
    }
}
#endif