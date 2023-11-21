

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <DHT11.h>

//#define UNO

#include "pins.h"

U8G2_SSD1305_128X64_ADAFRUIT_F_4W_SW_SPI u8g2(U8G2_R2, /* clock=*/SCK, /* data=*/MOSI, /* cs=*/SS, /* dc=*/MISO, /* reset=*/RES);

DHT11 dht11(16);

int button1 = 0;
int button2 = 0;
int button3 = 0;

int button1State = 0;
float R1 = 10000.0;
float R2 = 10000.0;

float R3 = 10000.0;
float R4 = 2200.0;

int batt1Value = 0;
int batt2Value = 0;
int batt3Value = 0;
int batt4Value = 0;
int discharge;


int chargeBox1;
int chargeBox2;
int chargeBox3;
int chargeBox4;
int dischargeBox;

float batt1;
float batt2;
float batt3;
float batt4;
float dischargeVolts;


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

int t;
int h;


#include "menu.h"
#include "charge.h"
#include "Discharge.h"
#include "temp.h"

void setup() {
  u8g2.clearBuffer();
  analogReadResolution(10);
  Serial.begin(115200);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
 
  pinMode(LED, OUTPUT);

  u8g2.begin();
  Serial.print("u8g2 BOOTING.");
  Serial.print(". ");
  Serial.print(". ");
  Serial.print(". ");
  Serial.print(". ");
  Serial.print(".");

  u8g2.setCursor(10, 10);
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0, 10, "u8g2 BOOTING.");
  u8g2.print(". ");
  u8g2.sendBuffer();
  delay(500);
}


void loop() {
  Time = millis();
  button1 = digitalRead(BUTTON1);
  button2 = digitalRead(BUTTON2);
  button3 = digitalRead(BUTTON3);

  if (button1 != button1State) {
    if (button1State == LOW) {
      switch (currentMenu) {
        case HOME:
          currentMenu = CHARGE;
          break;
        case CHARGE:
          currentMenu = DRAIN;
          break;
        case DRAIN:
          currentMenu = HOME;
          break;
      }
    }
  }
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
