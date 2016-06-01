#include "instruments.h"

int scale=1;
int octave=1;
int threshold=0;
int a[6] = {0};
int meanDeviation = 0;



//Initial setup
void setup() {
  
  Serial.begin(9600);

  //Initializing input pins
  for(int i=14; i<=19; i++)
    pinMode(i, INPUT);

  //getting the threshold value
  for ( int i=14; i<=19; i++ )
    threshold+=analogRead(i);

  threshold = threshold / 6;

  //Serial print the threshold
  Serial.print("Threshold= ");
  Serial.println(threshold);
  delay(1000);

  //Initialize digital pins for switch input
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  
}

void loop() {

  //Check input from switches
  if ( isKeyPressed(2) )
    selectScale();
  if ( isKeyPressed(3) )
    selectOctave();

  //Constructor and initializing the scales and octaves
  Instruments instrument(scale, octave); 

  //Read and send the sensor number to instrument class
  for ( int i = 14; i <= 19; i++ )
  {
    a[i-14] = analogRead(i);
    meanDeviation = abs(a[i-14] - threshold);

    if( threshold > 80 )
    {
      //Code for day light or bright light
      if( meanDeviation > 100 )
      {
        Serial.print("In ");
        Serial.print(i);
        Serial.print(" :");
        Serial.println(meanDeviation);
        instrument.play(i-14);
      }

    }else{
      //Code for low lighting condition
      if( meanDeviation > 30 )
      {
        Serial.print("In ");
        Serial.print(i);
        Serial.print(" :");
        Serial.println(meanDeviation);
        instrument.play(i-14);
      }
    
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

//Filter for input
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


