include_directories("${CMAKE_CURRENT_LIST_DIR}../../include/")
link_directories("${CMAKE_CURRENT_LIST_DIR}../../")

link_libraries( glfw-cxx )

if( UNIX )
	link_libraries( GL )
elseif( WIN32 )
	link_libraries( opengl32 )
elseif( APPLE )
	link_libraries( OpenGL )
endif()

add_executable( examples/tutorial/tutorial examples/tutorial/tutorial.cpp )
