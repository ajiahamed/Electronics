/* DHT-22 sensor with 12c 16x2 LCD with Arduino uno
   Temperature and humidity sensor displayed in LCD
   based on: http://www.ardumotive.com/how-to-use-dht-22-sensor-en.html and
   https://www.ardumotive.com/i2clcden.html for the i2c LCD library by Michalis Vasilakis
   Recompile by adhitadhitadhit
   Notes: use LCD i2c Library from link above, i'm not sure why but new Liquidcristal library from Francisco Malpartida  isn't working for me
   other thing, check your */

//Libraries
#include <DHT.h> // sensor library using lib from https://www.ardumotive.com/how-to-use-dht-22-sensor-en.html
#include <LiquidCrystal_I2C.h> // LCD library using from  https://www.ardumotive.com/i2clcden.html for the i2c LCD library 
#include <Wire.h> 
//dht DHT;

//Constants
#define DHT22_PIN 2     // DHT 22  (AM2302) - pin used for DHT22 
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 after finding it from serial monitor (see comment above) for a 16 chars and 2 line display

//Variables
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
    Serial.begin(9600);
    lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setBacklight(HIGH);
}

void loop()
{
    int chk = DHT.read22(DHT22_PIN);
    //Read data and store it to variables hum and temp
    hum = DHT.humidity;
    temp= DHT.temperature;
    //Print temp and humidity values to LCD
    lcd.setCursor(0,0);
    lcd.print("Humidity: ");
    lcd.print(hum);
    lcd.print("%");
    lcd.setCursor(0,1);
    lcd.print("Temp: "); 
    lcd.print(temp);
    lcd.println("Celcius");
    delay(2000); //Delay 2 sec between temperature/humidity check.
}
