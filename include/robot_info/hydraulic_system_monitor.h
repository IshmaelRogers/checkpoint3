#ifndef HYDRAULIC_SYSTEM_MONITOR_H
#define HYDRAULIC_SYSTEM_MONITOR_H

#include <string>

class HydraulicSystemMonitor {
public:
    HydraulicSystemMonitor();

    // Setter methods
    void setHydraulicOilTemperature(const std::string& temp);
    void setHydraulicOilTankFillLevel(const std::string& level);
    void setHydraulicOilPressure(const std::string& pressure);

    // Getter methods
    std::string getHydraulicOilTemperature() const;
    std::string getHydraulicOilTankFillLevel() const;
    std::string getHydraulicOilPressure() const;

    // Retrieve all attributes as a formatted string
    std::string getHydraulicSystemStatus() const;

private:
    std::string hydraulic_oil_temperature;
    std::string hydraulic_oil_tank_fill_level;
    std::string hydraulic_oil_pressure;
};

#endif  // HYDRAULIC_SYSTEM_MONITOR_H
