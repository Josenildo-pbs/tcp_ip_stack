set(LIB_NAME "glthread")
add_library(${LIB_NAME} STATIC glthread.c)
target_include_directories(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})