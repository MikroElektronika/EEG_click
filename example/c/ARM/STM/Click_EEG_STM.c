/*
Example for EEG Click

    Date          : Oct 2018.
    Author        : Nemanja Medakovic

Test configuration STM32 :
    
    MCU              : STM32F107VCT6
    Dev. Board       : EasyMx PRO v7 for STM32
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes ADC and timer interrupt function.
- Application Task - (code snippet) - Reads ADC value and sends results on serial plotter 
  every time when interrupt occurres.

Additional Functions :

- void initTimer2() - Initializes interrupt time to 5ms.

*/

#include "Click_EEG_types.h"
#include "Click_EEG_config.h"

uint32_t interrCnt;
uint8_t interrFlag;
uint16_t readADC;
uint32_t timeRead;
const uint16_t time_ms = 5;
char text[ 50 ];

void initTimer2()
{
    RCC_APB1ENR.TIM2EN = 1;
    TIM2_CR1.CEN = 0;
    TIM2_PSC = 5;
    TIM2_ARR = 59999;
    NVIC_IntEnable(IVT_INT_TIM2);
    TIM2_DIER.UIE = 1;
    TIM2_CR1.CEN = 1;
}

void plotRes( uint16_t plotData, uint32_t plotTime )
{
    WordToStr( plotData, text );
    mikrobus_logWrite( text, _LOG_TEXT );
    mikrobus_logWrite( ",", _LOG_TEXT );
    LongWordToStr( plotTime, text );
    mikrobus_logWrite( text, _LOG_LINE );
}

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );

    mikrobus_logInit( _LOG_USBUART_A, 115200 );

    Delay_ms( 200 );
}

void applicationInit()
{
    eeg_gpioDriverInit( (T_EEG_P)&_MIKROBUS1_GPIO );
    Delay_ms( 200 );
    
    ADC1_Init();
    ADC_Set_Input_Channel( _ADC_CHANNEL_4 );
    Delay_ms( 200 );
    
    initTimer2();
    interrFlag = 0;
    interrCnt = 0;
    EnableInterrupts();
}

void applicationTask()
{
    if (interrFlag == 1)
    {
        interrFlag = 0;
        DisableInterrupts();
        
        readADC = ADC1_Get_Sample( 4 );
        timeRead = interrCnt * time_ms;
        plotRes( readADC, timeRead );
        EnableInterrupts();
    }
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}

void Timer2_interrupt() iv IVT_INT_TIM2 
{
    TIM2_SR.UIF = 0;
    interrFlag = 1;
    
    if (interrCnt == 0x33333333)
    {
        interrCnt = 0;
    }
    else
    {
        interrCnt++;
    }
}
