from machine import Pin, I2C

# Init I2C using pins GP8 & GP9 (default I2C0 pins)
#i2c = I2C(0, scl=Pin(9), sda=Pin(8), freq=200000)
i2c = I2C(0, sda = Pin(0), scl = Pin(1), freq = 400000)

# Display device address
print("I2C Address      : "+hex(i2c.scan()[0]).upper())