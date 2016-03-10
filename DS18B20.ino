#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

#define ONE_WIRE_BUS 10
LiquidCrystal lcd(13,12,11,10,9,8);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  lcd.begin(20, 4);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  lcd.setCursor(0, 0);
  lcd.print("Sensor 0: ");
  lcd.print(sensors.getTempCByIndex(0));
  lcd.print("C");
  
  lcd.setCursor(0, 1);
  lcd.print("Sensor 1: ");
  lcd.print(sensors.getTempCByIndex(1));
  lcd.print("C");
}
