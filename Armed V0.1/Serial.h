#ifndef __Serial__h
#define __Serial__h
#include "stm32f10x.h"
#include "string.h"     //standard c libaries
#include "stdlib.h"
#include "stdarg.h"



	 void StartSerial(int USART);
	 void Serial_1Print( char *message, ...);
	 void Serial_2Print( char *message, ...);
	 //char[] SerialRead(void);
	 static char buf[100];
	
	


#endif

