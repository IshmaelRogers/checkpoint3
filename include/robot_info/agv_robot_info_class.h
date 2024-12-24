#ifndef AGV_ROBOT_INFO_CLASS_H
#define AGV_ROBOT_INFO_CLASS_H

#include "robot_info/robot_info_class.h"
#include "robot_info/hydraulic_system_monitor.h"

// AGVRobotInfo class derived from RobotInfo
class AGVRobotInfo : public RobotInfo {
public:
    AGVRobotInfo(ros::NodeHandle &nh, double payload);

    void publish_data() override;  // Override to extend the data
    void setHydraulicOilTemperature(const std::string& temp);
    void setHydraulicOilTankFillLevel(const std::string& level);
    void setHydraulicOilPressure(const std::string& pressure);

private:
    double maximum_payload;  // Additional payload member
    HydraulicSystemMonitor hydraulic_monitor;
};

#endif // AGV_ROBOT_INFO_CLASS_H
