cmake_minimum_required(VERSION 3.20)
project(tcp_ip_stack VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 99)  
set(CMAKE_C_STANDARD_REQUIRED True)

add_subdirectory(glthread)
add_subdirectory(net)
add_subdirectory(graph)
add_subdirectory(src)
add_subdirectory(doc)
add_subdirectory(commandParser)
add_subdirectory(utils)




