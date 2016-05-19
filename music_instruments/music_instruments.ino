#include "instruments.h"

int sensor=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=14; i<=19; i++)
    pinMode(i, INPUT);
}

void loop() {

  Instruments instrument(3, 3);
  
  delay(100);
  if( analogRead(14) > 500 )
  {
      Serial.println(analogRead(14));
      instrument.play(0);
  }

  
  if( analogRead(15) > 500 )
  {
      instrument.play(1);
      Serial.println(analogRead(15));
  }

  
  if( analogRead(16) > 500 )
  {
    instrument.play(2);
    Serial.println(analogRead(16));
  }

  
  if( analogRead(17) > 500 )
  {
    instrument.play(3);
    Serial.println(analogRead(17));
  }

  
  if( analogRead(18) > 500 )
  {
    instrument.play(4);
    Serial.println(analogRead(18));
  }

  
  if( analogRead(19) > 500 )
  {
    instrument.play(5);
    Serial.println(analogRead(19));
  }
  
}



