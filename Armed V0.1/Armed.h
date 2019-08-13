
#ifndef __Armed__h
#define __Armed__h

/////dependencies/////
#include "delayMS.h"
#include "Serial.h"
#include "stm32f10x.h"


/* ---COMING SOON---
#include "Wire.h" --- I2c and SPI
#include "PWM.h"  --- read and write PWM
#include "LiquidCrystal_I2C.h"  --- 12C lcd
#include "Nextion.h" --- Nextion Touch screen disply
#include ""
*/

#define HIGH 1
#define LOW  0
#define OUTPUT 1
#define INPUT 0
#define PORT_A 2
#define PORT_B 3
#define PORT_C 4

void pinMode(uint32_t port,uint32_t pin, uint32_t mode);
void digitalWrite (uint32_t port,uint32_t pin, uint32_t state);
void analogWrite(uint32_t port,uint32_t pin, uint32_t mode);
int  digitalRead(int port, int pin);


#endif
