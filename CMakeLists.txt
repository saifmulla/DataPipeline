CMAKE_MINIMUM_REQUIRED(VERSION 2.8) #minimum cmake version for building project

# project name
PROJECT(datapipeline)

SET(PROJECT_NAME datapipeline)

# ###############################################
# yes we are building shared libraries
ADD_DEFINITIONS(-DBUILD_SHARED_LIB)
# we are building the code as shared library accordingly we must set a name
SET(SHARED_LIB_NAME DataPipeline)
# executale name
SET(EXECUTABLE_NAME datapipeline)
# ###############################################
# Make VC happy and group all the binary outputs,
# also make sure GMock headers will compile in
# all targets.
IF( MSVC )
	SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/)
	SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/)
	SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib/)
	ADD_DEFINITIONS( -D_VARIADIC_MAX=10)
ENDIF( MSVC )

SET(CMAKE_EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
# set c++11 flags for compiler types
IF ( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
ELSEIF ( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
ELSEIF ( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	# DO something for msc++
ENDIF("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")

# MESSAGE("COMPILER ID " ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER})
# MESSAGE(FATAL_ERROR " flags " ${CMAKE_CXX_FLAGS})
SET(ADDITIONAL_COMP_FLAGS "")

# ##################################################
# create executable target for program
ADD_EXECUTABLE(${EXECUTABLE_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)


# ###############################################
# by default unit tests are disabled
# however to enable them simply supply variable
# BUILD_UNIT_TESTS = ON
OPTION( BUILD_UNIT_TESTS "Build unit tests." OFF )

IF (BUILD_UNIT_TESTS)
	SET(BUILD_UNIT_TESTS ${BUILD_UNIT_TESTS})
ENDIF (BUILD_UNIT_TESTS)

#compile gtest framework for unit testing
# ###############################################
# Enable the CMake built in CTest system if unit
# tests are enabled.
IF( BUILD_UNIT_TESTS)
	# IF( APPLE )
	# 	INCLUDE_DIRECTORIES(libraries/CMake/GTest)
	# ENDIF( APPLE )

	ENABLE_TESTING()
	# ###############################################
	# find package pthreads this is required when 
	# unit testing with gtest 
	FIND_PACKAGE(Threads)
	INCLUDE(external/CMakeLists.txt)
	ADD_SUBDIRECTORY(tests)
ENDIF( BUILD_UNIT_TESTS)

