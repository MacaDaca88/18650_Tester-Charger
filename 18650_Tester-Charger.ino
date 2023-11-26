

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <DHT11.h>
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

DHT11 dht11(16);

int button1 = 0;
int button2 = 0;
int button3 = 0;

int button1State = 0;
int button2State = 0;
int button3State = 0;

bool chargeMenu = false;
bool drainMenu = false;

enum MenuState {
  HOME,
  CHARGE,
  DRAIN
};

MenuState currentMenu = HOME;

int Time = 0;
int oldTime = 0;
int counter;

#include "menu.h"
#include "charge.h"
#include "Discharge.h"
#include "temp.h"
#include "backdrop.h"

void setup() {
  u8g2.clearBuffer();
  Serial.begin(115200);
  OTAinit();
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);

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
    Serial.print("Battery 3 = ");
    Serial.println(batt3);
    
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
      }
    }
  }

  if (button2 != button2State) {
    if (button2State == LOW) {
      ScreenSaver();
    }
  }
  button2State = button2;

  switch (currentMenu) {
    case HOME:
      home();
      break;

    case CHARGE:
      readCharge();
      break;

    case DRAIN:
      readDrain();
      break;
  }
  button1State = button1;
}
