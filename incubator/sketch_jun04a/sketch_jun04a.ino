#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  //0x27 is the i2c address, while 16 = columns, and 2 = rows. 
 
void setup() {
  lcd.init();                 //Init the LCD
  lcd.backlight();            //Activate backlight     
  lcd.home();  
}
 
void loop() {
 
  lcd.clear();
  lcd.print("electroniClinic");
  delay(1000);
  lcd.setCursor(0,1);
  for (int i=0; i<=5; i++) //the columns are automatically incremented
  {
    lcd.print(i);
    delay(500);
  }
lcd.clear();
lcd.setCursor(0,0);
  lcd.print("electroniClinic");
    for (int i=0; i<=5; i++)
  {
    lcd.setCursor(0,1);
    lcd.print(i);
    delay(500);
  }
 
 
  lcd.noDisplay();
  delay(500);
  // Turn on the display:
  lcd.display();
  delay(500);
 
}
