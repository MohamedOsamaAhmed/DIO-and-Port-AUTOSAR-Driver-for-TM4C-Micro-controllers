# DIO-and-Port-AUTOSAR-Driver-for-TM4C-Micro-controllers

## Summary
The main function is toggling Led using Button as an input with specific requirements building all layers MCAL, ECUAL, Services layer contains Scheduler and Application with System Logic. The main purpose is not the logic of the application but applying AUTOSAR standard and Misra Rules in Port and Dio driver **only**.

## Requirements:
- Button is considered pressed if it reads high for 60ms
- Button is considered released if it reads low for 60ms 
- Led output needs to be refreshed every 40ms 

## What is need to done ?
>1-	Build **MCAL** contains **DIO** and **Timer** drivers 

>2-	Build **ECUAL** contains **Led** and **Button** drivers

>3-	Build **Services** layer contains **Scheduler**

>4-	Build **Application** contains **System Logic**

## Project Layers
![alt text](https://github.com/MohamedOsamaAhmed/DIO-and-Port-AUTOSAR-Driver-for-TM4C-Micro-controllers/blob/main/ProjectLayers.jpg?raw=true)

## Programming Language
    C Language

## Microcontroller
    Tiva C Series TM4C123GXL LaunchPad Evaluation kit  

## Software Complier & Editor
    IAR Embedded workbench

## AUTOSAR Version
	4.0.3

## Implementation 
The main function is toggling Led when button is pressed, refresh Led status every 40ms and check Button status every 60ms. So, we need timer to count base time which is common with 40ms and 60ms which is 20ms 

## Scheduler Flowchart
![alt text](https://github.com/MohamedOsamaAhmed/DIO-and-Port-AUTOSAR-Driver-for-TM4C-Micro-controllers/blob/main/Schedulerflowchart.jpg?raw=true)

## Code Tips
**In OS Scheduler function as shown**
```
 while(1)
    {
	/* Code is only executed in case there is a new timer tick */
	if(g_New_Time_Tick_Flag == 1)
	{
	    switch(g_Time_Tick_Count)
            {
		case 20:
		case 100:
			    Button_Task();
			    g_New_Time_Tick_Flag = 0;
			    break;
		case 40:
		case 80:
			    Button_Task();
			    Led_Task();
			    g_New_Time_Tick_Flag = 0;
			    break;
		case 60:
			    Button_Task();
			    App_Task();
			    g_New_Time_Tick_Flag = 0;
			    break;
		case 120:
			    Button_Task();
			    App_Task();
			    Led_Task();
			    g_New_Time_Tick_Flag = 0;
			    g_Time_Tick_Count = 0;
			    break;
            }
	}
    }
```
In requirements we have only to periods of time 40 and 60ms, so Why do we check on 100 and 120ms?
    1-	Because this is period when all actions in the scheduler occur together this enable us to make sure our system is working properly without any problems.
    2-	As we checked on 120ms we must check 100ms as it is a multiple of 20ms which is the used in our application in BUTTON_refreshState fuction as shown 
```
uint8 state = Dio_ReadChannel(DioConf_SW1_CHANNEL_ID_INDEX);
    
    /* Count the number of Pressed times increment if the switch pressed for 20 ms */
    static uint8 g_Pressed_Count  = 0;

    /* Count the number of Released times increment if the switch released for 20 ms */
    static uint8 g_Released_Count = 0;
    
    if(state == BUTTON_PRESSED)
    {
    g_Pressed_Count++;
	g_Released_Count = 0;
    }
    else
    {
	g_Released_Count++;
	g_Pressed_Count = 0;
    }

    if(g_Pressed_Count == 3)
    {
	g_button_state = BUTTON_PRESSED;
	g_Pressed_Count       = 0;
	g_Released_Count      = 0;
    }
    else if(g_Released_Count == 3)
    {
	g_button_state = BUTTON_RELEASED;
	g_Released_Count      = 0;
	g_Pressed_Count       = 0;
    }
```

So we refresh button state every 60ms but we call the function every 20ms that is the point.

•	We have 2 files of configurations one for precompile configuration and the other for post build configuration those configurations is time consumable specifically when you write more than 4 configurations for one pin what about 43 pins or more 
So I recommend you to use any tool helps you I suggest to use this tool of my friend which is perfect in this job form [here](https://github.com/autosar-drivers/autosar-drivers.github.io) 

## Conclusion 
    Writing AUTOSAR driver is not an impossible thing to do it is easy to need many lines of code than you actually need to support all features used and no used. Also applying AUTOSAR standard is for abstraction that is one of the main purpose for it. So if you are work in any project or company and you needn’t to write AUTOSAR standard don’t cost yourself to write code you will not use it only use your clear way to express solution. 

