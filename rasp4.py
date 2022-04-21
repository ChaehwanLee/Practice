import paho.mqtt.client as mqtt
import RPi.GPIO as gpio

import time
import board # 데이터 송신용 board모듈
import adafruit_dht

mydht11 = adafruit_dht.DHT11(board.D20)

gpio.setmode(gpio.BCM)
led_pin = 19 # led
gpio.setup(led_pin, gpio.OUT)

pir_pin = 27 # pir
gpio.setup(pir_pin,gpio.IN)


def connect_result(client, userdata, flags, rc):
    print("connect..."+str(rc))
    if rc == 0: 
        client.subscribe("mydata/led")
    else:
        print("연결실패.....")
        
try:
    mqttClient = mqtt.Client()
    mqttClient.on_connect = connect_result
    mqttClient.connect("***.**.1.**",1883,60)
    mqttClient.loop_forever() 
except KeyboardInterrupt:
    pass
finally:
    pass

# led
def mydevice(client, userdata, flags, rc):
    print("connect..."+str(rc)) 
    if rc == 0:
        client.subscriber("led_on/`")
    else:
        print("연결실패.....")
        
def on_message(client, userdata, message):
    myval = message.payload.decode("utf-8")
    print(message.topic+"-----"+myval)
    if myval == "led_on":
        print("on")
        gpio.output(led_pin,gpio.HIGH)
    else:
        print("off")
        gpio.output(led_pin,gpio.LOW)
        
try:
    mqttClient = mqtt.Client()
    mqttClient.on_connect = mydevice
    mqttClient.on_message = on_message 
    mqttClient.connect("***.**.1.**",1883,60)
    mqttClient.loop_forever() 
except KeyboardInterrupt:
    pass
finally:
    pass

# mydht11
while True:
    try:
        humidity_data = mydht11.humidity
        temperature_data = mydht11.temperature
        print(humidity_data, temperature_data)
        time.sleep(2) 

    except RuntimeError as error:
        print(error.args[0])
    finally:
        pass
    
#pir
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