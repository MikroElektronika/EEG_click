/*
Example for EEG Click

    Date          : Oct 2018.
    Author        : Nemanja Medakovic

Test configuration TIVA :
    
    MCU              : TM4C129XNCZAD
    Dev. Board       : EasyMx PRO v7 for TIVA ARM
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes ADC and timer interrupt function.
- Application Task - (code snippet) - Reads ADC value and sends results on serial plotter 
  every time when interrupt occurres.

Additional Functions :

- void initTimer0A() - Initializes interrupt time to 5ms.

*/

#include "Click_EEG_types.h"
#include "Click_EEG_config.h"

uint32_t interrCnt;
uint8_t interrFlag;
uint16_t readADC;
uint32_t timeRead;
const uint16_t time_ms = 5;
char text[ 50 ];

void initTimer0A()
{
    SYSCTL_RCGCTIMER_R0_bit = 1;
    TIMER_CTL_TAEN_bit = 0;
    TIMER0_CFG   = 4;
    TIMER0_TAMR |= 2;
    TIMER0_TAPR  = 9;
    TIMER0_TAILR = 60000;
    NVIC_IntEnable(IVT_INT_TIMER0A_16_32_bit);
    TIMER_IMR_TATOIM_bit = 1;
    TIMER_CTL_TAEN_bit   = 1;
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
    ADC_Set_Input_Channel( _ADC_CHANNEL_9 );
    Delay_ms( 200 );
    
    initTimer0A();
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
        
        readADC = ADC1_Get_Sample( 9 );
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

void Timer_interrupt() iv IVT_INT_TIMER0A_16_32_bit 
{
    TIMER_ICR_TATOCINT_bit = 1;
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
