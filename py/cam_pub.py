from picamera import PiCamera
import time
from paho.mqtt import publish

camera = PiCamera()
camera.start_preview()

for i in range(1, 6):
    time.sleep(2)
    camera.capture("/home/pi/mywork/picamera/mqttimage%d.jpg" % i)
    f = open("/home/pi/mywork/picamera/mqttimage%d.jpg" % i, "rb")
    # fArray = bytearray(f.read())  
    # print(fArray)
    publish.single("iot/cam", f.read(), hostname="XXX.XXX.XXX.XXX")
    f.close()
    
camera.stop_preview()