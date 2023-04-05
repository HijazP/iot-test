#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define SOIL1 33
#define SOIL2 32
#define SOIL3 35
#define SOIL4 34
#define THRESHOLD 1000
#define ONE_WIRE_BUS 2

LiquidCrystal_I2C lcd(0x27, 16, 2);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void) {
  sensors.begin();
  lcd.init();
  lcd.backlight();
}

void loop(void) {
  int soil1 = analogRead(SOIL1);
  int soil2 = analogRead(SOIL2);
  int soil3 = analogRead(SOIL3);
  int soil4 = analogRead(SOIL4);
  sensors.requestTemperatures(); 

  lcd.clear();

  // if (soil1 < THRESHOLD)
  // {
  //   lcd.print("DRY ");
  // }
  // else
  // {
  //   lcd.print("WET ");
  // }
  
  lcd.print("SOIL 1 ");
  lcd.print(soil1);
  lcd.setCursor(0, 1);
  lcd.print("SOIL 2 ");
  lcd.print(soil2);
  delay(3000);
  lcd.clear();
  lcd.print("SOIL 3 ");
  lcd.print(soil3);
  lcd.setCursor(0, 1);
  lcd.print("SOIL 4 ");
  lcd.print(soil4);
  delay(3000);
  lcd.clear();
  lcd.print("Sensor suhu ");
  lcd.setCursor(0, 1);
  lcd.print(sensors.getTempCByIndex(0));
  delay(3000);
}