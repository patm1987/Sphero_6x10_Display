# Sphero 6x10 WS2801 RGB LED Display

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

                                                                                               
