    #include "Light.h"
#include "Device.h"
#include <chrono>
#include <thread>


Light::Light(const std::string& name, bool OnorOff, int BrightnessLevel)
    : Device(name),
    OnorOff(OnorOff),
    BrightnessLevel(BrightnessLevel),
    sleeptime(0)
{}


Light::~Light() {}

void Light::QuickAction() {
    OnorOff = !OnorOff;

    if (OnorOff) {
        std::cout << NameGetter() << " is now On";;
    }
    else {
        std::cout << NameGetter() << " is now Off";
    }
}


void Light::TurnOn() {
    OnorOff = true;
    std::cout << NameGetter() << "is now On";
}
void Light::TurnOff() {
    OnorOff = false;
    std::cout << NameGetter() << "is now Off";
}

void Light::ChangeBrightness(int input) {
    if (input < 0 || input > 100) {
        std::cout << "Please input in acepted range: 0-100";
        return;
    }
    BrightnessLevel = input;
    std::cout << "Brightness is now set to:" << BrightnessLevel << "%";
}

void Light::QuickView() const {
    std::cout << NameGetter() << ": ";
    if (OnorOff) {
        std::cout << "On";
    }
    else {
        std::cout << "Off";
    }
    std::cout << "Brightness Level: " << BrightnessLevel << "%\n";
}




void Light::SleepTimer(int minutes) {
    std::cout << "Light will turn off for " << minutes << " minute(s).\n";
    TurnOff();
    //std::this_thread::sleep_for(std::chrono::minutes(minutes));
    TurnOn();
    std::cout << "Light turned back on after " << minutes << " minute(s).\n";
}
bool Light::GetOn() {
    return OnorOff;
}

int Light::getBrightness() {
    return BrightnessLevel;
}
