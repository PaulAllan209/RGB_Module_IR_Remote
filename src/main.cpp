#include <Arduino.h>
#include <IRremote.hpp>

//define sensor pin
const int IR_RECEIVE_PIN = 4;

//RGB pins
int red = 6;
int green = 10;
int blue = 3;

//LED output values
int r = 0;
int g = 0;
int b = 0;

//togglestates
// color cycle = 0 on remote button
int cycle_togglestate = 0;
// red = 1
// cyan = 2
// white = 3
// yellow = 4
// blue = 5
// pink = 6
// green = 7
int color_mode_togglestate = 0;

//speed of delay
const int delay_speed = 5;


//Function for decoding IR signal from IR receiver and detects whether what case to run
void decoding_signal(){
  if (IrReceiver.decode()){
    switch(IrReceiver.decodedIRData.decodedRawData){

      case 2907897600: //#8 on remote. Cycle mode
        if (cycle_togglestate==0){
          color_mode_togglestate = 0;
          cycle_togglestate = 1;
        }
        else {
          r = 0;
          g = 0;
          b = 0;
          analogWrite(red,r);
          analogWrite(green,g);
          analogWrite(blue,b);
          cycle_togglestate = 0;
        }
        break;

      case 4077715200: //#1 on remote. Red mode
        if (color_mode_togglestate != 1){ 
          cycle_togglestate = 0;
          color_mode_togglestate = 1;
        }
        else {
          r = 0;
          g = 0;
          b = 0;
          analogWrite(red,r);
          analogWrite(green,g);
          analogWrite(blue,b);
          color_mode_togglestate = 0;
        }
        break;

      case 3877175040: //#2 on remote. Cyan mode
        if (color_mode_togglestate != 2){ 
          cycle_togglestate = 0;
          color_mode_togglestate = 2;
        }
        else {
          r = 0;
          g = 0;
          b = 0;
          analogWrite(red,r);
          analogWrite(green,g);
          analogWrite(blue,b);
          color_mode_togglestate = 0;
        }
        break;

      case 2707357440: //#3 on remote. White mode
        if (color_mode_togglestate != 3){ 
          cycle_togglestate = 0;
          color_mode_togglestate = 3;
        }
        else {
          r = 0;
          g = 0;
          b = 0;
          analogWrite(red,r);
          analogWrite(green,g);
          analogWrite(blue,b);
          color_mode_togglestate = 0;
        }
        break;

      case 4144561920: //#4 on remote. Yellow mode
        if (color_mode_togglestate != 4){ 
          cycle_togglestate = 0;
          color_mode_togglestate = 4;
        }
        else {
          r = 0;
          g = 0;
          b = 0;
          analogWrite(red,r);
          analogWrite(green,g);
          analogWrite(blue,b);
          color_mode_togglestate = 0;
        }
        break;

      case 3810328320: //#5 on remote. Blue mode
        if (color_mode_togglestate != 5){ 
          cycle_togglestate = 0;
          color_mode_togglestate = 5;
        }
        else {
          r = 0;
          g = 0;
          b = 0;
          analogWrite(red,r);
          analogWrite(green,g);
          analogWrite(blue,b);
          color_mode_togglestate = 0;
        }
        break;

      case 2774204160: //#6 on remote. Pink mode
        if (color_mode_togglestate != 6){ 
          cycle_togglestate = 0;
          color_mode_togglestate = 6;
        }
        else {
          r = 0;
          g = 0;
          b = 0;
          analogWrite(red,r);
          analogWrite(green,g);
          analogWrite(blue,b);
          color_mode_togglestate = 0;
        }
        break;

      case 3175284480: //#7 on remote. Green mode
        if (color_mode_togglestate != 7){ 
          cycle_togglestate = 0;
          color_mode_togglestate = 7;
        }
        else {
          r = 0;
          g = 0;
          b = 0;
          analogWrite(red,r);
          analogWrite(green,g);
          analogWrite(blue,b);
          color_mode_togglestate = 0;
        }
        break;
    }
  }
  IrReceiver.resume();
}


