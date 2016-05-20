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
  
  //delayMicroseconds(4);

  for ( int i = 14; i <= 19; i++ )
  {
    if ( analogRead(i) > 100 )
    {
      Serial.print("In ");
      Serial.print(i);
      Serial.print(" :");
      Serial.println(analogRead(i));
      instrument.play(i-14);
    }
  }
  
}



