#-*- coding: utf-8 -*-

import PRi.GPIO as gpio
import time

led1 = 20
led2 = 21
sensor = 17

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

GPIO.setup(led1, GPIO.OUT)
GPIO.setup(led2, GPIO.OUT)
GPIO.setup(sensor, GPIO.IN)

print("PIR 준비")
time.sleep(3)

try:
    while(1):
        if GPIO.input(sensor) == 1:
            GPIO.output(led2,1)
            GPIO.output(led1,0)
            print("동작감지")
            time.sleep(0.2)
            
        elif GPIO.input(sensor) == 0:
            GPIO.output(led1,1)
            GPIO.output(led2,0)
            time.sleep(0.2)
            
except KeyboardInterrupt:
    print("정지")
    GPIO.cleanup()