



void State() {
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
  u8g2.drawBox(0, 0, 127, 40);
  u8g2.setDrawColor(1);
  u8g2.setCursor(0, 10);
  u8g2.print("ESP Board MAC Address:  ");
  u8g2.setCursor(0, 20);
  u8g2.print(WiFi.macAddress());
  u8g2.setCursor(0, 30);
  u8g2.print("WiFi.localIP");
  u8g2.setCursor(0, 40);
  u8g2.print(WiFi.localIP());
  u8g2.sendBuffer();
  delay(1000);
}
