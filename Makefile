#include folders
INCS += -I ./externals/vca_agent_lib/include 
INCS += -I ./externals/VCAParamHandler_lib/include
INCS += -I ./externals/VCAUtils_lib/include
INCS += -I ./externals/VCAProcess_lib/include
INCS += -I .

#vca libraries
LIBS+=-lvca_agent_lib_teach
LIBS+=-lVCAParamHandler
LIBS+=-lVCAProcess_lib
LIBS+=-lvca_agent
LIBS+=-lVCAHyperblock
LIBS+=-lVCAUtils
LIBS+=-lgd 
LIBS+=-ljpeg

#include opencv (order of libs is important!)
include ./MakeOpenCV.mk

#3rd party libs
LIBS+=-ldl
LIBS+=-lrt
LIBS+=-lm -lpthread
LIBS+=-lssl -lcrypto



#library foldes
MY_LDFLAGS += -L./externals/gd_lib/$(OBJDIRP)_rel/
MY_LDFLAGS += -L./externals/jpeg-9b_lib/$(OBJDIRR)_rel/
MY_LDFLAGS += -L./externals/jpeg_lib/$(OBJDIRP)_rel/
MY_LDFLAGS += -L./externals/vca_agent_lib/$(OBJDIRP)_rel/
MY_LDFLAGS += -L./externals/VCAHyperblock_lib/$(OBJDIRP)_rel/
MY_LDFLAGS += -L./externals/VCAParamHandler_lib/$(OBJDIRP)_rel/
MY_LDFLAGS += -L./externals/VCAProcess_lib/$(OBJDIRP)_rel/
MY_LDFLAGS += -L./externals/VCAUtils_lib/$(OBJDIRP)_rel/
MY_LDFLAGS += -L./externals/vca_agent_lib_teach/$(OBJDIRP)_rel/

#program name
PROGRAM = image_proc_agent


#select compiler for host target 
ifeq ($(TARGET_TYPE),arm)
 CXX=arm-linux-gnueabihf-g++
 AR=arm-linux-gnueabihf-ar
 OBJDIRP = arm-obj
 MY_CFLAGS += -DNO_SSL_DL -DOSC_TARGET
 
 #some libs are target dep.
 LIBS+=-lzlib -l:libudev.so.0
 MY_LDFLAGS += -L./externals/libudev/arm
 MY_LDFLAGS += -L./externals/openssl.linux.arm/
else
 CXX     = g++
 AR      = ar
 OBJDIRP = linux-obj
 MY_CFLAGS = -DNO_SSL_DL -DOSC_HOST
 
 #some libs are target dep.
 LIBS+=-lzlib -l:libudev.so.1
 MY_LDFLAGS += -L./externals/openssl.linux.x86/
endif

#release or debug mode
ifeq ($(BUILD_TYPE),)
  MY_CFLAGS += -fpic -Wall -O3  -DNDEBUG  -DRUN_MODE=0
  OBJDIR =$(OBJDIRP)_rel
endif

ifeq ($(BUILD_TYPE),debug)
  MY_CFLAGS +=  -fpic -ggdb -Wall -D_DEBUG  -DRUN_MODE=0
  OBJDIR =$(OBJDIRP)_dbg
  MY_LDFLAGS += -ggdb 
endif

#for profiling
PROFFLAG =
ifdef PROFILE_FLAG
  PROFFLAG = -pg
endif
    
# Command to make an object file:
COMPILE = $(CXX) $(PROFFLAG) -I. $(INCS) $(CFLAGS) $(MY_CFLAGS) -c

# ------------------------------------------------------------------------
# Source filea
SOURCES += Process_2_Teach.cpp ProcessingDbgImages.cpp ProcessingTeachMain.cpp  ProcessingTeachParams.cpp main.cpp

# ------------------------------------------------------------------------
# Object files
OBJS=$(foreach SRCFILE,$(SOURCES),$(OBJDIR)/$(SRCFILE:.cpp=.o))

####### Build rules
all:  $(PROGRAM)

$(PROGRAM) :   $(OBJS)
	echo target: $(TARGET_TYPE) ..
	echo $(CXX) $(MY_LDFLAGS) $^ $(LIBS) -o $(PROGRAM)
	$(CXX) $(PROFFLAG) $(LDFLAGS) $(MY_LDFLAGS) $^ -o $(OBJDIR)/$(PROGRAM) $(LIBS) $(MY_LIBS) 


clean:
	find  $(OBJDIR) -name "*.o" -exec rm -rvf {} \; || true
	rm -f $(OBJDIR)/$(PROGRAM)


$(OBJDIR)/%.o: %.cpp
	mkdir -p $(OBJDIR)
	$(COMPILE)  $< -o $@