void cycleMode() {
  decoding_signal();
  if (cycle_togglestate==1){
    color_mode_togglestate = 0;
    for (r = 0, g = 0, b = 0; r<255 && cycle_togglestate==1; r++){ //red Fade in
      decoding_signal();
      analogWrite(red, r);
      analogWrite(green, g);
      analogWrite(blue, b);
      decoding_signal();
      delay(delay_speed);
    }
      for (r = 255, g = 0, b = 0; r>0 && cycle_togglestate==1;r--){ //red fade out
      decoding_signal();
      analogWrite(red, r);
      analogWrite(green, g);
      analogWrite(blue, b);
      decoding_signal();
      delay(delay_speed);
    }


    for(r = 0, g = 0, b = 0; g<255 && b<255 && cycle_togglestate==1; g++, b++){ //cyan fade in 
      decoding_signal();
      analogWrite(red, r);
      analogWrite(green, g);
      analogWrite(blue, b);
      decoding_signal();
      delay(delay_speed);
    }
    for(r = 0, g = 255, b = 255; g>0 && b>0 && cycle_togglestate==1; g--, b--){ //cyan fade out
      decoding_signal();
      analogWrite(red, r);
      analogWrite(green, g);
      analogWrite(blue, b);
      decoding_signal();
      delay(delay_speed);
    }


    for(r = 0, g = 0, b = 0; r<255 && g<255 && b<255 && cycle_togglestate==1; r++, g++, b++){ //white fade in 
      decoding_signal();
      analogWrite(red, r);
      analogWrite(green, g);
      analogWrite(blue, b);
      decoding_signal();
      delay(delay_speed);
    }
      for(r = 255, g = 255, b = 255; r>0 && g>0 && b>0 && cycle_togglestate==1; r--, g--, b--){ //white fade out
      decoding_signal();
      analogWrite(red, r);
      analogWrite(green, g);
      analogWrite(blue, b);
      decoding_signal();
      delay(delay_speed);
    }


    for(r = 0, g = 0, b = 0; r<255 && g<255 && cycle_togglestate==1; r++, g++){ //yellow fade in 
      decoding_signal();
      analogWrite(red, r);
      analogWrite(green, g);
      analogWrite(blue, b);
      decoding_signal();
      delay(delay_speed);
    }
    for(r = 255, g = 255, b = 0; r>0 && g>0 && cycle_togglestate==1; r--, g--){ //yellow fade out
      decoding_signal();
      analogWrite(red, r);
      analogWrite(green, g);
      analogWrite(blue, b);
      decoding_signal();
      delay(delay_speed);
    }


    for(r = 0, g = 0, b = 0; b<255 && cycle_togglestate==1; b++){ //blue fade in
      decoding_signal();
      analogWrite(red, r);
      analogWrite(green, g);
      analogWrite(blue, b);
      decoding_signal();
      delay(delay_speed);
    }
    for(r = 0, g = 0, b = 255; b>0 && cycle_togglestate==1; b--){ //blue fade out
      decoding_signal();
      analogWrite(red, r);
      analogWrite(green, g);
      analogWrite(blue, b);
      decoding_signal();
      delay(delay_speed);
    }

    for(r = 0, g = 0, b = 0; r<255 && b<255 && cycle_togglestate==1; r++, b++){ //pink fade in 
      decoding_signal();
      analogWrite(red, r);
      analogWrite(green, g);
      analogWrite(blue, b);
      decoding_signal();
      delay(delay_speed);
    }
    for(r = 255, g = 0, b = 255; r>0 && b>0 && cycle_togglestate==1; r--, b--){ //pink fade out
      decoding_signal();
      analogWrite(red, r);
      analogWrite(green, g);
      analogWrite(blue, b);
      decoding_signal();
      delay(delay_speed);
    }


    for(r = 0, g = 0, b = 0; g<255 && cycle_togglestate==1; g++){ //green fade in
      decoding_signal();
      analogWrite(red, r);
      analogWrite(green, g);
      analogWrite(blue, b);
      decoding_signal();
      delay(delay_speed);
    }
    for(r = 0, g = 255, b = 0; g>0 && cycle_togglestate==1; g--){ //green fade out
      decoding_signal();
      analogWrite(red, r);
      analogWrite(green, g);
      analogWrite(blue, b);
      decoding_signal();
      delay(delay_speed);
    }
  }
}


