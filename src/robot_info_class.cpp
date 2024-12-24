// roboot info class
#include "ros/node_handle.h"
#include <robotinfo_msgs/RobotInfo10Fields.h>
#include <ros/ros.h>

#include "robot_info/robot_info_class.h"

// Constructor
RobotInfo::RobotInfo(ros::NodeHandle &nh) : nh_(nh) {
    pub_ = nh_.advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 10);
}


void RobotInfo::publish_data() {
    robotinfo_msgs::RobotInfo10Fields msg;
    msg.data_field_01 = "robot_description: " + getRobotDescription();
    msg.data_field_02 = "serial_number: " + getSerialNumber();
    msg.data_field_03 = "ip_address: " + getIpAddress();
    msg.data_field_04 = "firmware_version: " + getFirmwareVersion();


    pub_.publish(msg);

    ROS_INFO("Published robot info: %s, %s, %s, %s", robot_description.c_str(),
                serial_number.c_str(), ip_address.c_str(),
                firmware_version.c_str());
    }

    // Setter methods
void RobotInfo::setRobotDescription(const std::string& description) {
    robot_description = description;
}

void RobotInfo::setSerialNumber(const std::string& serial) {
    serial_number = serial;
}

void RobotInfo::setIpAddress(const std::string& ip) {
    ip_address = ip;
}

void RobotInfo::setFirmwareVersion(const std::string& version) {
    firmware_version = version;
}

// Getter methods
std::string RobotInfo::getRobotDescription() const {
    return robot_description;
}

std::string RobotInfo::getSerialNumber() const {
    return serial_number;
}

std::string RobotInfo::getIpAddress() const {
    return ip_address;
}

std::string RobotInfo::getFirmwareVersion() const {
    return firmware_version;
}