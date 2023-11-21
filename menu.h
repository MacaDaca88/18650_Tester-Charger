#ifndef MENU_H
#define MENU_H

#include "temp.h"

void home() {
  temps();   // update temp and himidity 
  u8g2.clearBuffer();

  u8g2.setDrawColor(0);
  u8g2.drawBox(0, 0, 127, 63);

  u8g2.setDrawColor(1);
  u8g2.setCursor(10, 10);
  u8g2.print("18650 test/charge");

  u8g2.setCursor(30, 30);
  u8g2.print("Temp = ");
  u8g2.print(t);
  Serial.print("Temp = ");
  Serial.println(t);
  u8g2.setCursor(30, 50);
  u8g2.print("Humid = ");
  u8g2.print(h);
  Serial.print("Humid = ");
  Serial.println(h);
  u8g2.sendBuffer();
}

#endif