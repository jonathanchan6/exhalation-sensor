#include "uFire_SHT20.h"
uFire_SHT20 sht20;
double currentT, previousT, elapsedT;;
unsigned long timer;
double counter;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  sht20.begin();
}

void loop()
{
  currentT = sht20.humidity();
  //Serial.print("currentT : "); Serial.println(currentT);
  elapsedT = currentT - previousT; 
  //Serial.print("previousT : "); Serial.println(previousT);
  previousT = currentT; // 1000;//Second in unit
//  Serial.print("Correct T : "); Serial.println(elapsedT);
  Serial.print((String)sht20.humidity());
  Serial.print(" , ");
  Serial.println(elapsedT);
  if(elapsedT >1.1){
    counter = counter + 0.5;
    Serial.print(" , ");
    Serial.println(counter);
  }
  delay(500);
}
