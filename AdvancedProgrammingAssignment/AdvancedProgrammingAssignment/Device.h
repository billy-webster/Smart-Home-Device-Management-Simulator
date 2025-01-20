#pragma once
#include <iostream>
#include <string>

class Device
{
protected:
	std::string Name;
	
public:
	Device(const std::string& name);
	virtual ~Device();
	virtual void NameSetter(const std::string& Name);
	virtual std::string NameGetter() const;
	virtual std::string DeviceType() const = 0; // Virtual so that each child class can have a unique return 
	virtual void QuickView() const;
	virtual void QuickAction();
	
	
};

