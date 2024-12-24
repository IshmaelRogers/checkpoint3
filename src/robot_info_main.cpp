
#include "robot_info/robot_info_class.h" // Include the header file, not the cpp
#include <ros/ros.h>

int main(int argc, char **argv) {
  // Initialize the ROS node
  ros::init(argc, argv, "robot_info_node");
  ros::NodeHandle nh;

  // Create an object of the RobotInfo class
  RobotInfo robotInfo(nh);

  // Set the robot info fields
  robotInfo.setRobotDescription("Mir100");
  robotInfo.setSerialNumber("567A359");
  robotInfo.setIpAddress("169.254.5.180");
  robotInfo.setFirmwareVersion("3.5.8");

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
