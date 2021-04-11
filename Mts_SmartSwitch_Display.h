/*******************************************************************************
  Title                 :   Smart Switch from Misfits
  Filename              :   Mts_SmartSwitch_Display.h
  Author                :   Ajee,Anto,Nithin,Mohan
  Origin Date           :   11/04/2012
  Version               :   1.0.0
  Compiler              :   Arduino 1.8.14
  Target                :   ESP32
  Notes                 :   None
*******************************************************************************/
/*
   Functionality :
                  1.Welcome page
                  2.Relay Status print              
*/
/******************************************************************************
  Includes
*******************************************************************************/
#include <EEPROM.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "arduino.h"


/******************************************************************************
  Declarations
*******************************************************************************/
#define   OLED_RESET 4

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

//Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void Mts_SmartSwitch_Disp_Welcome(void);
void Mts_SmartSwitch_Disp_RlySt(bool Status_b);


/******************************************************************************
  Mts_SmartSwitch_Disp_Welcome : Which displays the wellcome page.
*******************************************************************************/
void Mts_SmartSwitch_Disp_Welcome()
{
  display.clearDisplay();
  display.setCursor(10,20);
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.print("MISFITS");
  display.display();
  delay(1000);

 for (char repeat=0; repeat<4;repeat++)
 {
    display.setTextColor(SSD1306_BLACK);
    display.setCursor(95,22);
    display.print(".");
    display.display();
    display.setCursor(105,22);
    display.print(".");
    display.display();
    display.setCursor(115,22);
    display.print(".");
    display.display();
    
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(95,22);
    display.print(".");
    display.display();
    delay(300);
    display.setCursor(105,22);
    display.print(".");
    display.display();
    delay(300);
    display.setCursor(115,22);
    display.print(".");
    display.display();
    delay(300);
 }
   delay(1500);
   display.setTextColor(SSD1306_WHITE);
}
/******************************************************************************
  Mts_SmartSwitch_Disp_RlySt : Which display relay status based on the input.
*******************************************************************************/
void Mts_SmartSwitch_Disp_RlySt(bool Status_b)
{
  display.clearDisplay();
  display.setCursor(28,12);
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.print("SWITCH");
  display.display();
  delay(1000);

  if(Status_b== true)
  {
    display.setCursor(35,37);
    display.setTextColor(SSD1306_BLACK);
    display.print(" OFF");
    display.display();
    
    display.setCursor(35,37);
    display.setTextColor(SSD1306_WHITE);
    display.print(" ON ");
    display.display();
  }
  else
  { 
    display.setCursor(35,37);
    display.setTextColor(SSD1306_BLACK);
    display.print(" ON ");
    display.display();
    
    display.setCursor(35,37);
    display.setTextColor(SSD1306_WHITE);
    display.print(" OFF");
    display.display();
  }
}
