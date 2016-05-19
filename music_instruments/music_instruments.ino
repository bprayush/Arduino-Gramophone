#include "pitch.h"
#include "instruments.h"

int sensor=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(14, INPUT);
}

void loop() {

  Instruments instrument(2, 3);

  delay(100);
  for ( int i = 14; i <= 19; i++ )
  {
    Serial.print("Pin: ");
    Serial.print(i);
    Serial.print(" ");
    Serial.println(analogRead(i));
    if( analogRead(i) > 500 )
      instrument.play(i-14);
      
  }
  
}



