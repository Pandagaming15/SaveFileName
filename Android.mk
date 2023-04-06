LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := SaveFileName
LOCAL_LDLIBS := -llog
LOCAL_SRC_FILES := main.cpp library.cpp ARMHook/CHook.cpp ARMHook/CPatch.cpp ARMHook/Substrate/SubstrateHook.cpp ARMHook/Substrate/SubstratePosixMemory.cpp ARMHook/Substrate/SubstrateDebug.cpp mod/config.cpp mod/logger.cpp
LOCAL_CFLAGS += -w -O3 -mfloat-abi=softfp -mfpu=neon -DNDEBUG -DANDROID -std=c++17
LOCAL_C_INCLUDES += ./include
include $(BUILD_SHARED_LIBRARY)
