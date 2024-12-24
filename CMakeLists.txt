cmake_minimum_required(VERSION 3.0.2)
project(robot_info)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  robotinfo_msgs
  roscpp
  std_msgs
)


###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS robotinfo_msgs roscpp
)

###########
## Build ##
###########

## Specify additional locations of header files
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a shared library for the RobotInfo class
add_library(robot_info_lib src/robot_info_class.cpp)

## Declare C++ executables
add_executable(robot_info_node src/robot_info_main.cpp)
add_executable(agv_robot_info_node src/agv_robot_info_class.cpp src/agv_robot_info_main.cpp)

## Link the library to both executables
target_link_libraries(robot_info_node
  robot_info_lib
  ${catkin_LIBRARIES}
)

target_link_libraries(agv_robot_info_node
  robot_info_lib
  ${catkin_LIBRARIES}
)