#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); 
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS); 

 
DallasTemperature sensors(&oneWire);
 
void setup(void)
{
  
  Serial.begin(9600);
  sensors.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.setCursor(0,1);
  delay(2000);
  lcd.clear();
}
void loop(void)
{ 

  sensors.requestTemperatures(); 
  float tempC = sensors.getTempCByIndex(0);
  if(tempC != DEVICE_DISCONNECTED_C)
  {
    Serial.print("Temperature for the device 1 (index 0) is:");
    Serial.println(tempC);
    lcd.setCursor(0,0);
    lcd.print("Temperature:");
    lcd.setCursor(0,1);
    lcd.print(tempC);
    lcd.print((char)223);
    lcd.print("C");
    lcd.print(" | ");
    lcd.print(DallasTemperature::toFahrenheit(tempC));
    lcd.print("F");
  }
}
   
