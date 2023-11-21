#ifndef TEMP_H
#define TEMP_H

void temps() {

  t = dht11.readTemperature();
  h = dht11.readHumidity();
  if (t != DHT11::ERROR_CHECKSUM && t != DHT11::ERROR_TIMEOUT && h != DHT11::ERROR_CHECKSUM && h != DHT11::ERROR_TIMEOUT) {
    Serial.print("Temperature:");
    Serial.print(t);
    Serial.print(",Humidity:");
    Serial.println(h);
  }
}

#endif