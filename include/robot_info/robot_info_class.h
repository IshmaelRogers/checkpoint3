#ifndef ROBOT_INFO_CLASS_H
#define ROBOT_INFO_CLASS_H

#include <ros/ros.h>
#include <robotinfo_msgs/RobotInfo10Fields.h>
#include <string>

class RobotInfo {
public:
    RobotInfo(ros::NodeHandle &nh);

    virtual void publish_data();
    
    void setRobotDescription(const std::string& description);
    void setSerialNumber(const std::string& serial);
    void setIpAddress(const std::string& ip);
    void setFirmwareVersion(const std::string& version);

    std::string getRobotDescription() const;
    std::string getSerialNumber() const;
    std::string getIpAddress() const;
    std::string getFirmwareVersion() const;

private:
    ros::NodeHandle nh_;
    std::string robot_description;
    std::string serial_number;
    std::string ip_address;
    std::string firmware_version;
protected:
    ros::Publisher pub_;
};

#endif // ROBOT_INFO_CLASS_H
