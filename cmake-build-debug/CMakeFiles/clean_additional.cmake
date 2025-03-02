# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/QGraph_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/QGraph_autogen.dir/ParseCache.txt"
  "QGraph_autogen"
  )
endif()
