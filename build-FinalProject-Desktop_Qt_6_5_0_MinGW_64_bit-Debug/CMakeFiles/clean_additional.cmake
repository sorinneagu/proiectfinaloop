# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\FinalProject_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FinalProject_autogen.dir\\ParseCache.txt"
  "FinalProject_autogen"
  )
endif()
