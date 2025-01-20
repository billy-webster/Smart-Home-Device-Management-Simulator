#pragma once
#include "Device.h"
#include <vector>
#include <string>

class TemperatureHumiditySensor : public Device
{
private:
	float Temperature;
	float Humidity;
	std::vector<std::pair<float, float>> DataStorage;

public:
	
	TemperatureHumiditySensor(const std::string& name, float Temperature = 0.0, float Humidity = 0.0);
	virtual ~TemperatureHumiditySensor();
	
	void HistoricData() const;
	void UpdateData(float Temperature, float Humidity);
	//no quick action method needed as quick view does same thing
	void QuickView() const override;
	std::string DeviceType() const override { return "TemperatureHumiditySensor"; } // Overrides the virtual device type method to get a unique return per device type
	float GetTemp();
	float GetHumidity();

};

