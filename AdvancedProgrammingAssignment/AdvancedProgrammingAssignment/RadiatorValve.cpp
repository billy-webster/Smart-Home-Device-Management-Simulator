#include "RadiatorValve.h"
#include <iostream>

RadiatorValve::RadiatorValve(const std::string Name, float Temperature, bool OnorOff)
    : Device(Name), Temperature(Temperature), OnorOff(OnorOff) {}



void RadiatorValve::QuickAction() {
    OnorOff = !OnorOff;

    if (OnorOff) {
        std::cout << NameGetter() << " is now On\n";
    }
    else {
        std::cout << NameGetter() << " is now Off\n";
    }
}

void RadiatorValve::QuickView() const {
    std::cout << NameGetter() << ": ";
    if (OnorOff) {
        std::cout << "On";
    }
    else {
        std::cout << "Off";
    }
    std::cout << " Current Temperature: " << Temperature << " Degrees";
}

void RadiatorValve::UpdateTemp(float Temperature) {
    this->Temperature = Temperature;
    std::cout << "Updated Temperature: " << Temperature << " Degrees\n";
}

void RadiatorValve::TurnOn() {
    OnorOff = true;
    std::cout << NameGetter() << " is now On\n";
}

void RadiatorValve::TurnOff() {
    OnorOff = false;
    std::cout << NameGetter() << " is now Off\n";
}

void RadiatorValve::SetSchedule() {
    std::string scheduletime;
    float scheduletemperature;

    std::cout << "Enter time for the schedule: ";
    std::cin >> scheduletime;

    std::cout << "Enter temperature for the schedule: ";
    std::cin >> scheduletemperature;

    Schedule.push_back({ scheduletime, scheduletemperature });
    std::cout << "Scheduled for " << scheduletime << " at " << scheduletemperature << " Degrees\n";
}

void RadiatorValve::ShowSchedule() const {
    if (Schedule.empty()) {
        std::cout << "There are no schedules for: " << NameGetter() << ".\n";
    }
    else {
        std::cout << "Schedules: " << NameGetter() << ":\n";
        std::vector<std::pair<std::string, float>>::const_iterator iterator = Schedule.begin();

        while (iterator != Schedule.end()) {
            std::cout << NameGetter() << " scheduled for " << (*iterator).first << " at " << (*iterator).second << " Degrees\n";
            ++iterator;
        }
    }
}


bool RadiatorValve::getOn() {
    return OnorOff;
}

int RadiatorValve::GetTemp() {
    return Temperature;
}