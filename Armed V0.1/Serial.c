#include "Serial.h"

void StartSerial(int USART)
{
	switch (USART) 
	{
	case 1: //USART 1
	RCC->APB2ENR|=RCC_APB2ENR_USART1EN|RCC_APB2ENR_IOPAEN|RCC_APB2ENR_AFIOEN; //ENABLE USART1, PORTA CLOCK AND ALTERNATE FUNCTION IN APB2 
	GPIOA->CRH |=GPIO_CRH_CNF9_1|GPIO_CRH_MODE9_0|GPIO_CRH_MODE9_1; //SET PIN A9 TO ALTERNATE FUNCTION, OUTPUT, PUSH PULL
	GPIOA->CRH &=~(GPIO_CRH_CNF9_0);
	//A10 which is the RX, is already set  to input flaoting by defualt
	USART1->BRR=0x1D4C; //set baud rate
	USART1->CR1|=USART_CR1_TE|USART_CR1_UE|USART_CR1_RE; //ENABLE USART, RX AND TRANSMITTER IN USART1 CONTRL REGISTER
	USART1->CR1|=USART_CR1_RXNEIE; //|USART_CR1_TXEIE; //ENABLE INTERRUPTS FOR RX NOT EMPTY AND TX EMPTY
	USART1->CR3|=USART_CR3_DMAR; //DMA ENABLE FOR MULTI BUFFER
	NVIC_EnableIRQ(USART1_IRQn);// ENABLE INERRUPT LINE FOR USART AT NVIC
	break;
	case 2: //USART 2
		
	break;
	
	
	
	
	
	}
}

//////////////////////////////////
 void Serial_1Print( char *message, ...)
 {
	 va_list args;
	 va_start (args,message);
	 vsprintf(buf,message,args);
	 
	 for(int i=0;i<strlen(buf);i++)
	 {
		 USART1->DR=buf[i];
		 while(!(USART1->SR & USART_SR_TXE));
		 
	 }
	 
 }
 
  void Serial_2Print( char *message, ...)
 {
	 va_list args;
	 va_start (args,message);
	 vsprintf(buf,message,args);
	 
	 for(int i=0;i<strlen(buf);i++)
	 {
		 USART2->DR=buf[i];
		 while(!(USART2->SR & USART_SR_TXE));
		 
	 }
	 
 }
 
///////////////////////////////////////
 
 

 
 
 
 
 
   
   

	    