import time
import RPi.GPIO as gpio
servo_pin = 19
gpio.setmode(gpio.BCM)
gpio.setup(servo_pin,OUT)
pwm = gpio.PWM(servo_pin,50)
pwm.start(3) # 서보모터의 초기값을 0으로 설정
for i in range(30, 125): # 0:2.5, 90:7.5, 100:12.5
    pwm.ChangeDutyCycle(i/10)
    time.sleep(0.1)

pwm.ChangeDutyCycle(3)
time.sleep(2)
pwm.ChangeDutyCycle(0)
pwm.stop()
gpio.cleanup()