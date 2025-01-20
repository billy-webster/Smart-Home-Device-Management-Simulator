#pragma once
#include "Device.h"

class Speaker : public Device
{
private:
	int Volume;
	bool OnOrOff;

public:
	Speaker(const std::string& name, int volume = 0, bool OnOrOff = false);
	virtual ~Speaker();

	void QuickAction() override;
	void QuickView() const override;
	void TurnOn();
	void TurnOff();
	void ChangeVolume(int volume);
	std::string DeviceType() const override { return "Speaker"; }
	bool GetOn();
	int GetVolume();

	
};

