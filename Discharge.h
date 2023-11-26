#ifndef DISCHARGE_H
#define DISCHARGE_H

int discharge;

int dischargeBox;

float dischargeVolts;


void readDrain() {

  discharge = analogRead(DISCHARGE);
  dischargeVolts = discharge * (4.7 / 1023);
  dischargeBox = map(discharge, 0, 1023, 1, 50);
  u8g2.clearBuffer();

  u8g2.setDrawColor(1);
  u8g2.drawBox(0, 0, 127, 63);

  u8g2.setDrawColor(0);
  u8g2.setCursor(0, 60);
  u8g2.print("Drain");
  u8g2.drawBox(40, 50, 50, 10);
  u8g2.drawBox(35, 53, 5, 4);
  u8g2.setDrawColor(1);
  u8g2.drawBox(42 + 48 - dischargeBox, 52, dischargeBox, 5);

  u8g2.setDrawColor(0);
  u8g2.setCursor(100, 60);
  u8g2.print(dischargeVolts);

  u8g2.sendBuffer();
}

#endif