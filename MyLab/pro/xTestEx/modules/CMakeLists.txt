cmake_minimum_required(VERSION 2.8.6)

SET(MODULES mod_001 mod_002)

#MESSAGE("[MESSAGE] start generate modules " ${MODULES}) 
MESSAGE("[MESSAGE] start generate module ${MODULES}") 

FOREACH(module ${MODULES})
  ADD_SUBDIRECTORY(${module})
  #MESSAGE("[MESSAGE] ${module} " ${module})
ENDFOREACH()
