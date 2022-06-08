from paho.mqtt import client

i = 0
def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("연결 완료")
        client.subscribe("iot/cam")
    else:
        print("연결 실패")

def on_message(client, userdata, msg):
    global i
    i += 1
    f = open("./picamera/mqttimage%d.jpg" % i, "wb")
    f.write(msg.payload)
    # print(msg.payload)
    f.close()

mqttClient = client.Client()
mqttClient.on_connect = on_connect
mqttClient.on_message = on_message
mqttClient.connect("XXX.XXX.XXX.XXX", 1883, 60) 
mqttClient.loop_forever()