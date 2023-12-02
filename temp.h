#ifndef TEMP_H
#define TEMP_H

DHT_Unified dht(DHTPIN, DHTTYPE);


float temp;
float humid;

float _temp;
float _humid;


void temps() {

  sensors_event_t event;

  dht.temperature().getEvent(&event);
  temp = event.temperature;

  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  } else {
    if (temp != _temp) {
      Serial.print("Temperature:");
      Serial.println(temp);
      _temp = temp;
    }
  }


  dht.humidity().getEvent(&event);
  humid = event.relative_humidity;

  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  } else {
    if (humid != _humid) {
      Serial.print("Humidity:");
      Serial.println(humid);
      _humid = humid;
    }
  }
}
#endif