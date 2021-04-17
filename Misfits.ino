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

//#define  RTC  


void setup() 
{
 // Terminal Print 
  Serial.begin(115200);
  
//******************************************************************************************//
//*                                   BUTTON                                               *//
//******************************************************************************************// 
  pinMode(ENTER.PIN, INPUT);
  
  attachInterrupt(ENTER.PIN, isr, FALLING);
  attachInterrupt(UP.PIN, isr_01, FALLING);
  attachInterrupt(DOWN.PIN, isr_02, FALLING);

//******************************************************************************************//
//*                                   O-LED                                                *//
//******************************************************************************************// 
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  { 
    // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  // MISFITS... Wellcome page 
  Mts_SmartSwitch_Disp_Welcome( );

//******************************************************************************************//
//*                                RTC                                                     *//
//******************************************************************************************//  
#ifdef  RTC
    if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
 pinMode(buzzer, OUTPUT);
 welcome_menu(1000);
 flag = choose_menu();
 set_alarm();
#endif
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
  
#ifdef RTC
 // show_time();
#endif

}

#ifdef  RTC

/******************************************************************************
  Functions : 
*******************************************************************************/
void show_time()
{
 DateTime now = rtc.now();

 if (now.hour() == h && now.minute() == m)
 {
   switch (flag)
   {
     case 1:
       Serial.print("** ءedicine Time **");
       break;
     case 2:
       Serial.print("You'r late!!");
       Serial.print("Come onnnnnnn");
       break;
     case 3:
       Serial.print("Befor you go:");
       Serial.print("Wallet,Keys,...");
       break;
   }
   for (int i = 0; i < 203; i++) {       //203 is the total number of music notes in the song
//     int wait = duration[i] * songspeed;
//     delay(wait);
   }
 }
 delay(2000);
}
void welcome_menu(int show_delay)
{
 Serial.print("Arduino reminder");
}
int detect_button() 
{
 int readkey = 0;
 int result = 0;
 int activeButton = 0;
 while (activeButton == 0) 
   {
     readkey = analogRead(0);
     if (readkey < 790) {
       delay(100);
       readkey = analogRead(0);
       if (readkey < 60) {
         result = 1; // right
       } else if (readkey < 200) {
         result = 2; // up
       } else if (readkey < 400) {
         result = 3; // down
       } else if (readkey < 600) {
         result = 4; // down
       }
     } 
     else if (readkey < 800) 
       { 
          result = 5; 
          return result; 
          activeButton = 1; 
       } 
   }
   return menuPage;
}

void set_alarm() 
{
 int sit = 0;

 Serial.print("**Set Alarm**");
 Serial.print("00:00");
 while (sit != 1)
 {
   sit = detect_button();
   if (sit == 2)
   {
     Serial.print("**Set Alarm**");
     h++;
     if (h > 23)
     {
       h = 0;
     }
     Serial.print(h);
     Serial.print(":00");
   }
   else if (sit == 3)
   {
     Serial.print("**Set Alarm**");
     h--;
     if (h < 0) { h = 23; }  Serial.print(h); Serial.print(":00"); } } while (sit != 5) { sit = detect_button(); if (sit == 2) { Serial.print("**Set Alarm**"); m++; if (m > 59)
     {
       m = 0;
     }
     Serial.print(h);
     Serial.print(":");
     Serial.print(m);
   }
   else if (sit == 3)
   {
     Serial.print("**Set Alarm**");
     m--;
     if (m < 0)
     {
       m = 59;
     }
     
     Serial.print(h);
     Serial.print(":");
     Serial.print(m);
   }
 }
 Serial.print("Alarm set");
 Serial.print("I'll be on time");
 delay(1500);
}

int choose_menu() 
{ 
  while (btn != 5) 
  { 
      btn = detect_button(); 
      if (btn == 1) 
      { 
        if (menuPage > maxMenuPages) menuPage = 0;
      }
  }
  return menuPage;
}
#endif
