set( GLFW-CXX_INCLUDE_DIR "${CMAKE_PROJECT_DIR}/include/" )
set( GLFW_CXX_LIBRARY_DIR "${CMAKE_PROJECT_DIR}/")

mark_as_advanced( GLFW-CXX_INCLUDE_DIR )
mark_as_advanced( GLFW_CXX_LIBRARY_DIR )

execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory examples/simple)
include( ${CMAKE_SOURCE_DIR}/examples/simple/CMakeLists.txt )
