#include "Armed.h"


 void pinMode(uint32_t port,uint32_t pin, uint32_t mode)
{
	RCC->APB2ENR|=(1U<<port);  //enable clock  for port a, b, c
	//pins are in input floating by default
	if( pin<=7&&mode==1) //if pin fall to CRL and mode is output
		{
			if (port==2) { GPIOA->CRL &=~((1<<((pin*4)+3))|(1<<((pin*4)+2))); GPIOA->CRL|=(1<<((pin*4)+1))|(1<<(pin*4)); }//set CFN to 00, set Mode to 11
			else if (port==3) { GPIOB->CRL &=~((1<<((pin*4)+3))|(1<<((pin*4)+2))); GPIOB->CRL|=(1<<((pin*4)+1))|(1<<(pin*4)); }//set CFN to 00, set Mode to 11
			else if (port==4) { GPIOC->CRL &=~((1<<((pin*4)+3))|(1<<((pin*4)+2))); GPIOC->CRL|=(1<<((pin*4)+1))|(1<<(pin*4)); }//set CFN to 00, set Mode to 11
		} 
	else if( pin<=7&&mode==0) //if the falls to CRL and mode is input
	{
			if (port==2) { GPIOA->CRL &=~(1<<((pin*4)+1))|(1<<((pin*4)))|(1<<((pin*4)+2)); GPIOA->CRL|=(1<<((pin*4)+3)); }// set Mode to 00' set CFN to 10,(input pull)
			else if (port==3) { GPIOB->CRL &=~((1<<((pin*4)+1))|(1<<((pin*4)))|(1<<((pin*4)+2))); GPIOB->CRL|=(1<<((pin*4)+3)); }// set Mode to 00, set CFN to 10,
			else if (port==4) { GPIOC->CRL &=~((1<<((pin*4)+1))|(1<<((pin*4)))|(1<<((pin*4)+2))); GPIOC->CRL|=(1<<((pin*4)+3)); }//set Mode to 00, set CFN to 10, 
	} 
	else if( pin>=8&&mode==1) //if the falls to CRH and mode is ouput
	{	
			pin=pin-8;
			if (port==2) 			{ GPIOA->CRH &=~((1<<((pin*4)+3))|(1<<((pin*4)+2))); GPIOA->CRH|=(1<<((pin*4)+1))|(1<<(pin*4)); }//set CFN to 00, set Mode to 11
			else if (port==3) { GPIOB->CRH &=~((1<<((pin*4)+3))|(1<<((pin*4)+2))); GPIOB->CRH|=(1<<((pin*4)+1))|(1<<(pin*4)); }//set CFN to 00, set Mode to 11
			else if (port==4) { GPIOC->CRH &=~((1<<((pin*4)+3))|(1<<((pin*4)+2))); GPIOC->CRH|=(1<<((pin*4)+1))|(1<<(pin*4)); }//set CFN to 00, set Mode to 11
	}
	else if( pin>=8&&mode==0) //if the falls to CRH and mode is input
	{
			pin=pin-8;
			if (port==2) 			{ GPIOA->CRH &=~((1U<<((pin*4)+1))|(1U<<(pin*4))|(1U<<((pin*4)+2))); GPIOC->CRH|=(1U<<((pin*4)+3));}// set Mode to 00' set CFN to 10,
			else if (port==3) { GPIOB->CRH &=~((1U<<((pin*4)+1))|(1U<<(pin*4))|(1U<<((pin*4)+2))); GPIOC->CRH|=(1U<<((pin*4)+3));}// set Mode to 00, set CFN to 10,
			else if (port==4) { GPIOC->CRH &=~((1U<<((pin*4)+1))|(1U<<(pin*4))|(1U<<((pin*4)+2))); GPIOC->CRH|=(1U<<((pin*4)+3));}//set Mode to 00, set CFN to 10, 
	}
}


 void digitalWrite (uint32_t port,uint32_t pin, uint32_t state)
{
	if(state==1) //If mode is high
	{
	if (port==2) GPIOA->BSRR=(1<<pin);
	if (port==3) GPIOB->BSRR=(1<<pin);
	if (port==4) GPIOC->BSRR=(1<<pin);
	}
	if(state==0) //If mode is loww
	{
	if (port==2) GPIOA->BSRR=(1<<(pin+16));
	if (port==3) GPIOB->BSRR=(1<<(pin+16));
	if (port==4) GPIOC->BSRR=(1<<(pin+16));
	}		 
}

 int digitalRead(int port, int pin)
		
	{
		int state;
		
		switch (port)
		{
			case 2: state=(GPIOA->IDR & (1U<<pin));	break;
			case 3: state=(GPIOB->IDR & (1U<<pin));	break;
			case 4: state=(GPIOC->IDR & (1U<<pin));	break;	
		}
		
		if (state>0) return 1;
		else if (state<=0) return 0;
	
	}
	
	
	 void analogWrite(uint32_t port,uint32_t pin, uint32_t mode)
	 {
		 
		 
		 
		 
		 
		 
		 	 
		 
	 }





