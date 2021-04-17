/*******************************************************************************
  Title                 :   Smart Switch from Misfits
  Filename              :   Misfits.h
  Author                :   Ajee,Anto,Nithin,Mohan
  Origin Date           :   11/04/2012
  Version               :   1.0.0
  Compiler              :   Arduino 1.8.14
  Target                :   ESP32
  Notes                 :   None
*******************************************************************************/

/******************************************************************************
  Includes
*******************************************************************************/

// include library to read and write from flash memory
#include <EEPROM.h>
#include <arduino.h>
#include "Mts_SmartSwitch_Relay.h"
#include "Mts_SmartSwitch_Display.h"
#include "RTClib.h"



/******************************************************************************
  Declarations
*******************************************************************************/
// define the number of bytes you want to access
#define EEPROM_SIZE 1

//RTC Declarations.
#ifdef RTC
RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


const int buzzer  = 4; // Arduino pin connected to relay's pin
String menuItems[] = {"1-Medicin", "2-Wake up", "3-Go out"};
int songspeed = 1.5;
int flag = 0;
int menuPage = 0;
int maxMenuPages = round(((sizeof(menuItems) / sizeof(String)) / 2) + .5);
int cursorPosition = 0;
int btn;
int h = 0, m = 0;
#endif

/******************************************************************************
  Declarations
*******************************************************************************/

struct Button {
  const uint8_t PIN;
  bool pressed;
};


Button ENTER = {2,false};
Button UP = {5,false};
Button DOWN = {18,false};
char Flash_Test;

/******************************************************************************
  Functions
*******************************************************************************/

void IRAM_ATTR isr() {
  ENTER.pressed = true;
}

void IRAM_ATTR isr_01() {
  UP.pressed = true;
}

void IRAM_ATTR isr_02() {
  DOWN.pressed = true;
}
