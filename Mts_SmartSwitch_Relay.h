/*******************************************************************************
  Title                 :   Smart Switch from Misfits
  Filename              :   Mts_SmartSwitch_Relay.h
  Author                :   Ajee,Anto,Nithin,Mohan
  Origin Date           :   11/04/2012
  Version               :   1.0.0
  Compiler              :   Arduino 1.8.14
  Target                :   ESP32
  Notes                 :   None
*******************************************************************************/

/*
   Functionality :
                  1.Relay controlling              
*/

/******************************************************************************
  Includes
*******************************************************************************/
#include "arduino.h"

/******************************************************************************
  Declarations
*******************************************************************************/
void Mts_SmartSwitch_Relay(bool Status);
const int RELAY_PIN  = 4; // Arduino pin connected to relay's pin



/******************************************************************************
  Mts_SmartSwitch_Relay: Controlls the relay based on the status.
*******************************************************************************/
void Mts_SmartSwitch_Relay(bool Status)
{
    if (Status == LOW) 
    {
    Serial.println("The button is unpressed");
    digitalWrite(RELAY_PIN, HIGH); // turn on
  }
  else
  if (Status == HIGH) {

    Serial.println("The button is being pressed");
    digitalWrite(RELAY_PIN, LOW);  // turn off
  }
}
