
#include "robot_info_class.cpp" // Include the RobotInfo class
#include <ros/ros.h>

int main(int argc, char **argv) {
  // Initialize the ROS node
  ros::init(argc, argv, "robot_info_node");
  ros::NodeHandle nh;

  // Create an object of the RobotInfo class
  RobotInfo robotInfo(nh);

  // Set the robot info fields
  robotInfo.setRobotDescription("Robot Brand XYZ");
  robotInfo.setSerialNumber("SN1234567890");
  robotInfo.setIpAddress("192.168.1.100");
  robotInfo.setFirmwareVersion("v1.0.0");

  // Set the loop rate for publishing
  ros::Rate loop_rate(1); // 1 Hz

  while (ros::ok()) {
    // Publish the robot info data
    robotInfo.publish_data();

    // Spin and sleep for loop rate duration
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}