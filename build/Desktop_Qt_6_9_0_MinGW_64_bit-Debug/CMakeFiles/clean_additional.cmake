# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TranslatorProject_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TranslatorProject_autogen.dir\\ParseCache.txt"
  "TranslatorProject_autogen"
  )
endif()
