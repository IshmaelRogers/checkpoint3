// agv_robot_info_class.cpp
// Derived class for Autonomous Ground Vehicles (AGV) Robot Information

#include "ros/ros.h"
#include "robot_info/robot_info_class.h"  // Include the base class header
#include <robotinfo_msgs/RobotInfo10Fields.h>

// Derived class AGVRobotInfo
class AGVRobotInfo : public RobotInfo {
public:
    // Constructor
    AGVRobotInfo(ros::NodeHandle &nh) : RobotInfo(nh), maximum_payload_(0.0) {
        // Initialize maximum_payload_ if needed
    }

    // Setter for maximum_payload
    void setMaximumPayload(double payload) {
        maximum_payload_ = payload;
    }

    // Overridden publish_data method
    virtual void publish_data() override {
        robotinfo_msgs::RobotInfo10Fields msg;

        // Populate base class data fields
        msg.data_field_01 = getRobotDescription();
        msg.data_field_02 = getSerialNumber();
        msg.data_field_03 = getIpAddress();
        msg.data_field_04 = getFirmwareVersion();

        // Populate derived class data field
        msg.data_field_05 = maximum_payload_;

        // Publish the message
        pub_.publish(msg);

        // Log the published data
        ROS_INFO("Published AGV robot info: %s, %s, %s, %s, Maximum Payload: %.2f",
                 getRobotDescription().c_str(),
                 getSerialNumber().c_str(),
                 getIpAddress().c_str(),
                 getFirmwareVersion().c_str(),
                 maximum_payload_);
    }

private:
    double maximum_payload_;  // Maximum payload the AGV can transport
};

// Main function to build the executable node
int main(int argc, char **argv) {
    // Initialize the ROS system
    ros::init(argc, argv, "agv_robot_info_node");

    // Create a ROS node handle
    ros::NodeHandle nh;

    // Instantiate the AGVRobotInfo object
    AGVRobotInfo agv_robot_info(nh);

    // Set robot information (these values can be parameterized as needed)
    agv_robot_info.setRobotDescription("AGV_Model_XYZ");
    agv_robot_info.setSerialNumber("AGV123456");
    agv_robot_info.setIpAddress("192.168.1.100");
    agv_robot_info.setFirmwareVersion("v1.2.3");
    agv_robot_info.setMaximumPayload(1500.0);  // Example payload in kilograms

    // Set the loop rate (e.g., 1 Hz)
    ros::Rate loop_rate(1);

    // Main loop
    while (ros::ok()) {
        // Publish the AGV robot information
        agv_robot_info.publish_data();

        // Handle ROS callbacks (if any)
        ros::spinOnce();

        // Sleep for the remaining time to enforce the loop rate
        loop_rate.sleep();
    }

    return 0;
}