void indivColorMode(){
  decoding_signal();
  if (color_mode_togglestate==1){ //red mode
    for (r = 0, g = 0, b = 0; r<255 && color_mode_togglestate==1; r++){ //red Fade in
    decoding_signal();
    analogWrite(red, r);
    analogWrite(green, g);
    analogWrite(blue, b);
    decoding_signal();
    delay(delay_speed);
    }
    for (r = 255, g = 0, b = 0; r>0 && color_mode_togglestate==1;r--){ //red fade out
    decoding_signal();
    analogWrite(red, r);
    analogWrite(green, g);
    analogWrite(blue, b);
    decoding_signal();
    delay(delay_speed);
    }
  }

  else if (color_mode_togglestate==2){ //cyan mode
    for (r = 0, g = 0, b = 0; g<255 && b<255 && color_mode_togglestate==2; g++, b++){ //cyan Fade in
    decoding_signal();
    analogWrite(red, r);
    analogWrite(green, g);
    analogWrite(blue, b);
    decoding_signal();
    delay(delay_speed);
    }
    for (r = 0, g = 255, b = 255; g>0 && b>0 && color_mode_togglestate==2;g--, b--){ //cyan fade out
    decoding_signal();
    analogWrite(red, r);
    analogWrite(green, g);
    analogWrite(blue, b);
    decoding_signal();
    delay(delay_speed);
    }  
  }

  else if (color_mode_togglestate==3){ //white mode
    for (r = 0, g = 0, b = 0;r<255 && g<255 && b<255 && color_mode_togglestate==3; r++, g++, b++){ //white Fade in
    decoding_signal();
    analogWrite(red, r);
    analogWrite(green, g);
    analogWrite(blue, b);
    decoding_signal();
    delay(delay_speed);
    }
    for (r = 255, g = 255, b = 255; r>0 && g>0 && b>0 && color_mode_togglestate==3;r--, g--, b--){ //white fade out
    decoding_signal();
    analogWrite(red, r);
    analogWrite(green, g);
    analogWrite(blue, b);
    decoding_signal();
    delay(delay_speed);
    }  
  }

  else if (color_mode_togglestate==4){ //Yellow mode
    for (r = 0, g = 0, b = 0;r<255 && g<255 && color_mode_togglestate==4; r++, g++){ //Yellow Fade in
    decoding_signal();
    analogWrite(red, r);
    analogWrite(green, g);
    analogWrite(blue, b);
    decoding_signal();
    delay(delay_speed);
    }
    for (r = 255, g = 255, b = 0; r>0 && g>0 && color_mode_togglestate==4;r--, g--){ //Yellow fade out
    decoding_signal();
    analogWrite(red, r);
    analogWrite(green, g);
    analogWrite(blue, b);
    decoding_signal();
    delay(delay_speed);
    }  
  }

  else if (color_mode_togglestate==5){ //Blue mode
    for (r = 0, g = 0, b = 0;b<255 && color_mode_togglestate==5; b++){ //Blue Fade in
    decoding_signal();
    analogWrite(red, r);
    analogWrite(green, g);
    analogWrite(blue, b);
    decoding_signal();
    delay(delay_speed);
    }
    for (r = 0, g = 0, b = 255; b>0 && color_mode_togglestate==5; b--){ //Blue fade out
    decoding_signal();
    analogWrite(red, r);
    analogWrite(green, g);
    analogWrite(blue, b);
    decoding_signal();
    delay(delay_speed);
    }  
  }

  else if (color_mode_togglestate==6){ //Pink mode
    for (r = 0, g = 0, b = 0;r<255 && b<255 && color_mode_togglestate==6; r++, b++){ //Pink Fade in
    decoding_signal();
    analogWrite(red, r);
    analogWrite(green, g);
    analogWrite(blue, b);
    decoding_signal();
    delay(delay_speed);
    }
    for (r = 255, g = 0, b = 255; r>0 && b>0 && color_mode_togglestate==6; r--, b--){ //Pink fade out
    decoding_signal();
    analogWrite(red, r);
    analogWrite(green, g);
    analogWrite(blue, b);
    decoding_signal();
    delay(delay_speed);
    }  
  }

  else if (color_mode_togglestate==7){ //Green mode
    for (r = 0, g = 0, b = 0; g<255 && color_mode_togglestate==7; g++){ //Green Fade in
    decoding_signal();
    analogWrite(red, r);
    analogWrite(green, g);
    analogWrite(blue, b);
    decoding_signal();
    delay(delay_speed);
    }
    for (r = 0, g = 255, b = 0; g>0 && color_mode_togglestate==7; g--){ //Green fade out
    decoding_signal();
    analogWrite(red, r);
    analogWrite(green, g);
    analogWrite(blue, b);
    decoding_signal();
    delay(delay_speed);
    }  
  }
}

void setup() {

//Enable the IR receiver
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver

  
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);

  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);

}


void loop() {
  decoding_signal();
  cycleMode();
  indivColorMode();
  IrReceiver.resume();
}
