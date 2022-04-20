import RPi.GPIO as gpio
import time
pir_pin = 27
gpio.setmode(gpio.BCM)
gpio.setup(pir_pin,gpio.IN)

try:
    while True:
        if gpio.input(pir_pin == 1:
            print("motion detected....")
        else:
            print("no motion....")
        time.sleep(1)

except KeyboardInterrupt:
    pass

finally:
    gpio.clenup()