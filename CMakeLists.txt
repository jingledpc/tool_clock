cmake_minimum_required(VERSION 2.8.3)
project(clock_tools)

set(CMAKE_BUILD_TYPE Release)
set(BUILD_STATIC_LIBS ON)
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  rospy
  roscpp
  std_msgs
  sensor_msgs
  rosgraph_msgs
)


###################################
## catkin specific configuration ##
###################################

catkin_package(
  CATKIN_DEPENDS
  rospy
  roscpp
  std_msgs
  sensor_msgs
  rosgraph_msgs
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  ${catkin_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
  "${PROJECT_SOURCE_DIR}/include"
)


add_executable(pubClock src/pubClock.cpp)
target_link_libraries(pubClock ${catkin_LIBRARIES} ${PCL_LIBRARIES})
