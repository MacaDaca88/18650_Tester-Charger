#ifndef TEMP_H
#define TEMP_H

int temp = 0;
int humid = 0;

int _temp;
int _humid;

void temps() {

  temp = dht11.readTemperature() - 4;
  humid = dht11.readHumidity();

  if (temp != DHT11::ERROR_CHECKSUM && temp != DHT11::ERROR_TIMEOUT && humid != DHT11::ERROR_CHECKSUM && humid != DHT11::ERROR_TIMEOUT) {

    if (temp != _temp) {
      Serial.print("Temperature:");
      Serial.println(temp);
      _temp = temp;
    }
    if (humid != _humid) {
      Serial.print("Humidity:");
      Serial.println(humid);
      _humid = humid;
    }
  }
}

#endif