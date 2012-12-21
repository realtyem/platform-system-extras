LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES:= thtt.c
LOCAL_MODULE := thtt
LOCAL_MODULE_TAGS := optional
LOCAL_STATIC_LIBRARIES := libcutils libc
include $(BUILD_EXECUTABLE)


