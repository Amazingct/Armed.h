#include "Armed.h"

int main(void)
{
int  b;
	
	//start serial communication (USART 1)
	StartSerial(1);
	//set up sysclock for delay function
	InitTimer();
	//set up pins 
	pinMode(PORT_C, 15, INPUT);
	pinMode(PORT_A, 5, OUTPUT);
	pinMode(PORT_A, 6, OUTPUT);
	while (1)
	{
		
	//write 1 (one) to Pin 5, port A and pin 6, port A
	digitalWrite(PORT_A,5,HIGH);
	digitalWrite(PORT_A,6,HIGH);
		
	//read Pin 15, Port C and print value to serial monitor
	b=digitalRead(PORT_C,15);
	Serial_1Print(" %d\n",b);
		
	//delay 1 second
	Delay(1000);
	
		
	//write 0 (zero) to Pin 5, port A and pin 6, port A
	digitalWrite(PORT_A,5,LOW);
	digitalWrite(PORT_A,6,LOW);
	Delay(1000);
		

		
		
	}
	
	
	
	
}
