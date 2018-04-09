
#OPENCV_PATH=../../../../vcageneric/trunk
OPENCV_PATH=.

#opencv includes
INCS += -I $(OPENCV_PATH)/externals/OpenCV3.0.0.linux.x86/build/$(OBJDIRP)_rel/include
INCS += -I $(OPENCV_PATH)/externals/OpenCV3.0.0.linux.x86/build/$(OBJDIRP)_rel/include/opencv2


#opencv libs
MY_LDFLAGS += -L$(OPENCV_PATH)/externals/OpenCV3.0.0.linux.x86/build/$(OBJDIRP)_rel/lib
LIBS+=-lopencv_shape
LIBS+=-lopencv_stitching
LIBS+=-lopencv_objdetect
LIBS+=-lopencv_superres
LIBS+=-lopencv_videostab
LIBS+=-lopencv_calib3d
LIBS+=-lopencv_features2d
LIBS+=-lopencv_highgui
LIBS+=-lopencv_videoio
LIBS+=-lopencv_imgcodecs
LIBS+=-lopencv_video
LIBS+=-lopencv_photo
LIBS+=-lopencv_ml
LIBS+=-lopencv_imgproc
LIBS+=-lopencv_flann
LIBS+=-lopencv_core
LIBS+=-lopencv_hal
LIBS+=-lopencv_ts


#opencv 3rd party libs
MY_LDFLAGS += -L$(OPENCV_PATH)/externals/OpenCV3.0.0.linux.x86/build/$(OBJDIRP)_rel/share/OpenCV/3rdparty/lib/
LIBS+=-llibjpeg
LIBS+=-llibwebp
LIBS+=-llibpng
LIBS+=-llibtiff
LIBS+=-llibjasper
LIBS+=-lIlmImf
