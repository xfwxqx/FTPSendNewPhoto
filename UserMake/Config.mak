CROSS_COMPILER_PREFIX:=arm-linux-
TARGET_OS?=linux
TARGET_ARCH?=arm
TARGET_ENDIAN=default-endian		#[big-endian,little-endian,default-endian]
APP_DEBUG:=no 				#[yes,no]


CROSS_COMPILER_ROOT:=/usr/local/arm_linux_4.8
ifneq ($(strip $(CROSS_COMPILER_ROOT)),)
ifeq ($(strip $(CROSS_COMPILER_CMD_PATH)),)
	CROSS_COMPILER_CMD_PATH:=$(strip $(CROSS_COMPILER_ROOT))/bin
endif
endif

HISDK_ROOT:=
HISDK_TOOLS_PATH:=
ifneq ($(strip $(HISDK_ROOT)),)
ifeq ($(strip $(HISDK_TOOLS_PATH)),)
	HISDK_TOOLS_PATH:=$(strip $(HISDK_ROOT))/tools/bin
endif
endif

DRV_HEAD:=$(CURDIR)/drv_inc
PRIVATE_LIB:=$(CURDIR)/Lib
PRIVATE_INC:=$(CURDIR)/include




INCLUDE_DIR:=$(DRV_HEAD) $(PRIVATE_INC) $(PRIVATE_INC)/webinc
ifeq ($(strip $(APP_DEBUG)),yes)
	LIB_DIR:=$(PRIVATE_LIB)
else
	LIB_DIR:=$(PRIVATE_LIB)
endif
LIB:=pthread m crypt rt dl webs LocalAppPublicLib sqlite3 iksemel pm5kttbi halapilib pm5kpcm netsnmp iconv
DLL:=
LIB_STATIC=no				#[yes,no]
STRIP_TARGET:=yes			#[yes,no]



APP_TARGET:=photoUpload
TOP_DIR:=
SOURCE_DIR:=source
USER_MACRO:=PLATFORM_OF_NUC972
APP_DIR:=App
#DOWNLOAD_DIR:=/mnt/hgfs/Download
#NFS_DIR:=/home/share
#FS_ROOT:=/opt/rootfs
INSTALL_DIR:=dvs
#DEBUG_ROOT:=$(HISDK_ROOT)/rootfs-FULL_DBG
SOURCE:= $(wildcard *.c)


