#include "instruments.h"

int sensor=0;
int scale=1;
int octave=1;
int threshold=0;
int average = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=14; i<=19; i++)
    pinMode(i, INPUT);

  for ( int i=14; i<=19; i++ )
    threshold+=analogRead(i);

  threshold = threshold / 6;
  Serial.println(threshold);
  delay(1000);

  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(6, OUTPUT);
  
}

int a[6] = {0};
int meanDeviation = 0;

void loop() {

  if ( isKeyPressed(2) )
    selectScale();
  if ( isKeyPressed(3) )
    selectOctave();

  Instruments instrument(scale, octave); 
  
  //delayMicroseconds(4);
  /*
  for ( int i = 14; i <= 19; i++ )
  {
    //use 100;
    if ( analogRead(i) > 150)
    {
      Serial.print("In ");
      Serial.print(i);
      Serial.print(" :");
      Serial.println(analogRead(i));
      instrument.play(i-14);
    }
  }
  */

  for ( int i = 14; i <= 19; i++ )
  {
    a[i-14] = analogRead(i);
    meanDeviation = abs(a[i-14] - threshold);
    if( meanDeviation > 100 )
    {
      Serial.print("In ");
      Serial.print(i);
      Serial.print(" :");
      Serial.println(meanDeviation);
      instrument.play(i-14);
    }
  }
  
  
}


//Scale selector code
void selectScale(){
  Serial.print("Scale: ");
  Serial.println(scale);
  if( scale == 3)
  {
    scale = 1;
  }else if( scale == 1)
  {
    scale = 2;
  }else if( scale == 2)
  {
    scale = 3;
  }
}


//octave selector code
void selectOctave(){
  Serial.print("Octave: ");
  Serial.println(octave);
  if(  octave == 3 )
  {
    octave = 1;
  }else if( octave == 1)
  {
    octave = 2;
  }else if( octave == 2)  
  {
    octave = 3;
  }  
}

char isKeyPressed(char pinNumber)
{
   if(digitalRead(pinNumber)==HIGH)
  {
    delay(20);
    while(digitalRead(pinNumber)==HIGH)
      delay(20);
    delay(80);
    return 1;
    //Serial.println("switch pressed");
  }
  return 0;
}


