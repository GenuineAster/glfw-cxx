set( GLFW-CXX_INCLUDE_DIR "${CMAKE_PROJECT_DIR}/include/" )
set( GLFW_CXX_LIBRARY_DIR "${CMAKE_PROJECT_DIR}/")

mark_as_advanced( GLFW-CXX_INCLUDE_DIR )
mark_as_advanced( GLFW_CXX_LIBRARY_DIR )

include( examples/tutorial/CMakeLists.txt )
