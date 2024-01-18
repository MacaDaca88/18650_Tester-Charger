

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
//#define UNO
#include "pins.h"

U8G2_SSD1305_128X64_ADAFRUIT_F_4W_SW_SPI u8g2(U8G2_R2, /* clock=*/SCK, /* data=*/MOSI, /* cs=*/SS, /* dc=*/MISO, /* reset=*/RES);

///////////////////////OTA//////////////////////////

#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include "ota.h"

///////////////////////////////////////////////////


int button1 = 0;
int button2 = 0;
int button3 = 0;

int button1State = 0;
int button2State = 0;
int button3State = 0;

bool Charging = false;
bool Home = false;
bool Testing = false;
bool Wifi = false;


enum MenuState {
  HOME,
  CHARGE,
  DRAIN,
  WIFI
};

MenuState currentMenu = DRAIN;

int Time = 0;
int oldTime = 0;
int counter;

#include "menu.h"
#include "charge.h"
#include "Discharge.h"
#include "temp.h"
#include "backdrop.h"
#include "wifiState.h"

void setup() {
  u8g2.clearBuffer();
  Serial.begin(115200);
  OTAinit();
  dht.begin();
  sensor_t sensor;

  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);

  pinMode(BATT1, INPUT);
  pinMode(BATT2, INPUT);
  pinMode(BATT3, INPUT);
  pinMode(BATT4, INPUT);

  pinMode(LED, OUTPUT);

  u8g2.begin();
  Serial.print("u8g2 BOOTING.");

  u8g2.setCursor(10, 10);
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0, 10, "u8g2 BOOTING.");
  u8g2.print(". ");
  u8g2.sendBuffer();
  delay(500);
}


void loop() {
  ArduinoOTA.handle();

  Time = millis();
  button1 = digitalRead(BUTTON1);
  button2 = digitalRead(BUTTON2);
  button3 = digitalRead(BUTTON3);


  Serial.println(batt3Value);
  Serial.print("Battery 4 = ");
  Serial.println(batt4);

  if (button1 != button1State) {
    if (button1State == LOW) {
      counter++;
      Serial.print("counter");
      Serial.println(counter);

      switch (currentMenu) {
        case DRAIN:
          currentMenu = HOME;
          break;
        case HOME:
          currentMenu = CHARGE;
          break;
        case CHARGE:
          currentMenu = DRAIN;
          break;
        case WIFI:
          currentMenu = WIFI;
          break;
      }
    }
  }

  switch (currentMenu) {
    case HOME:
      home();
      Home = true;
      break;

    case CHARGE:
      readCharge();
      Charging = true;
      break;

    case DRAIN:
      readDrain();
      Testing = true;
      break;
    case WIFI:
      STATE();
      break;
  }
  button1State = button1;

  if (button2 != button2State) {
    if (button2State == LOW) {
      ScreenSaver();
    }
  }
  button2State = button2;
}
