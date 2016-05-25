#include "instruments.h"

int sensor=0;
int scale=1;
int octave=1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=14; i<=19; i++)
    pinMode(i, INPUT);

  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  
}

void loop() {

  attachInterrupt(digitalPinToInterrupt(5), selectScale, HIGH);
  attachInterrupt(digitalPinToInterrupt(6), selectOctave, HIGH);  

  Instruments instruments(scale, octave); 
  
  //delayMicroseconds(4);

  for ( i = 14; i <= 19; i++ )
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


//Scale selector code
void selectScale(){

  if( scale == 0 || scale == 3)
  {
    scale = 1;
    delay(200);
  }else if( scale == 1)
  {
    scale = 2;
    delay(200);
  }else if( scale == 2)
  {
    scale = 3;
    delay(200);
  }
}


//octave selector code

void selectOctave(){
  if( octave == 0 || octave == 3 )
  {
    octave = 1;
    delay(200);
  }else if( octave == 1)
  {
    octave = 2;
    delay(200);
  }else if( octave == 2)  
  {
    octave = 3;
    delay(200);
  }  
}



