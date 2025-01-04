set(SRC_FILES "main.c" "topologies.c")  # Source files for the executable

add_executable(${PROJECT_NAME} ${SRC_FILES})



target_include_directories(${PROJECT_NAME} 
    PRIVATE 
        "${PROJECT_BINARY_DIR}"
)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC 
        graph 
        glthread
        utils
)

target_compile_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-Wall -Wextra>)

