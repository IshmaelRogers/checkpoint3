#include "robot_info/agv_robot_info_class.h"
#include <robotinfo_msgs/RobotInfo10Fields.h>
#include <ros/ros.h>

// Constructor to initialize payload and call parent constructor
AGVRobotInfo::AGVRobotInfo(ros::NodeHandle &nh, double payload) : RobotInfo(nh), maximum_payload(payload) {}

// Overriding publish_data() to add maximum_payload as data_field_06
void AGVRobotInfo::publish_data() {
    robotinfo_msgs::RobotInfo10Fields msg;
    
    msg.data_field_01 = "robot_description: " + getRobotDescription();
    msg.data_field_02 = "serial_number: " + getSerialNumber();
    msg.data_field_03 = "ip_address: " + getIpAddress();
    msg.data_field_04 = "firmware_version: " + getFirmwareVersion();

    // Add AGV-specific payload to field 05
    msg.data_field_05 = "maximum_payload: " + std::to_string(static_cast<int>(maximum_payload)) + " Kg";

    pub_.publish(msg);  // Publish the message using the base class publisher
    ROS_INFO("AGV Info Published: %s, Payload: %f Kg", getRobotDescription().c_str(), maximum_payload);
}

