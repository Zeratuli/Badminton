# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "Badminton_autogen"
  "CMakeFiles\\Badminton_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Badminton_autogen.dir\\ParseCache.txt"
  )
endif()
