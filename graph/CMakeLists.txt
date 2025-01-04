set(LIB_NAME "graph")
add_library(${LIB_NAME} STATIC graph.c)
target_link_libraries(${LIB_NAME} PUBLIC 
    glthread
    net
)
target_include_directories(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})