#include "pitch.h"

/*
 * 
 * Constructor takes 2 parameters(scale and octave)
 * Pin 6 as speaker output
 * sensor = the input sensor number (start from 0 ends at 7)
 * octave 1-3
 * scale 1-3
 * 
 */

class Instruments {

  private:
    int scale;
    int octave;
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

  if ( octave == 1 )
  {

    //C-scale
    if ( scale == 1 )
    {
      int note[] = {
        NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3
      };

      tone(6, note[sensor], 500);
    }

    //D-scale
    else if ( scale == 2 )
    {
      int note[] = {
        NOTE_D3, NOTE_E3, NOTE_FS3, NOTE_G3, NOTE_A3, NOTE_B3, NOTE_CS3
      };

      tone(6, note[sensor], 500);
    }

    //G-scale
    else if ( scale == 3 )
    {
      int note[] = {
        NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_FS3
      };

      tone(6, note[sensor], 500);
    }
  }

  else if ( octave == 2 )
  {
    //C-scale
    if ( scale == 1 )
    {
      int note[] = {
        NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4
      };

      tone(6, note[sensor], 500);
    }

    //D-scale
    else if ( scale == 2 )
    {
      int note[] = {
        NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_CS4
      };

      tone(6, note[sensor], 500);
    }

    //G-scale
    else if ( scale == 3 )
    {
      int note[] = {
        NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_FS4
      };

      tone(6, note[sensor], 500);
    
    } 
  }


  else if ( octave == 3 )
  {
    //C-scale
    if ( scale == 1 )
    {
      int note[] = {
        NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5
      };

      tone(6, note[sensor], 500);
    }

    //D-scale
    else if ( scale == 2 )
    {
      int note[] = {
        NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_CS5
      };

      tone(6, note[sensor], 500);
    }

    //G-scale
    else if ( scale == 3 )
    {
      int note[] = {
        NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_FS5
      };

      tone(6, note[sensor], 500);
    
    } 
  }

}
