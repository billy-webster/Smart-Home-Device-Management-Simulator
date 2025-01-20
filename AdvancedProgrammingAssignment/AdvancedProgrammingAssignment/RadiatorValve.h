#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "Device.h"


class RadiatorValve : public Device
{
private:
	bool OnorOff;
	float Temperature;
	std::vector<std::pair<std::string, float>> Schedule;

public:
	RadiatorValve(const std::string Name, float Temperature = 0.0, bool OnorOff = false);
	

	void QuickView() const override;
	void QuickAction() override;
	std::string DeviceType() const override { return "RadiatorValve"; }
	void UpdateTemp(float Temperature);
	void SetSchedule();
	void ShowSchedule() const;
	void TurnOn();
	void TurnOff();
	bool getOn();
	int GetTemp();


};