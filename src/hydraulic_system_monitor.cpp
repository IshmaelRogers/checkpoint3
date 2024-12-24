#include "robot_info/hydraulic_system_monitor.h"

// Constructor with default values
HydraulicSystemMonitor::HydraulicSystemMonitor()
    : hydraulic_oil_temperature("N/A"),
      hydraulic_oil_tank_fill_level("N/A"),
      hydraulic_oil_pressure("N/A") {}

// Setter Implementations
void HydraulicSystemMonitor::setHydraulicOilTemperature(const std::string& temp) {
    hydraulic_oil_temperature = temp;
}

void HydraulicSystemMonitor::setHydraulicOilTankFillLevel(const std::string& level) {
    hydraulic_oil_tank_fill_level = level;
}

void HydraulicSystemMonitor::setHydraulicOilPressure(const std::string& pressure) {
    hydraulic_oil_pressure = pressure;
}

// Getter Implementations
std::string HydraulicSystemMonitor::getHydraulicOilTemperature() const {
    return hydraulic_oil_temperature;
}

std::string HydraulicSystemMonitor::getHydraulicOilTankFillLevel() const {
    return hydraulic_oil_tank_fill_level;
}

std::string HydraulicSystemMonitor::getHydraulicOilPressure() const {
    return hydraulic_oil_pressure;
}

std::string HydraulicSystemMonitor::getHydraulicSystemStatus() const {
    return "Temperature: " + hydraulic_oil_temperature + 
           ", Tank Level: " + hydraulic_oil_tank_fill_level + 
           ", Pressure: " + hydraulic_oil_pressure;
}
