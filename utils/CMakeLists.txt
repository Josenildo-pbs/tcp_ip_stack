set(LIB_NAME "utils")
add_library(${LIB_NAME} INTERFACE)
target_include_directories(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
configure_file("config.h.in" "${PROJECT_BINARY_DIR}/config.h")