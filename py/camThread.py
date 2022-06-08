from threading import Thread
import logging
import time

class piCam(Thread):
    def __init__(self, contrast=7, exposure=0, framerate=32, resolution=(320,240)):
        from picamera import piCam
        from picamera.array import PiRGBArray

        self.camera = piCam()
        self.camera.contrast = contrast
        self.camera.exposure = exposure
        self.camera.framrate = framerate
        self.camera.resolution = resolution
        self.rawCapture = PiRGBArray(self.camera, size = resolution)
        self.exit = False
        self.frame = None
        logging.info('Contrast: {} Exposure: {} FPS: {}'.format(contrast, exposure, framerate))
        time.sleep(0.1)  # Sleep to let the camera warm up
        super().__init__(daemon=True)  # Initialize thread

    def run(self):
        for frame in self.camera.capture_continuous(self.rawCapture, format='bgr', use_video_port=True):
            if self.exit:
                break
            self.frame = frame.array
            self.rawCapture.truncate(0)

        def release(self):
            self.exit = True

        def set_exposure(self, exposure: int):
            self.camera.exposure_compensation = exposure

        def get_resolution(self):
            return self.camera.resolution

if __name__ == "__main__":
        help(piCam)