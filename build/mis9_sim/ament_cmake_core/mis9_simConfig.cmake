# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_mis9_sim_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED mis9_sim_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(mis9_sim_FOUND FALSE)
  elseif(NOT mis9_sim_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(mis9_sim_FOUND FALSE)
  endif()
  return()
endif()
set(_mis9_sim_CONFIG_INCLUDED TRUE)

# output package information
if(NOT mis9_sim_FIND_QUIETLY)
  message(STATUS "Found mis9_sim: 0.0.0 (${mis9_sim_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'mis9_sim' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  message(WARNING "${_msg}")
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(mis9_sim_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${mis9_sim_DIR}/${_extra}")
endforeach()
