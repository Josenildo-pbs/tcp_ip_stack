find_package(Doxygen)

if (Doxygen_FOUND)
  
    set(DOXYFILE_PATTERN_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in")
    set(DOXYFILE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/doc/Doxyfile")

    configure_file("${DOXYFILE_PATTERN_PATH}" "${DOXYFILE_OUTPUT_PATH}")
    
    add_custom_target(GenerateDoc
        # ALL
        COMMAND Doxygen::doxygen
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/doc"
        COMMENT "Generating documentation. Please wait..."
    )

else ()
    message("Documentation generation failed !!!")
endif ()