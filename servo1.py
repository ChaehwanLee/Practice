import GPi.GPIO as GPIO
import time

pwm_pin=18
GPIO.setmode(GPIO.BCM)
GPIO.setup(pwm_pin,GPIO.OUT)
pwm = GPIO.PWM(pwm_pin, 100)
angle = 4
pwm.start(angle)

while True:
    cmd = input("Command, f/r:")
    direction = cmd[0]
    if direction == "f":
        angle+=1
    else:
        angle-=1
    if angle < 4:
        angle = 4
    elif angle > 23:
        angle = 23
    print("angle=", (angle-4)*10)
    pwm.ChangeDutyCycle(angle)
    
    # pi@raspberrypi ~ $ sudo apt-get install pigpio python-pigpio python3-pigpio
    # pi@raspberrypi ~ $ sudo pigpiod
    
    import pigpio
    import time
    
    pwm_pin = 18
    pi = pigpio.pi()
    angle = 0
    pi.set_servo_pulsewidth(pwm_pin, angle * 100 + 500)
    while True:
        cmd = input("Connand, f/r:")
        direction = cmd[0]
    if direction == "f":
        angle+=1
    else:
        angle-=1
    if angle < 0:
        angle = 0
    elif angle > 18:
        angle = 18
    print("angle=", angle*10)
    pi.set_servo(pwm_pin, angle * 100 + 500)