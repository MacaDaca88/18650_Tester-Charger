#ifdef WIFISTATE_H
#define WIFISTATE_H

byte mac[6];

void STATE() {
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {

    u8g2.setDrawColor(0);
    u8g2.drawBox(0, 0, 127, 63);
    u8g2.setDrawColor(1);
    u8g2.setCursor(10, 10);
    u8g2.print("Connection Failed");
    ESP.restart();
  }

  u8g2.clearBuffer();
  u8g2.setDrawColor(0);
  u8g2.drawBox(0, 0, 127, 63);
  WiFi.macAddress(mac);
  u8g2.setDrawColor(1);
  u8g2.setCursor(0, 0);
  u8g2.print("ESP Board MAC Address:  ");
  u8g2.print(mac);
  u8g2.setCursor(0, 40);
  u8g2.print(WiFi.localip);
  u8g2.sendBuffer();
}


#endif