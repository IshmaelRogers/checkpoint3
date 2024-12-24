#include "robot_info/agv_robot_info_class.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "agv_robot_info_node");
    ros::NodeHandle nh;

    AGVRobotInfo agvRobot(nh, 100);  // Example: 750 kg payload

    // Inherit and set base class fields
    agvRobot.setRobotDescription("Mir100");
    agvRobot.setSerialNumber("567A359");
    agvRobot.setIpAddress("169.254.5.180");
    agvRobot.setFirmwareVersion("3.5.8");

    ros::Rate loop_rate(1);  // 1 Hz publishing rate

    while (ros::ok()) {
        agvRobot.publish_data();
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
