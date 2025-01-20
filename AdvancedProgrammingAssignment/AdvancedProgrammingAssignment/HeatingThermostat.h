#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "Device.h"

class HeatingThermostat : public Device
{
private:
    bool OnorOff;
    float Temperature;
    float BoostMultiplier;
    float OriginalTemperature;
    std::vector<std::pair<std::string, float>> Schedule;

public:
    HeatingThermostat(const std::string& name, float Temperature = 0.0, bool OnorOff = false);
    virtual ~HeatingThermostat();

    void TurnOn();
    void TurnOff();
    void QuickAction() override;
    void QuickView() const override;
    void SetTemperature(float Temperature);
    void SetSchedule();
    void ShowSchedule() const;
    std::string DeviceType() const override { return "HeatingThermostat"; }
    void HeatingBoost();
    void StopHeatingBoost();
    bool GetOn();
    int GetTemp();

  
};
