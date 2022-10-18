
//Interfacing HC05 Blue tooth module with with PIC 16F877A microcontroller
#include <xc.h>
#define _XTAL_FREQ 20000000
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_OFF & LVP_OFF & CPD_OFF & WRT_OFF & CP_OFF);//configuration bit setting
unsigned char blue_data=0;// global variable char type (blue_data) initial value is 0
void interrupt RECEIVE()// interrupt function
{
if(PIR1bits. RCIF==1)//if UART receive interrupt flag is 1
{
	blue_data=RCREG;
 PIR1bits. RCIF = 0;
}
}
void main()// main function
{
	INTCONbits.GIE = 1;//Global interrupt Enable bit
	INTCONbits.PEIE = 1;//Peripheral Interrupt Enable
	PIE1bits.RCIE = 1;// Enable receive interrupt
	    
	    TXSTA=0X24;//(00100100)Transmit Status And Control Register
        RCSTA=0X90;//Receive status and control register

	     SPBRG = 129;//USART Baud Rate Generator 

	TRISC = 0x80;
	TRISB1 = 0;// set PortB1 as an output
    TRISB2 = 0;// set PortB2 as an output
    TRISB3 = 0;// set PortB3 as an output
    TRISB4 = 0;// set PortB4 as an output
	while(1)
	{   
        {
		if(blue_data == 'a')// when value of variable blue_data is 'a'
		{
			PORTBbits.RB1 = 1;// turn the RB1 HIGH
		}
		if(blue_data == 'b')// when value of variable blue_data is 'b'
			PORTBbits.RB1 = 0;// turn the RB1 LOW
		}
        if(blue_data == 'c')//when value of variable blue_data is 'c'
		{
			PORTBbits.RB2 = 1;// turn the RB2 HIGH
		}
        if(blue_data == 'd')// when value of variable blue_data is 'd' 
		{
			PORTBbits.RB2 = 0;// turn the RB2 LOW
		}
        if(blue_data == 'e')// when value of variable blue_data is 'e' 
		{
			PORTBbits.RB3 = 1;// turn the RB3 HIGH
		}
        if(blue_data == 'f')// when value of variable blue_data is 'f' 
		{
			PORTBbits.RB3 = 0;// turn the RB3 LOW
		}
        if(blue_data == 'g')// when value of variable blue_data is 'g' 
		{
			PORTBbits.RB4 = 1;// turn the RB4 HIGH
		}
        if(blue_data == 'h')// when value of variable blue_data is 'h' 
		{
			PORTBbits.RB4 = 0;// turn the RB4 LOW
		}
    }
}