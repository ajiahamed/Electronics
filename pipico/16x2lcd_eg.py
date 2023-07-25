from machine import I2C, Pin
from time import sleep
from lcd_api import LcdApi
from pico_i2c_lcd import I2cLcd

i2c = I2C(0, sda = Pin(0), scl = Pin(1), freq = 400000)
lcd = I2cLcd(i2c, 0x27, 2, 16)
lcd.move_to(0,0)
lcd.putstr("  16x2 LCD with")
lcd.move_to(0,1)
lcd.putstr("RaspberryPiPico")
sleep(2)
lcd.clear()

while True:
    lcd.move_to(0,0)
    lcd.putstr("nixNtronics")
    lcd.move_to(3,1)
    lcd.putstr("subscribe")
    sleep(0.5)
    lcd.move_to(3,1)
    lcd.putstr("   yyy      ")
    sleep(0.5)
    
    