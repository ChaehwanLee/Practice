import RPi.GPIO as gpio
import time

LED = 26;
btn_minus = 20;
btn_plus = 21;
buzzer_pin = 17;
servo_pin = 22;
angle = 0;
gpio.setmode(gpio.BCM)

gpio.setup(LED,gpio.OUT)
gpio.setup(btn_plus,gpio.IN,pull_up_down=gpio.PUD_UP)
gpio.setup(btn_minus,gpio.IN,pull_up_down=gpio.PUD_UP)
gpio.setup(buzzer_pin,gpio.OUT)
gpio.setup(servo_pin,gpio.OUT) # 서보핀을 출력으로 설정
pwm_servo = gpio.PWM(servo_pin, 50) # 서보핀을 PWM 모드 50Hz 로 사용
pwm_buzzer = gpio.PWM(buzzer_pin,262)

# pluse 버튼에 처리
from multiprocessing.connection import answer_challenge


def btn_plus_callback(channel):
    global angle
    if angle > 180:
        angle = 180
    else:    
        angle = angle + 10
    
    duty = getDuty(angle)
    print(angle)

def btn_minus_callback(channel):
    global angle
    if angle<=0:
        angle=0
    else:    
        angle = angle-10
    
    duty = getDuty(angle)
    print(angle)
    pwm_servo.ChangeDutyCycle(duty)
    
def run_buzzer():
    pwm_buzzer.ChangeDutyCycle(50)
    time.sleep(0.5)
    pwm_buzzer.ChangeDutyCycle(0)
    
# push 두 개에 이벤트 처리 
gpio.add_event_detect(btn_plus,gpio.RISING,callback=btn_plus_callback,bouncetime=100)
gpio.add_event_detect(btn_minus,gpio.RISING,callback=btn_minus_callback,bouncetime=100)

try:
    while 1:
        if angle==0 or angle ==180:
            print("부저를 울리자",angle)
            run_buzzer()
        elif angle ==90:
            gpio.output(LED,True)
        else:
            gpio.output(LED,False)
except KeyboardInterrupt:
    pass
finally:
        pwm_servo.ChangeDutyCycle(2.5)
        pwm_buzzer.stop()
        pwm_servo.stop()
        gpio.cleanup()