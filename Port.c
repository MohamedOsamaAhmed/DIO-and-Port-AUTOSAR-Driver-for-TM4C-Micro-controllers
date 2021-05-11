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

STATIC const Port_Pin_ConfigType *Port_Pin_Config = NULL_PTR;
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
            switch (Port_Pin_Config[i].Pin_Mode) /* check mode of the pin*/
            {
            case PORT_PIN_MODE_DIO:

                /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Port_Pin_Config[i].Pin_Num);

                /* Disable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), Port_Pin_Config[i].Pin_Num);

                /* Clear the PMCx bits for this pin */
                *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pin_Config[i].Pin_Num * 4));

                /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Port_Pin_Config[i].Pin_Num);
                break;

            case PORT_PIN_MODE_ADC:
                /* code */
                break;
            case PORT_PIN_MODE_CAN:
                /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Port_Pin_Config[i].Pin_Num);

                /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Port_Pin_Config[i].Pin_Num);

                break;
            case PORT_PIN_MODE_GPT:
                /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Port_Pin_Config[i].Pin_Num);

                /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Port_Pin_Config[i].Pin_Num);

                break;
            case PORT_PIN_MODE_WDG:
                /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Port_Pin_Config[i].Pin_Num);

                /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Port_Pin_Config[i].Pin_Num);

                break;
            case PORT_PIN_MODE_PWM:
                /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Port_Pin_Config[i].Pin_Num);

                /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Port_Pin_Config[i].Pin_Num);

                break;

            case PORT_PIN_MODE_UART:
                /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Port_Pin_Config[i].Pin_Num);

                /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Port_Pin_Config[i].Pin_Num);

                break;

            default:
                break;
            }

            /* Set Pin Direction    */

            if (Port_Pin_Config[i].Pin_Direction == PORT_PIN_OUTPUT)
            {
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), Port_Pin_Config[i].Pin_Num); /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
            }
            else if (Port_Pin_Config[i].Pin_Direction == PORT_PIN_INPUT)
            {
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), Port_Pin_Config[i].Pin_Num); /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
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
    if (PORT_NUMBER_OF_PORT_PINS <= Pin)
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

        switch (Mode) /* check mode of the pin*/
        {
        case PORT_PIN_MODE_DIO:

            /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

            /* Disable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

            /* Clear the PMCx bits for this pin */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pin_Config[Pin].Pin_Num * 4));

            /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);
            break;



        case PORT_PIN_MODE_ADC:

            /* Set the corresponding bit in the GPIOAMSEL register to Enable analog functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

            /* Enable Alternative function for this pin by Setting the corresponding bit in GPIOAFSEL register */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);



            /* Clear the corresponding bit in the GPIODEN register to disable digital functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);
            break;




        case PORT_PIN_MODE_CAN:
            /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

            /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

        
            /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

            /* Set the PMCx bits = F for this pin */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x0000000F << (Port_Pin_Config[Pin].Pin_Num * 4));

            
            break;



        case PORT_PIN_MODE_GPT:
            /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

            /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);
            
            
            /* Set the PMCx bits = 8 for this pin */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000008 << (Port_Pin_Config[Pin].Pin_Num * 4));

            /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

            /* Set the PMCx bits = F for this pin */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x0000000F << (Port_Pin_Config[Pin].Pin_Num * 4));

            break;


        case PORT_PIN_MODE_WDG:
            /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

            /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);
        
            /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

            /* Set the PMCx bits = F for this pin */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x0000000F << (Port_Pin_Config[Pin].Pin_Num * 4));


            break;


        case PORT_PIN_MODE_SSI:
            /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

            /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

            /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

            /* Set the PMCx bits = F for this pin */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x0000000F << (Port_Pin_Config[Pin].Pin_Num * 4));


            break;


        case PORT_PIN_MODE_I2C:
            /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

            /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);
        
            /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);
            

            /* Set the PMCx bits = F for this pin */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x0000000F << (Port_Pin_Config[Pin].Pin_Num * 4));

            break;




        case PORT_PIN_MODE_PWM:
            /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

            /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

            /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

            /* Set the PMCx bits = F for this pin */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x0000000F << (Port_Pin_Config[Pin].Pin_Num * 4));


            break;
            


        case PORT_PIN_MODE_UART:
            /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

            /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

            /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);

            /* Set the PMCx bits = F for this pin */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x0000000F << (Port_Pin_Config[Pin].Pin_Num * 4));


            break;

        default:
            break;
        }
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
        }
        else if (Direction == PORT_PIN_INPUT)
        {
            /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET), Port_Pin_Config[Pin].Pin_Num);
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
