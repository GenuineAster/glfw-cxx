
add_custom_target(docs ALL COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/docs/Doxyfile COMMENT "Generating HTML documentation" VERBATIM)

install(
    DIRECTORY ${CMAKE_BINARY_DIR}/docs/html
    DESTINATION ${INSTALL_MISC_DIR}/doc
    COMPONENT doc
)
if(DOXYGEN_HHC_PROGRAM)
    install(
        FILES ${DOXYGEN_OUTPUT_DIR}/${CMAKE_PROJECT_NAME}.chm
        DESTINATION ${INSTALL_MISC_DIR}/doc
        COMPONENT doc
        QUIET
    )
endif()
