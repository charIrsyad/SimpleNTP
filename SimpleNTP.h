/*
  SimpleNTP.h header file

  Version: 1.0.0
  (c) 2022 Irsyad
*/

#ifndef SIMPLENTP_H
#define SIMPLENTP_H

#include "Arduino.h"

class SimpleNTP /*The "SimpleNTP" class*/
{
  public:

int second; /*second*/

int minute; /*minute*/

int hour;   /*hour*/

int dayOfWeek;  /*dayOfWeek*/

int dayOfMonth; /*dayOfMonth*/

int month; /*month*/

long year; /*year*/

unsigned long unix; /*get the unix*/

void begin(float gmt, float dst); /*Begin the ntp*/

void readNTP(); /*read ntp*/

  private:
 
};
#endif
