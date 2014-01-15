/*-------------------------------------------------------------------------------------------
  demo of display text
  
  loovee
  2013-7-10
  
  note: if you use an Arduin UNO, Seeeduino 3.0 (any board that use Atmega 328P or 32U4) 
        you should insert an SD card if you want to use this demo
        if you use a Arduino Mega(any board that use Atmega1280 or Atmega2560), you neen't
        insert an SD card for this demo
-------------------------------------------------------------------------------------------*/ 

#include <ePaper.h>
#include <SPI.h>
#include <SD.h>
#include "GT20L16_drive.h"
#include "picture.h"

#define SCREEN_SIZE 200                 // choose screen size: 144, 200, 270

#if (SCREEN_SIZE == 144)
#define EPD_SIZE    EPD_1_44
#define IMAGEFILE   image_144

#elif (SCREEN_SIZE == 200)
#define EPD_SIZE    EPD_2_0
#define IMAGEFILE   image_200

#elif (SCREEN_SIZE == 270)
#define EPD_SIZE    EPD_2_7
#define IMAGEFILE   image_270

#else
#error "Unknown EPB size: Change the #define SCREEN_SIZE to a supported value"
#endif


unsigned char matrix[32] = 
{
0x01,0x26,0x34,0x2C,0x24,0x24,0x37,0x4C,0x44,0x44,0x4C,0x74,0xC4,0x45,0x06,0x00,
0x00,0x82,0x84,0x89,0x91,0xE1,0xB2,0xAA,0xA4,0xA4,0xAA,0xB2,0x81,0x01,0x01,0x00,

};
void setup()
{
    
    Serial.begin(115200);
    EPAPER.begin(EPD_SIZE);                             // setup epaper, size 
    EPAPER.setDirection(DIRNORMAL);                     // set display direction
    
    eSD.begin(EPD_SIZE);                                   
    GT20L16.begin();

}

int i=0;


unsigned int uniCode[5] = {0xced2, 0xb0a5, 0xd6d0, 0xcec4, '!'};


void loop()
{

    //******************display seeed studio***************************
    eSD.clear();
    EPAPER.drawString("Seeed Studio", 50, 40);
    EPAPER.display();                                   // use only once
   
    delay(1000);
    
    
    //***************display more than 170 languages********************
    eSD.clear();
    EPAPER.drawString("more than 170 languages", 10, 40);
    EPAPER.display();                                   // use only once
   
    delay(1000);
    

    //*************************我爱中文********************************* 
    eSD.clear();
    EPAPER.drawUnicode(uniCode[0], 40, 40);
    EPAPER.drawUnicode(matrix, 56, 40);
    EPAPER.drawUnicode(uniCode[2], 72, 40);
    EPAPER.drawUnicode(uniCode[3], 88, 40);
    EPAPER.drawUnicode(uniCode[4], 104, 40);
    EPAPER.display();                                   // use only once
   
    Serial.println("over");
    delay(1000);
    
    
    //*************** draw**********************************************
    
    eSD.clear();
    EPAPER.drawRectangle(10, 10, 100, 80);
    EPAPER.fillCircle(50, 50, 30);
    EPAPER.fillRectangle(50, 65, 50, 20);
    
    EPAPER.drawCircle(150, 50, 25);
    EPAPER.drawCircle(150, 50, 20);
    EPAPER.drawCircle(150, 50, 15);
    EPAPER.drawCircle(150, 50, 10);
    EPAPER.fillCircle(150, 50, 5);
    
    EPAPER.drawHorizontalLine(120, 50, 60);
    EPAPER.drawVerticalLine(150, 20, 60);
    
    EPAPER.display();                                   // display, you can use this function
    
    delay(1000);
    
    
    //**********************image*****************************************
    
    EPAPER.image_flash(IMAGEFILE);
    delay(1000);
    
    
    //
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
