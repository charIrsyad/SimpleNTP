#include "Arduino.h"
#include "time.h"
#include "sys/time.h"
#include "SimpleNTP.h"
#include "sntp.h"

//PRIVATE:


//PUBLIC:

void SimpleNTP::begin(float gmt, float dst){ 
  sntp_servermode_dhcp(1);
  configTime(gmt*3600,dst*3600, "pool.ntp.org", "time.nist.gov"); //change ntp server here
}

void SimpleNTP::readNTP(){
  time_t now;
  struct tm timeinfo; //get the time
  if(!getLocalTime(&timeinfo)){
    return;
  }
  int ntp_hour = timeinfo.tm_hour;
  int ntp_minute = timeinfo.tm_min;
  int ntp_second = timeinfo.tm_sec;
  long ntp_year = timeinfo.tm_year + 1900;
  int ntp_month = timeinfo.tm_mon + 1;
  int ntp_dayMonth = timeinfo.tm_mday;
  int ntp_dayWeek = timeinfo.tm_wday;

  if(ntp_dayWeek == 0){
    ntp_dayWeek = 7;
  } else {
    ntp_dayWeek = timeinfo.tm_wday;
  }
    
    unix = time(&now);

    second = ntp_second; /*second*/

    minute = ntp_minute; /*minute*/

    hour = ntp_hour;   /*hour*/

    dayOfWeek = ntp_dayWeek;  /*dayOfWeek*/

    dayOfMonth = ntp_dayMonth; /*dayOfMonth*/

    month = ntp_month; /*month*/

    year = ntp_year; /*year*/

}