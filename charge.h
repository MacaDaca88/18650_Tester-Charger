#ifndef CHARGE_H
#define CHARGE_H

float R3v = 690;
float R3v2= 1000;

float R1 = 2000.0;
float R2 = 1000.0;

float R3 = 10000.0;
float R4 = 1300.0;

int batt1Value = 0;
int batt2Value = 0;
int batt3Value = 0;
int batt4Value = 0;

float batt1;
float batt2;
float batt3;
float batt4;

int chargeBox1;
int chargeBox2;
int chargeBox3;
int chargeBox4;

int b1;
int b2;
int b3;
int b4;

void readCharge() {
  batt1Value = analogRead(BATT1);
  batt2Value = analogRead(BATT2);
  batt3Value = analogRead(BATT3);
  batt4Value = analogRead(BATT4);



  batt1 = batt1Value * (3.36 / 4093) * ((R3v + R3v2) / R3v2);
  chargeBox1 = map(batt1Value, 0, 4093, 1, 53);
  batt2 = batt2Value * (3.36 / 4093) * ((R3v + R3v2) / R3v2);
  chargeBox2 = map(batt2Value, 0, 4093, 1, 53);
  batt3 = batt3Value * (3.36 / 4093) * ((R1 + R2) / R2);
  chargeBox3 = map(batt3Value, 0, 4093, 1, 30);
  batt4 = batt4Value * (3.36 / 4093) * ((R3 + R4) / R4);
  chargeBox4 = map(batt4Value, 0, 4093, 1, 30);

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
  if (batt1 != b1) {
  //  Serial.println(batt1Value);
    //Serial.print("Battery 1 = ");
    //Serial.println(batt1);
    b1 = batt1;
  }
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
  if (batt2 != b2) {
 //   Serial.println(batt2Value);
  //  Serial.print("Battery 2 = ");
  //  Serial.println(batt2);
    b2 = batt2;
  }
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
  if (batt3 != b3) {
    Serial.println(batt3Value);
    Serial.print("Battery 3 = ");
    Serial.println(batt3);
    b3 = batt3;
  }
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
  if (batt4 != b4) {
    Serial.println(batt4Value);
    Serial.print("Battery 4 = ");
    Serial.println(batt4);
    b4 = batt4;
  }
  u8g2.sendBuffer();
  if (batt4 >= 10.8) {
    digitalWrite(LED, 1);
  } else {
    digitalWrite(LED, 0);
  }
}

#endif