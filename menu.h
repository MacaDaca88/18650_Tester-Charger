#ifndef MENU_H
#define MENU_H

#include "temp.h"
#include "backdrop.h"

void home() {

  u8g2.clearBuffer();
  temps();  // update temp and himidity

  u8g2.setDrawColor(0);
  u8g2.drawBox(0, 0, 127, 63);

  u8g2.setDrawColor(1);
  u8g2.setCursor(10, 10);
  u8g2.print("18650 test/charge");

  u8g2.setCursor(30, 30);
  u8g2.print("Temp = ");
  u8g2.print(temp);
  u8g2.setCursor(30, 50);
  u8g2.print("Humid = ");
  u8g2.print(humid);
  u8g2.sendBuffer();
}


#endif