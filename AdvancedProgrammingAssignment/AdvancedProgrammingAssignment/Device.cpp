
#include "Device.h"

Device::Device(const std::string& name) : Name(name) {   // Base class for all child classes to inherit from

}

Device::~Device() {};

void Device::NameSetter(const std::string& Name) {
	this->Name = Name;
};
std::string Device::NameGetter() const {
    return Name;
}



void Device::QuickAction() {};
void Device::QuickView() const {}; 
