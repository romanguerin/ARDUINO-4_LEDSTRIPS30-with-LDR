/* 
 * Hardware & Physical Computing Arduino Code
 * Artificial Photosyntesis Project 
 * 15-02-2021
 * Lieke, Tobias, Roman
 */

// MultiArrays - see https://github.com/FastLED/FastLED/wiki/Multiple-Controller-Examples for more info on
// different pins, each strip getting its own CRGB array to be played with

#include <FastLED.h>

//define leds
#define NUM_LEDS_PER_STRIP 30
CRGB firstLeds[NUM_LEDS_PER_STRIP];
CRGB secondLeds[NUM_LEDS_PER_STRIP];
CRGB thirthLeds[NUM_LEDS_PER_STRIP];
CRGB fourthLeds[NUM_LEDS_PER_STRIP];

//init array for color
CRGB myArray[11];

// init max lights each
int maxLight1, maxLight2, maxLight3, maxLight4;

void setup() {
  //Serial.begin(9600); //sets serial port for communication

  //set max light + 10 for each ldr
  maxLight1 = analogRead(A1) + 10;
  maxLight2 = analogRead(A2) + 10;
  maxLight3 = analogRead(A3) + 10;
  maxLight4 = analogRead(A4) + 10;
  
  //put colors in array ([0] is buggy)
  //color goes from green to red with the Fast.Led crgb library 
  myArray[1]=CRGB::DarkGreen;
  myArray[2]=CRGB::Green;
  myArray[3]=CRGB::LawnGreen;
  myArray[4]=CRGB::GreenYellow;
  myArray[5]=CRGB::Yellow;
  myArray[6]=CRGB::Orange;
  myArray[7]=CRGB::DarkOrange;
  myArray[8]=CRGB::OrangeRed;
  myArray[9]=CRGB::Red;
  myArray[10]=CRGB::DarkRed;
  
  // tell FastLED there's 30 NEOPIXEL leds on pin 3
  FastLED.addLeds<NEOPIXEL, 3>(firstLeds, NUM_LEDS_PER_STRIP);

  // tell FastLED there's 30 NEOPIXEL leds on pin 5
  FastLED.addLeds<NEOPIXEL, 5>(secondLeds, NUM_LEDS_PER_STRIP);

  // tell FastLED there's 30 NEOPIXEL leds on pin 9
  FastLED.addLeds<NEOPIXEL, 9>(thirthLeds, NUM_LEDS_PER_STRIP);
  //FastLED.setBrightness(50);

  // tell FastLED there's 30 NEOPIXEL leds on pin 11
  FastLED.addLeds<NEOPIXEL, 11>(fourthLeds, NUM_LEDS_PER_STRIP);
}

void loop() {
  //led chase with 100 mili delay
  Chase(100);
}

void Chase(int SpeedDelay) {
  for (int j=0; j<15; j++) {  //do .. cycles of chasing
    for (int q=0; q < 10; q++) {
      for (int i=0; i < NUM_LEDS_PER_STRIP; i=i+10) {

        // give first ledstrip ldr remap from array
        int s1 = map(analogRead(A1),0,160,9,1);  //yellow - green   ldr 
        //send variables to ledstip
        firstStrip(j,i,q, s1);

        // give second ledstrip ldr remap from array
        int s2 = map(analogRead(A2),0,10,9,1);   //blue - purple    ldr
        //send variables to ledstip
        secondStrip(j,i,q, s2);

        // give thirth ledstrip ldr remap from array
        int s3 = map(analogRead(A3),0,20,9,1);   //orange - red     ldr
        //send variables to ledstip
        thirthStrip(j,i,q, s3);

        // give fourth ledstrip ldr remap from array
        int s4 = map(analogRead(A4),0,10,9,1);   //Black - Brown    ldr
        //send variables to ledstip
        fourthStrip(j,i,q, s4);  

        // set brigthnes just to 33 -> pc will not accept higher then 50
        FastLED.setBrightness(33);
      }
      FastLED.show();
      delay(SpeedDelay);
    }
  }
}

/* 
 * for each indivual ledstrip:
 * individual strip array color go down
 * Cyan colors goes up
 * array color are used
 * Black will remove color
*/

void firstStrip(int c, int a ,int b, int p) {
  firstLeds[28-(a+b)] = myArray[p];  
  firstLeds[29-(a+b)] = myArray[p+1];  
  firstLeds[30-(a+b)] = CRGB::Black;  
  firstLeds[c] = CRGB::Cyan;          
  firstLeds[15+c] = CRGB::Cyan;
}

void secondStrip(int c, int a ,int b, int p){
  secondLeds[28-(a+b)] = myArray[p];
  secondLeds[29-(a+b)] = myArray[p+1];
  secondLeds[30-(a+b)] = CRGB::Black;
  secondLeds[c] = CRGB::Cyan;
  secondLeds[15+c] = CRGB::Cyan;
}

void thirthStrip(int c, int a ,int b, int p){
  thirthLeds[28-(a+b)] = myArray[p];
  thirthLeds[29-(a+b)] = myArray[p+1];
  thirthLeds[30-(a+b)] = CRGB::Black;
  thirthLeds[c] = CRGB::Cyan;
  thirthLeds[15+c] = CRGB::Cyan;
}

void fourthStrip(int c, int a ,int b, int p){
  fourthLeds[28-(a+b)] = myArray[p];
  fourthLeds[29-(a+b)] = myArray[p+1];
  fourthLeds[30-(a+b)] = CRGB::Black;
  fourthLeds[c] = CRGB::Cyan;
  fourthLeds[15+c] = CRGB::Cyan;
}


 
