cmake_minimum_required( VERSION 2.8 )
project( glfw-c++ )

set( CMAKE_BUILD_TYPE Release CACHE STRING "Build type." FORCE )
set( GLFW-CXX_BUILD_SHARED_LIBS TRUE CACHE BOOL "Build shared llibraries." )
set( GLFW-CXX_BUILD_DOC FALSE CACHE BOOL "Build Doxygen documentation." )

if(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules/;${CMAKE_MODULE_PATH}")

find_package( glfw3 REQUIRED )

if(UNIX)
	include_directories(${GLFW_INCLUDE_DIRS})
elseif(GLFW_FOUND)
	include_directories(${GLFW_INCLUDE_DIRS})
else()
	set(GLFW_ROOT "" CACHE PATH "GLFW top-level directory")
	message("\n-> GLFW directory not found. Set GLFW_ROOT to GLFW's top-level path;")
	message("--> Containing \"include\"  and \"lib\" directories.")
endif()

if( GLFW-CXX_BUILD_SHARED_LIBS )
        set( LIB_TYPE SHARED )
else()
        set( LIB_TYPE STATIC )
endif()

set(SRC_DIR "src")
set(INC_DIR "include")
set(TEST_DIR "test")

set(
	SOURCES
	${INC_DIR}/${CMAKE_PROJECT_NAME}/glfw-c++.hpp
	${INC_DIR}/${CMAKE_PROJECT_NAME}/Monitor.hpp
	${INC_DIR}/${CMAKE_PROJECT_NAME}/Window.hpp
	${INC_DIR}/${CMAKE_PROJECT_NAME}/Time.hpp
	${INC_DIR}/${CMAKE_PROJECT_NAME}/Version.hpp
	${SRC_DIR}/${CMAKE_PROJECT_NAME}/Monitor.cpp
	${SRC_DIR}/${CMAKE_PROJECT_NAME}/Time.cpp
	${SRC_DIR}/${CMAKE_PROJECT_NAME}/Window.cpp
	${SRC_DIR}/${CMAKE_PROJECT_NAME}/Version.cpp
)

include_directories( ${INC_DIR} )

add_library( ${CMAKE_PROJECT_NAME} ${LIB_TYPE} ${SOURCES} )


if( UNIX )
	target_link_libraries(${CMAKE_PROJECT_NAME} ${GLFW_LIBRARIES})
elseif( GLFW_FOUND )
	target_link_libraries(${CMAKE_PROJECT_NAME} ${GLFW_LIBRARIES})
endif()

if( WIN32 )
	target_link_libraries(${CMAKE_PROJECT_NAME} gdi32)
	target_link_libraries(${CMAKE_PROJECT_NAME} opengl32)
endif()

if( GLFW-CXX_BUILD_DOC )
	add_subdirectory( doc )
endif()
