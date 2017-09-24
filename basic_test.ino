/* MAX6675 Module + K Type Thermocouple Thermocouple Sensor (MAX6675) [S080] : http://rdiot.tistory.com/57 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <MAX6675.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004

int CS = 10;              // CS pin on MAX6675
int SO = 12;              // SO pin of MAX6675
//int SCK = 13;             // SCK pin of MAX6675 
int units = 1;            // Units to readout temp (0 = raw, 1 = ˚C, 2 = ˚F)
 
float temperature = 0.0;  // Temperature output variable

// Initialize the MAX6675 Library for our chip
MAX6675 temp0(CS,SO,SCK,units);

void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");

  delay(1000);

  lcd.clear();
}

void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S080:MAX6675+K");

  temperature = temp0.read_temp(); 
  if(temperature == -1) {                   // If there is an error with the TC, temperature will be -1
  
    lcd.setCursor(0,1);
    lcd.print("Thermocouple Error!!");
    
  } else { 
  
    lcd.setCursor(0,1);
    lcd.print("temperature=" + (String)temperature + "C ");

  }
  delay(1000);  // Wait one second before reading again
}
