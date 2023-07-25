from machine import I2C, Pin
from ds1307 import DS1307
from pico_i2c_lcd import I2cLcd

i2c_lcd = I2C(id=1,scl=Pin(3),sda=Pin(2),freq=100000)

lcd = I2cLcd(i2c_lcd, 0x27, 2, 16)

i2c_rtc = I2C(0,scl = Pin(1),sda = Pin(0),freq = 400000)
result = I2C.scan(i2c_rtc)
rtc = DS1307(i2c_rtc)

"""
year = int(input("Year : "))
month = int(input("month (Jan --> 1 , Dec --> 12): "))
date = int(input("date : "))
day = int(input("day (1 --> monday , 2 --> Tuesday ... 0 --> Sunday): "))
hour = int(input("hour (24 Hour format): "))
minute = int(input("minute : "))
second = int(input("second : "))

now = (year,month,date,day,hour,minute,second,0)
rtc.datetime(now)
print(rtc.datetime())
"""



while True:
    (Y,M,D,day,hr,m,s,p1)=rtc.datetime()
    if s < 10:
        s = "0" + str(s)
    if m < 10:
        m = "0" + str(m)
    if hr < 10:
        hr = "0" + str(hr)
    if D < 10:
        D = "0" + str(D)
    if M < 10:
        hr = "0" + str(M)
        
    lcd.move_to(0,0)
    lcd.putstr("Time:")
    lcd.move_to(6,0)
    lcd.putstr(str(hr) + ":" + str(m) + ":" + str(s))
    lcd.move_to(0,1)
    lcd.putstr("Date:")
    lcd.move_to(6,1)
    lcd.putstr(str(D) + "/" + str(M) + "/" + str(Y))