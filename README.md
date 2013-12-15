# Sphero 6x10 WS2801 RGB LED Display


## **Display Setup**

The LED matrix is setup with X horizontal, Y vertical.  
(1,1) in the left, bottom corner.  (maxX, maxY in the top right).  

The lights are strung with i=1 being in the bottom right and weaving up and down
until it reaches numberLEDs. 

In this particular setup, we have 60 Total.  maxX = 6 and maxY = 10;  
        

## **Wire Pinouts**

* RED	- VCC (5V DC)
* YELLOW - GND (Connect to both supply and Arduino)
* GREEN  - DATA
* BLUE   - CLOCK
																						   
## PJM - design

DisplayMatrix abstracts either a WS2801 backend or a "test" backend
GLDisplayMatrix is a test backend written in SFML
WS2801DisplayMatrix will wrap WS2801

I expose a raw byte buffer for faster blitting when desired
I expose a vsync callback function to be called at some predetermined refresh rate																	   
