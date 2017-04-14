/*
this program taken from arduino Example.
  modified by By Ivan Isakov & Katerina Loschinina

  This code used to control two digital potentiometers
  MCP4151-103E connected to arduino Board
  
  /// 1st potentiometr
  CS >>> D10
  SCLK >> D13
  SDI  >>> D11
  PA0 TO VCC
  PBO TO GND
  PW0 TO led with resistor 100ohm.
  
  /// 2nd potentiometr
  CS >>> D10
  SCLK >> D13
  SDI  >>> D11
  PA0 TO VCC
  PBO TO GND
  PW0 TO led with resistor 100ohm.
*/

#include <SPI.h>


byte address = 0x00;
int CS_1 = 10;
int CS_2 = 9;

void setup()
  {
    pinMode(CS_1, OUTPUT);
    pinMode(CS_2, OUTPUT);
    SPI.begin();
  }

void loop()
  {
    for (int i = 0; i <= 255; i++)
       {
        digitalPotWrite(i, CS_1);
        digitalPotWrite(i, CS_2);
        delay(10);
       }
    delay(500);
    for (int i = 255; i >= 0; i--)
      {
        digitalPotWrite(i, CS_1);
        digitalPotWrite(i, CS_2);
        delay(10);
      }
  }

int digitalPotWrite(int value, int CS)
  {
    digitalWrite(CS, LOW);
    SPI.transfer(address);
    SPI.transfer(value);
    digitalWrite(CS, HIGH);
  }
