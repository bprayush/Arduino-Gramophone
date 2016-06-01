#include "pitch.h"

/*
 * 
 * Constructor takes 2 parameters(scale and octave)
 * Pin 9, 10 as speaker output
 * sensor = the input sensor number (start from 0 ends at 7)
 * octave 1-3
 * scale 1-3
 * 
 */

class Instruments {

  private:
    int scale;
    int octave;
    int duration=200;
    void setScale(int s);
    void setOctave(int o);


  public:
    void play(int sensor);
    Instruments(int s, int o);

};

//Constructor for scale and octave
Instruments::Instruments(int s, int o) {

  setScale(s);
  setOctave(o);

}

void Instruments::setScale(int s) {
  scale = s;
}

void Instruments::setOctave(int o) {
  octave = o;
}

void Instruments::play( int sensor ) {


//3rd octave
  if ( octave == 1 )
  {

    //C-scale
    if ( scale == 1 )
    {
      int note[] = {
        NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5
      };

      tone( 9, note[sensor], duration);
    }

    //D-scale
    else if ( scale == 2 )
    {
      int note[] = {
        NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_CS6
      };

      tone( 9, note[sensor], duration);
    }

    //G-scale
    else if ( scale == 3 )
    {
      int note[] = {
        NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_FS6
      };

      tone( 9, note[sensor], duration);
    }
  }


//4th octave
  else if ( octave == 2 )
  {
    //C-scale
    if ( scale == 1 )
    {
      int note[] = {
        NOTE_C6, NOTE_D6, NOTE_E6, NOTE_F6, NOTE_G6, NOTE_A6, NOTE_B6
      };

      tone( 9, note[sensor], duration);
    }

    //D-scale
    else if ( scale == 2 )
    {
      int note[] = {
        NOTE_D6, NOTE_E6, NOTE_FS6, NOTE_G6, NOTE_A6, NOTE_B6, NOTE_CS7
      };

     tone( 9, note[sensor], duration);
    }

    //G-scale
    else if ( scale == 3 )
    {
      int note[] = {
        NOTE_G6, NOTE_A6, NOTE_B6, NOTE_C7, NOTE_D7, NOTE_E7, NOTE_FS7
      };

      tone( 9, note[sensor], duration);
    
    } 
  }



//5th octave
  else if ( octave == 3 )
  {
    //C-scale
    if ( scale == 1 )
    {
      int note[] = {
        NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, NOTE_G7, NOTE_A7, NOTE_B7
      };

      tone( 9, note[sensor], duration);
    }

    //D-scale
    else if ( scale == 2 )
    {
      int note[] = {
        NOTE_D7, NOTE_E7, NOTE_FS7, NOTE_G7, NOTE_A7, NOTE_B7, NOTE_CS8
      };

      tone( 9, note[sensor], duration);
    }

    //G-scale
    else if ( scale == 3 )
    {
      int note[] = {
        NOTE_E7, NOTE_FS7, NOTE_G7, NOTE_A7, NOTE_B7, NOTE_C8, NOTE_D8 
      };

      tone( 9, note[sensor], duration);
    
    } 
  }

}
