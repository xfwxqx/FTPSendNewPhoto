#
#
#
#

include $(CURDIR)/UserMake/Config.mak

ifneq ($(strip $(TARGET_OS)),linux)
$(error  本项目必须指定运行平台arm-linux)
endif
ifneq ($(strip $(TARGET_ARCH)),arm)
$(error  本项目必须指定运行平台arm-linux)
endif

ifeq ($(strip $(TOP_DIR)),)
TOP_DIR=$(CURDIR)
endif

ifeq ($(strip $(APP_TARGET)),)
APP_TARGET=VideoServer
endif

ifeq ($(strip $(SOURCE)),)
SOURCE:=$(wildcard *.c)
endif

ifeq ($(strip $(SOURCE)),)
	TEMPFILES:=*.o
	DENCFILES:=*.d
else
	TEMPFILES:=${SOURCE}
	TEMPFILES:=${patsubst %.s,%.o,$(TEMPFILES)}
	TEMPFILES:=${patsubst %.S,%.o,$(TEMPFILES)}
	TEMPFILES:=${patsubst %.c,%.o,$(TEMPFILES)}
	TEMPFILES:=${patsubst %.C,%.o,$(TEMPFILES)}
	TEMPFILES:=${patsubst %.cpp,%.o,$(TEMPFILES)}
	TEMPFILES:=${patsubst %.cc,%.o,$(TEMPFILES)}
	DENCFILES:=${patsubst %.o,%.d,$(TEMPFILES)}
endif
TEMPFILES += Debug
TEMPFILES += *.d.*
TEMPFILES += *.c.bak
TEMPFILES += *.h.bak








.PHONY:	all clean cleanall

all:$(APP_TARGET)

cleanall:clean
	$(RM) $(DENCFILES)
	$(RM)	$(APP_TARGET)

clean:
	$(RM) $(TEMPFILES)


include	$(CURDIR)/UserMake/Rules.mak


$(APP_TARGET):$(OBJ)
	$(CMD_LINK_OBJ) -o $(APP_TARGET) $(OBJ) $(LOADLIBES) $(LDLIBS);
ifeq ($(strip $(STRIP_TARGET)),yes)
	$(STRIP) $(APP_TARGET)
endif


ifneq ($(strip $(APP_DIR)),)
	$(MKDIR) $(APP_DIR)
	$(CP) $(TOP_DIR)/$(APP_TARGET) $(TOP_DIR)/$(APP_DIR)/
endif


ifneq ($(strip $(DOWNLOAD_DIR)),)
	$(CP) $(TOP_DIR)/$(APP_TARGET) $(DOWNLOAD_DIR)/
endif


ifneq ($(strip $(FS_ROOT)),)
  ifneq ($(strip $(INSTALL_DIR)),)
		$(CP) $(TOP_DIR)/$(APP_TARGET) $(FS_ROOT)/$(INSTALL_DIR)/
  else
		$(CP) $(TOP_DIR)/$(APP_TARGET) $(FS_ROOT)/usr/bin/
  endif
endif


ifneq ($(strip $(SLAVE_FS_ROOT)),)
  ifneq ($(strip $(INSTALL_DIR)),)
		$(CP) $(TOP_DIR)/$(APP_TARGET) $(SLAVE_FS_ROOT)/$(INSTALL_DIR)/
  else
		$(CP) $(TOP_DIR)/$(APP_TARGET) $(SLAVE_FS_ROOT)/usr/bin/
  endif
endif


ifneq ($(strip $(OUT_PUT_LIB_DIR)),)
	$(CP) $(TOP_DIR)/$(APP_TARGET) $(OUT_PUT_LIB_DIR)/
endif
ifneq ($(strip $(OUT_PUT_INC_DIR)),)
  ifneq ($(strip $(OUT_PUT_INC_FILE1)),)
		$(CP) $(TOP_DIR)/$(OUT_PUT_INC_FILE1) $(OUT_PUT_INC_DIR)/
  endif
  ifneq ($(strip $(OUT_PUT_INC_FILE2)),)
		$(CP) $(TOP_DIR)/$(OUT_PUT_INC_FILE2) $(OUT_PUT_INC_DIR)/
  endif
endif




ifneq ($(strip $(DEBUG_ROOT)),)
  ifneq ($(strip $(INSTALL_DIR)),)
		$(CP) $(TOP_DIR)/$(APP_TARGET) $(DEBUG_ROOT)/$(INSTALL_DIR)/
  else
		$(CP) $(TOP_DIR)/$(APP_TARGET) $(DEBUG_ROOT)/usr/bin/
  endif
endif


ifneq ($(strip $(APP_DIR)),)
	$(RM)	$(APP_TARGET)
endif

