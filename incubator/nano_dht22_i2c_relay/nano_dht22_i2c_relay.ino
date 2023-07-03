#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Constants
#define DHTPIN A1     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino
LiquidCrystal_I2C lcd(0x27,16,2);
int relayPin1 = 4; //Relay pin
int relayPin2 = 5; //Relay pin

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
  pinMode(relayPin1, OUTPUT); //Bulb ON/OFF relay
  pinMode(relayPin2, OUTPUT); //Fan ON/OFF relay
}

void loop()
{
    delay(2000);
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    //loop
    if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT");
    } else { 
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" *C");
    delay(10000); //Delay 2 sec.
    
    //Print temp and humidity value to LCD
    lcd.setCursor(0,0);
    lcd.print("Hum: ");
    lcd.print(hum);
    lcd.print("%");
    lcd.setCursor(0,1);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print("\337C ");
    delay(2000);
    }
    delay(900000); //add 15 minute delay when reading temperature/humidity

    //THERMOSTAT CONTROL
    //relay 1 is Bulb ON/OFF action
    //relay 2 is Fan ON/OFF action

    if ((temp) <= 13) //if temperature is less than or equal than 55F
    {
      digitalWrite(relayPin1,LOW); //Bulb ON
      delay(15000); //for 15 seconds
      digitalWrite(relayPin1,HIGH); //de-energize
    }
    if ((temp) >= 32) //if temperature is greater than or equal to 89F
    {
      digitalWrite(relayPin1,LOW); // Bulb OFF
      delay(15000);
      digitalWrite(relayPin1,HIGH);
    }
    else
    {
      digitalWrite(relayPin2,LOW); //Fan OFF
      delay(15000); //hold for 15 seconds
      digitalWrite(relayPin2,HIGH); //de-energize
    }
}

   
