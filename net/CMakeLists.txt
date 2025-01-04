set(LIB_NAME "net")
add_library(${LIB_NAME} STATIC net.c)
target_link_libraries(${LIB_NAME} PUBLIC 
    glthread
    graph
    utils
    )
target_include_directories(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})