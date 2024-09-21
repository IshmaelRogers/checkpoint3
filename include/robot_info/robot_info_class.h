// robot_info_class.h
#ifndef ROBOT_INFO_CLASS_H
#define ROBOT_INFO_CLASS_H

#include "ros/ros.h"
#include <robotinfo_msgs/RobotInfo10Fields.h>
#include <string>

class RobotInfo {
public:
  // Constructor
  RobotInfo(ros::NodeHandle &nh);

  // Virtual destructor
  virtual ~RobotInfo() {}

  // Virtual method to publish data
  virtual void publish_data();

  // Setter methods
  void setRobotDescription(const std::string &description);
  void setSerialNumber(const std::string &serial);
  void setIpAddress(const std::string &ip);
  void setFirmwareVersion(const std::string &version);

  // Getter methods (needed for derived classes)
  std::string getRobotDescription() const;
  std::string getSerialNumber() const;
  std::string getIpAddress() const;
  std::string getFirmwareVersion() const;

protected:
  ros::Publisher pub_; // Made protected for access in derived classes

private:
  ros::NodeHandle nh_;
  // Robot info fields
  std::string robot_description;
  std::string serial_number;
  std::string ip_address;
  std::string firmware_version;
};

#endif // ROBOT_INFO_CLASS_H
