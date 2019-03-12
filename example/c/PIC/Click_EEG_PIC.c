/*
Example for EEG Click

    Date          : Oct 2018.
    Author        : Nemanja Medakovic

Test configuration PIC :
    
    MCU             : P18F87K22
    Dev. Board      : EasyPIC PRO v7
    PIC Compiler ver : v7.2.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes ADC and timer interrupt function.
- Application Task - (code snippet) - Reads ADC value and sends results on serial plotter 
  every time when interrupt occurres.

Additional Functions :

- void initTimer1() - Initializes interrupt time to 5ms.

*/

#include "Click_EEG_types.h"
#include "Click_EEG_config.h"

uint32_t interrCnt;
uint8_t interrFlag;
uint16_t readADC;
uint32_t timeRead;
const uint16_t time_ms = 5;
char text[ 50 ];

void initTimer1()
{
    T1CON = 0x11;
    TMR1IF_bit = 0;
    TMR1H = 0x63;
    TMR1L = 0xC0;
    TMR1IE_bit = 1;
    INTCON = 0xC0;
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

    mikrobus_logInit( _LOG_USBUART, 115200 );

    Delay_ms( 200 );
}

void applicationInit()
{
    eeg_gpioDriverInit( (T_EEG_P)&_MIKROBUS1_GPIO );
    Delay_ms( 200 );
    
    ADC_Init();
    Delay_ms( 200 );
    
    initTimer1();
    interrFlag = 0;
    interrCnt = 0;
}

void applicationTask()
{
    if (interrFlag == 1)
    {
        interrFlag = 0;
        
        readADC = ADC_Get_Sample( 0 );
        timeRead = interrCnt * time_ms;
        plotRes( readADC, timeRead );
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

void interrupt()
{
    if (TMR1IF_bit != 0)
    { 
        TMR1IF_bit = 0;
        TMR1H = 0x63;
        TMR1L = 0xC0;
		
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
}
