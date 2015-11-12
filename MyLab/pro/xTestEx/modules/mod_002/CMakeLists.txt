cmake_minimum_required(VERSION 2.8.6)

MESSAGE("[MESSAGE] start generate mod_002") 

#ADD_LIBRARY(mod_002 SHARED code/test_mod.cpp)
CXX_STANDARD_SHR_PRJ_WITH_PRECOMPILER(mod_002 ../../precompile xPrecompile.h xPrecompile.cpp)
#INCLUDE_DIRECTORIES("module/include")