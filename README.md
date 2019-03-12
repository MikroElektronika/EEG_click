![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# EEG Click

- **CIC Prefix**  : EEG
- **Author**      : Nemanja Medakovic
- **Verison**     : 1.0.0
- **Date**        : Oct 2018.

---


### Software Support

We provide a library for the EEG Click on our [LibStock](https://libstock.mikroe.com/projects/view/2594/eeg-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Library only initializes GPIO interface.
For more details check documentation.

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes ADC and timer interrupt function.
- Application Task - (code snippet) - Reads ADC value and sends results on serial plotter 
  every time when interrupt occurres.


```.c
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
```

Additional Functions :

- void initTimer() - Initializes interrupt time to the desired value.
- void plotRes( uint16_t plotData, uint32_t plotTime ) - Sends ADC data on the serial plotter.

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2594/eeg-click) page.

Other mikroE Libraries used in the example:

- Conversions
- ADC
- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
