#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Device.h"

class Socket : public Device
{
private:
    bool OnorOff;
    std::vector<std::pair<std::string, float>> Schedule;
    float EnergyUsage;
    std::vector<std::pair<std::string, float>> HistoricEnergyUsage;

public:
    Socket(const std::string& name, bool OnorOff = false, float EnergyUsage = 0.0);
    virtual ~Socket();

    void QuickAction() override;
    void QuickView() const override;

    void TurnOn();
    void TurnOff();
    void SleepTimer();
    void ShowEnergyUsage();
    void HistoricData() const;
    std::string DeviceType() const override { return "Socket"; }
    void SetSchedule();
    void ShowSchedule() const;
};
