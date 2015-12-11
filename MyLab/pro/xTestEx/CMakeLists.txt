cmake_minimum_required(VERSION 2.8.6)

MESSAGE("[MESSAGE] start generate MyLabEx") 
MESSAGE("[MESSAGE] CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")

SET (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(common)
#CXX_OPTIONS()

#SET (CMAKE_USE_RELATIVE_PATHS ON)

PROJECT(MyLabEx)
ADD_EXECUTABLE(xTestEx xTestEx.cpp precompile/xPrecompile.cpp)
INCLUDE_DIRECTORIES("precompile")
INCLUDE_DIRECTORIES("modules/include")
ADD_DEFINITIONS(-D__CXX11_STANDARD)

ADD_SUBDIRECTORY(modules)