#include "robot_info/agv_robot_info_class.h"
#include <robotinfo_msgs/RobotInfo10Fields.h>
#include <ros/ros.h>

// Constructor to initialize payload and call parent constructor
AGVRobotInfo::AGVRobotInfo(ros::NodeHandle &nh, double payload) : RobotInfo(nh), maximum_payload(payload) {}

void AGVRobotInfo::setHydraulicOilTemperature(const std::string& temp) {
    hydraulic_monitor.setHydraulicOilTemperature(temp);
}

void AGVRobotInfo::setHydraulicOilTankFillLevel(const std::string& level) {
    hydraulic_monitor.setHydraulicOilTankFillLevel(level);
}

void AGVRobotInfo::setHydraulicOilPressure(const std::string& pressure) {
    hydraulic_monitor.setHydraulicOilPressure(pressure);
}

// Overriding publish_data() to add maximum_payload as data_field_06
void AGVRobotInfo::publish_data() {
    robotinfo_msgs::RobotInfo10Fields msg;
    
    msg.data_field_01 = "robot_description: " + getRobotDescription();
    msg.data_field_02 = "serial_number: " + getSerialNumber();
    msg.data_field_03 = "ip_address: " + getIpAddress();
    msg.data_field_04 = "firmware_version: " + getFirmwareVersion();

    // Add AGV-specific payload to field 05
    msg.data_field_05 = "maximum_payload: " + std::to_string(static_cast<int>(maximum_payload)) + " Kg";

    // Populate hydraulic system data
    msg.data_field_06 = "hydraulic_oil_temperature: " + hydraulic_monitor.getHydraulicOilTemperature();
    msg.data_field_07 = "hydraulic_oil_tank_fill_level: " + hydraulic_monitor.getHydraulicOilTankFillLevel();
    msg.data_field_08 = "hydraulic_oil_pressure: " + hydraulic_monitor.getHydraulicOilPressure();


    pub_.publish(msg);  // Publish the message using the base class publisher
    ROS_INFO("AGV Info Published: %s, Payload: %f Kg", getRobotDescription().c_str(), maximum_payload);
}

