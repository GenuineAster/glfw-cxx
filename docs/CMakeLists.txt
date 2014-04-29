
add_custom_target(docs ALL COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/docs/Doxyfile COMMENT "Generating HTML documentation" VERBATIM)

