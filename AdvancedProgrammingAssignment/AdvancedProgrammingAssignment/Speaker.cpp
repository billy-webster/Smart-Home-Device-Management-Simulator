
#include "Speaker.h"
#include <iostream>


Speaker::Speaker(const std::string & name, int volume, bool OnOrOff)
    : Device(name), Volume(volume), OnOrOff(OnOrOff) {}


Speaker::~Speaker() {}

void Speaker::TurnOn() {
    OnOrOff = true;
    std::cout << NameGetter() << " Is now on";
}

void Speaker::TurnOff() {
    OnOrOff = false;
    std::cout << NameGetter() << " Is now off";
}

void Speaker::QuickView() const {
    std::cout << NameGetter() << ": ";
    if (OnOrOff) {
        std::cout << "On";
    }
    else {
        std::cout << "Off";
    }
    std::cout << "Volume Level: " << Volume << "%";

}


void Speaker::ChangeVolume(int volume) {
    if (volume < 0 || volume > 100) {
        std::cout << "Please input volume in the accepted range: 0-100.";
        return;
    }
    Volume = volume;
    std::cout << NameGetter() << " volume is now set to: " << Volume << "%";

}

void Speaker::QuickAction() {
    OnOrOff = !OnOrOff;

    if (OnOrOff) {
        std::cout << NameGetter() << " is now On.";
    }
    else {
        std::cout << NameGetter() << " is now Off.";
    }
}


bool Speaker::GetOn() {
    return OnOrOff;
}

int Speaker::GetVolume() {
    return Volume;
}