#include "SPI.h"
#include "WS2801.h"

/*****************************************************************************
The LED matrix is setup with X horizontal, Y vertical.  
(1,1) in the left, bottom corner.  (maxX, maxY in the top right).  

The lights are strung with i=1 being in the bottom right and weaving up and down
until it reaches numberLEDs.  

                         _   _   _
    i = numberLEDs --.> | |_| |_| | <.- i=1


 WIRE PINOUTS:
             RED    - VCC (5V DC)
             YELLOW - GND (Connect to both supply and Arduino)
             GREEN  - DATA
             BLUE   - CLOCK
             
*****************************************************************************/

int numberLEDs = 60;
int maxX = 6;
int maxY = 10;

int dataPin = 3;     // Green
int clockPin = 2;    // Blue

WS2801 SpheroDisplay = WS2801(numberLEDs, dataPin, clockPin);

void setup() {
  SpheroDisplay.begin();
  SpheroDisplay.show();
}


void loop() {
  
  //********************* -  Simple XY Plotting
  /** 
  Sphero_6x10matrixDisplay.setPixelColor(xyPlot(6,10), Color(random(255), random(255), random(255)));
  SpheroDisplay.show();
  delay(200);
  **/


  //********************* -  Color Wipe Examples
  /**
  colorWipeUniform(Color(255, 0, 0), 1);
  delay(1000);
  colorWipe(Color(0, 255, 255), 1);
  delay(1000);
  **/
  
  
  //********************* -  Rainbow Examples
  /** 
     rainbow(9);
     rainbowCycle(10);
  **/
  
  //********************* -  Other Examples
  // hop(25);

}




/*************************************************************
                      Display Routines 
*************************************************************/

void rainbow(uint8_t wait) {
  int i, j;
   
  for (j=0; j < 256; j++) {     // 3 cycles of all 256 colors in the wheel
    for (i=0; i < SpheroDisplay.numPixels(); i++) {
      SpheroDisplay.setPixelColor(i, Wheel( (i + j) % 255));
    }  
    SpheroDisplay.show();   
    delay(wait);
  }
}

// makes the rainbow wheel equally distributed along the chain
void rainbowCycle(uint8_t wait) {
  int i, j;
  
  for (j=0; j < 256 * 5; j++) {     // 5 cycles of all 25 colors in the wheel
    for (i=0; i < SpheroDisplay.numPixels(); i++) {
      SpheroDisplay.setPixelColor(i, Wheel( ((i * 256 / SpheroDisplay.numPixels()) + j) % 256) );
    }  
    SpheroDisplay.show();   
    delay(wait);
  }
}

// Hop around every other LED, evenly colored along the entire chain
void hop(uint8_t wait) {
  int i,j;
    for (i=0; i < SpheroDisplay.numPixels(); i+=2){
      SpheroDisplay.setPixelColor(i,Wheel( ((i * 256 / SpheroDisplay.numPixels()) + i) % 256));
      if(i>=2)SpheroDisplay.setPixelColor(i-2,Color(0, 0, 0));
      SpheroDisplay.show();
      delay(wait);
    }
    colorWipeUniform(Color(0,0,0),0);
}

// wipe the entire chain one by one.
void colorWipe(uint32_t c, uint8_t wait) {
  int i;
  
  for (i=0; i < SpheroDisplay.numPixels(); i++) {
      SpheroDisplay.setPixelColor(i, c);
      SpheroDisplay.show();
      delay(wait);
  }
}

// wipe the entire chain, COLOR then wait time.
void colorWipeUniform(uint32_t c, uint8_t wait) {
  int i;
  
  for (i=0; i < SpheroDisplay.numPixels(); i++) {
      SpheroDisplay.setPixelColor(i, c);
  }
  SpheroDisplay.show();
  delay(wait);
}

/*************************************************************
                       Helper functions 
*************************************************************/

int xyPlot(uint8_t X, uint8_t Y)
{
  int i = 0;
  i = ((X % 2) ? (maxX*maxY+1)-((X-1)*maxY+Y) : (maxX*maxY+1)-(X*maxY-(Y-1)));
  return i-1;
}

// Create a 24 bit color value from R,G,B
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}

//Input a value 0 to 255 to get a color value.
//The colours are a transition r - g -b - back to r
uint32_t Wheel(byte WheelPos)
{
  if (WheelPos < 85) {
   return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
   WheelPos -= 85;
   return Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170; 
   return Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
