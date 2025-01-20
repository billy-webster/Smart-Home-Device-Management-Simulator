#pragma once
#include "Device.h"


class Light : public Device
{
private:
	bool OnorOff;
	int BrightnessLevel;
	int sleeptime;

public:
	Light(const std::string& name, bool OnorOff = false, int BrightnessLevel = 100);
	virtual ~Light();
	
	virtual void QuickAction() override;
	void QuickView() const override;
	void TurnOff();
	void TurnOn();
	void ChangeBrightness(int input);
	std::string DeviceType() const override { return "Light"; }
	bool GetOn();
	int getBrightness();
	/*void SleepTimer(int time);*/
	void SleepTimer(int time);
	
};



