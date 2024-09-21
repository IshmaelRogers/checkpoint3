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

## Declare C++ executables
add_executable(robot_info_node src/robot_info_main.cpp src/robot_info_class.cpp)
add_executable(agv_robot_info_node src/agv_robot_info_class.cpp src/robot_info_class.cpp)

## Add dependencies to ensure messages are built before this node
add_dependencies(robot_info_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(agv_robot_info_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link against
target_link_libraries(robot_info_node
  ${catkin_LIBRARIES}
)

target_link_libraries(agv_robot_info_node
  ${catkin_LIBRARIES}
)

