#include <DHT.h>;
#include <Wire.h> ;
#include <LiquidCrystal_I2C.h>;

//Constants
#define DHTPIN A1     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino
LiquidCrystal_I2C lcd(0x27,16,2);

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setBacklight(HIGH);
}

void loop()
{
    delay(2000);
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    delay(10000); //Delay 2 sec.
    //Print temp and humidity value to LCD
    lcd.setCursor(0,0);
    lcd.print("Humidity: ");
    lcd.print(hum);
    lcd.print("%");
    lcd.setCursor(0,1);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.println("Celcius");
    delay(2000);
}

   
