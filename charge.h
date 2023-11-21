#ifndef CHARGE_H
#define CHARGE_H


void readCharge() {
  batt1Value = analogRead(BATT1);
  batt2Value = analogRead(BATT2);
  batt3Value = analogRead(BATT3);
  batt4Value = analogRead(BATT4);

  batt1 = batt1Value * (3.3 / 1023);
  chargeBox1 = map(batt1Value, 0, 1023, 1, 38);
  batt2 = batt2Value * (5.0 / 1023);
  chargeBox2 = map(batt2Value, 0, 1023, 1, 38);
  batt3 = batt3Value * (5.0 / 1023) * ((R1 + R2) / R2);
  chargeBox3 = map(batt3Value, 0, 1023, 1, 18);
  batt4 = batt4Value * (5.0 / 1023) * ((R3 + R4) / R4);
  chargeBox4 = map(batt4Value, 0, 1023, 1, 18);

  u8g2.clearBuffer();

  u8g2.setDrawColor(0);
  u8g2.drawBox(0, 0, 127, 63);

  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.setDrawColor(1);
  u8g2.setCursor(0, 10);
  u8g2.print("B+1");
  u8g2.drawBox(5, 15, 10, 40);
  u8g2.drawBox(8, 11, 5, 4);

  u8g2.setFont(u8g2_font_5x7_tf);
  u8g2.setDrawColor(1);
  u8g2.setCursor(0, 62);
  u8g2.print(batt1);
  u8g2.print("v");
  u8g2.setDrawColor(0);
  u8g2.drawBox(7, 15 + 40 - chargeBox1, 6, chargeBox1);

  Serial.println(batt1Value);
  Serial.print("Battery 1 = ");
  Serial.println(batt1);

  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.setDrawColor(1);
  u8g2.setCursor(25, 10);
  u8g2.print("B+2");
  u8g2.drawBox(30, 15, 10, 40);
  u8g2.drawBox(33, 11, 5, 4);

  u8g2.setFont(u8g2_font_5x7_tf);
  u8g2.setDrawColor(1);
  u8g2.setCursor(25, 62);
  u8g2.print(batt2);
  u8g2.print("v");
  u8g2.setDrawColor(0);
  u8g2.drawBox(32, 15 + 40 - chargeBox2, 6, chargeBox2);

  Serial.println(batt2Value);
  Serial.print("Battery 2 = ");
  Serial.println(batt2);

  u8g2.setDrawColor(1);
  u8g2.drawBox(50, 35, 35, 20);
  u8g2.drawBox(55, 31, 5, 4);
  u8g2.drawBox(75, 31, 5, 4);

  u8g2.setDrawColor(1);
  u8g2.setCursor(60, 62);
  u8g2.print(batt3);
  u8g2.print("v");
  u8g2.setDrawColor(0);
  u8g2.drawBox(52, 40 + 15 - chargeBox3, 31, chargeBox3);


  u8g2.setDrawColor(1);
  u8g2.drawBox(100, 35, 25, 20);
  u8g2.drawBox(105, 31, 5, 4);
  u8g2.drawBox(115, 31, 5, 4);

  u8g2.setDrawColor(1);
  u8g2.setCursor(100, 62);
  u8g2.print(batt4);
  u8g2.print("v");
  u8g2.setDrawColor(0);
  u8g2.drawBox(102, 40 + 15 - chargeBox4, 21, chargeBox4);
  u8g2.sendBuffer();
  if (batt4 <= 10.8){
    digitalWrite(LED,1);
  }else{
    digitalWrite(LED,0);
  }
      delay(100);
}

#endif