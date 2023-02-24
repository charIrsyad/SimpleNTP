#include "SimpleNTP.h" 
#include <WiFi.h>

const char* ssid       = "x"; //ssid and password
const char* password   = "x";

SimpleNTP ntp;

float GMT = 8; //x 3600
float DST = 0; //x 3600


//it automaticly x 3600


void setup() {
  ntp.begin(  GMT  ,  DST  );

  Serial.begin(115200);
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println(" CONNECTED");
}

void loop() {

  ntp.readNTP(); //raeds the time from ntp
  Serial.print(ntp.dayOfMonth, DEC);
  Serial.print("/");
  Serial.print(ntp.month, DEC);
  Serial.print("/");
  Serial.print(ntp.year, DEC);
  Serial.print(" (");
  Serial.print(ntp.dayOfWeek); 
  Serial.print(") ");
  Serial.print(ntp.hour, DEC);
  Serial.print(":");
  Serial.print(ntp.minute, DEC);
  Serial.print(":");
  Serial.print(ntp.second, DEC);
  Serial.println();

}
