int chk;
float temp;
float humidity;

#include <dht.h>
dht DHT;
#define DHTPIN 8


void setup() {
 Serial.begin(9600);
}

void loop() {
  chk=DHT.read11(DHTPIN);
  temp=DHT.temperature;
  humidity=DHT.humidity;

  Serial.print("Temperature=");
  Serial.println(temp);

  Serial.print("HUMIDITY =");
  Serial.println(humidity);
   delay(1500);
   
  

}
