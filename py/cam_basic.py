from picamera import PiCamera
from time import sleep

camera = PiCamera()
camera.start_preview()

# 해상도, 파이 카메라로 최대 해상도는 25XX, 19XX
camera.resolution = (2592, 1944)
camera.framerate = 15
camera.start_preview()
camera.rotation = 180

# 카메라의 센서가 빛의 수준을 감지할 시간이 있어야 하므로 이미지를 캡쳐하기 전에 최소 2초는 sleep
sleep(10)
camera.capture("/home/pi/mywork/picamera/image.jpg")
# 사진 촬영 파일명 또는 경로 -> RDS
camera.stop_preview()