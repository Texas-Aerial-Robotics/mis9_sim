cmake_minimum_required(VERSION 2.8.12)
project(example_trigger_light)

find_package(gazebo REQUIRED)
find_package(ignition-transport4 REQUIRED)
# find_package(boost REQUIRED)
# find_package(rendering REQUIRED)
# find_package(common REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")

add_library(ChangeRedLightVisual SHARED ChangeLightVisual.cpp)
target_link_libraries(ChangeRedLightVisual
  ${GAZEBO_LIBRARIES}
  ignition-transport4::ignition-transport4
)
