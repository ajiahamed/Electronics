from machine import I2C, Pin
from time import sleep
from lcd_api import LcdApi
from pico_i2c_lcd import I2cLcd
from ds3231_i2c import DS3231_I2C 


# Set DS I2C ID, SDA, SCL respective pins and uses default frequency (freq=400000)
ds_i2c = I2C(1,sda=Pin(2), scl=Pin(3),freq=400000)
#print("RTC I2C Address : " + hex(ds_i2c.scan()[0]).upper()) # Print the I2C device address in the command line
#print("RTC I2C Configuration: " + str(ds_i2c))              # Display the basic parameters of I2C device in the command line
ds = DS3231_I2C(ds_i2c)


i2c = I2C(0, sda = Pin(0), scl = Pin(1), freq = 400000)
lcd = I2cLcd(i2c, 0x27, 2, 16)
lcd.move_to(0,0)
lcd.putstr(" 16x2 LCD with")
lcd.move_to(4,1)
lcd.putstr("RPiPico")
sleep(2)
lcd.clear()

# Define the name of week days list
w  = ["Sunday","Monday","Tuesday","Wednesday","Thurday","Friday","Saturday"];

while True:
    # Retrun current time
    t = ds.read_time()
    
    lcd.move_to(0,1)
    lcd.putstr(" %02x/%02x/20%02x" %(t[4],t[5],t[6]))
    lcd.move_to(0,0)
    lcd.putstr(" Time: %02x:%02x:%02x" %(t[2],t[1],t[0]))
    sleep(10)
    lcd.clear()
    lcd.move_to(0,1)
    lcd.putstr("    %s" %(w[t[3]-1]))
    sleep(0.5)