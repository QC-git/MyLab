cmake_minimum_required(VERSION 2.8.6)

MESSAGE("[MESSAGE] start generate mod_001") 

#ADD_LIBRARY(mod_001 STATIC test_mod.cpp)
CXX_STANDARD_LIB_PRJ_WITH_PRECOMPILER(mod_001 ../../precompile xPrecompile.h xPrecompile.cpp)
#INCLUDE_DIRECTORIES("module/include")