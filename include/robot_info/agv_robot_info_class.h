#ifndef AGV_ROBOT_INFO_CLASS_H
#define AGV_ROBOT_INFO_CLASS_H

#include "robot_info/robot_info_class.h"

// AGVRobotInfo class derived from RobotInfo
class AGVRobotInfo : public RobotInfo {
public:
    AGVRobotInfo(ros::NodeHandle &nh, double payload);

    void publish_data() override;  // Override to extend the data

private:
    double maximum_payload;  // Additional payload member
};

#endif // AGV_ROBOT_INFO_CLASS_H
