/*******************************************************************************
  Title                 :   Smart Switch from Misfits
  Filename              :   Misfits.c
  Author                :   Ajee,Anto,Nithin,Mohan
  Origin Date           :   11/04/2012
  Version               :   1.0.0
  Compiler              :   Arduino 1.8.14
  Target                :   ESP32
  Notes                 :   None
*******************************************************************************/
/*
   Functionality :
                  1.Keys input
                  2.Welcome page
                  3.Relay Status                 
*/
/******************************************************************************
  Includes
*******************************************************************************/
#include "Misfits.h"


void setup() 
{
  
  Serial.begin(115200);
  pinMode(ENTER.PIN, INPUT);
  
  attachInterrupt(ENTER.PIN, isr, FALLING);
  attachInterrupt(UP.PIN, isr_01, FALLING);
  attachInterrupt(DOWN.PIN, isr_02, FALLING);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  { 
    // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  // MISFITS... Wellcome page 
  Mts_SmartSwitch_Disp_Welcome( );
}
/******************************************************************************
  Application : Takes the input and control the relay and print the status.
*******************************************************************************/
void loop() 
{
  if (ENTER.pressed) 
  {
      Serial.println(" ENTER ");
      ENTER.pressed = false;
      Mts_SmartSwitch_Relay(true);
      Mts_SmartSwitch_Disp_RlySt(true);
  }
  if (UP.pressed) 
  {
      Serial.println(Flash_Test);
      UP.pressed = false;
      Mts_SmartSwitch_Relay(false);
      Mts_SmartSwitch_Disp_RlySt(false);
  }
  if (DOWN.pressed) 
  {
      Serial.println(" DOWN ");
      DOWN.pressed = false;
  }
}
