#include <WiFi.h>
#include "time.h"

const char* ssid       = "YOUR_SSID";
const char* password   = "YOUR_PASS";

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 25200;
const int   daylightOffset_sec = 3600;

//////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(115200);
  xTaskCreate(tx_Time, "uart_tx_task", 1024*2, NULL, configMAX_PRIORITIES-1, NULL); 

  ///////////////connect to WiFi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println(" CONNECTED");

  //////////////init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();

  //////////////disconnect WiFi as it's no longer needed
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
}

//////////////////////////////////////////////////////////////////////

void loop() {
  printLocalTime();
  tx_task()
}

/////////////////////////////////////////////// For Debug
void printLocalTime()
{
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

////////////////////////////////////////////////// Work with sentdata function and config function

static void tx_Time(void *arg)
{
    esp_log_level_set(TX_Sit_Range, ESP_LOG_INFO);
    Serial.println("It work!!");
    while (1) {
        char timeHour[3];
        strftime(timeHour,3, "%H", &timeinfo);
        char timeMinute[3];
        strftime(timeMinute,3, "%M", &timeinfo);
        char timeSecond[3];
        strftime(timeSecond,3, "%S", &timeinfo);
        sendData(TX_Sit_Range, timeHour);
        sendData(TX_Sit_Range, timeMinute);
        sendData(TX_Sit_Range, timeSecond);
        
    }
}