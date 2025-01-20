#include "HeatingThermostat.h"
#include <iostream>

HeatingThermostat::HeatingThermostat(const std::string& name, float Temperature, bool OnorOff)
    : Device(name), Temperature(Temperature), OnorOff(OnorOff), BoostMultiplier(0.0), OriginalTemperature(Temperature) {}

HeatingThermostat::~HeatingThermostat() {}



void HeatingThermostat::QuickAction() {
    OnorOff = !OnorOff;

    if (OnorOff) {
        std::cout << NameGetter() << " is now On\n";
    }
    else {
        std::cout << NameGetter() << " is now Off\n";
    }
}


void HeatingThermostat::QuickView() const {
    std::cout << NameGetter() << ": ";
    if (OnorOff) {
        std::cout << "On";
    }
    else {
        std::cout << "Off";
    }
    std::cout << " Current Temperature: " << Temperature << "Degrees";

}

void HeatingThermostat::SetTemperature(float Temperature) {
    if (Temperature < 0 || Temperature > 100) {
        std::cout << "Invalid temperature! Please enter a value between 0 and 100 Degrees.";
    }
    else {
        this->Temperature = Temperature;
        std::cout << "Temperature set to " << Temperature << " Degrees";
    }
}


void HeatingThermostat::TurnOn() {
    OnorOff = true;
    std::cout << NameGetter() << " is now On";
}

void HeatingThermostat::TurnOff() {
    OnorOff = false;
    std::cout << NameGetter() << " is now Off";
}


void HeatingThermostat::SetSchedule() {
    std::string scheduletime;
    float scheduletemperature;

    std::cout << "Enter time for the schedule: ";
    std::cin >> scheduletime;

    std::cout << "Enter temperature for the schedule: ";
    std::cin >> scheduletemperature;

    if (scheduletemperature < 0 || scheduletemperature > 100) {
        std::cout << "Invalid temperature! Please enter a value between 0 and 100 Degrees.";
        return;
    }

    Schedule.push_back({ scheduletime, scheduletemperature });
    std::cout << "Scheduled for " << scheduletime << " at " << scheduletemperature << " Degrees";
}


void HeatingThermostat::ShowSchedule() const {
    if (Schedule.empty()) {
        std::cout << "No schedules set for " << NameGetter() << ".";
    }
    else {
        std::cout << "Schedules for " << NameGetter() << ":";
        std::vector<std::pair<std::string, float>>::const_iterator iterator = Schedule.begin();

        while (iterator != Schedule.end()) {
            std::cout << "Scheduled for " << (*iterator).first << " at " << (*iterator).second << "Degrees";
            ++iterator;
        }
    }
}


void HeatingThermostat::HeatingBoost() {
    std::cout << "Enter Heating Boost multiplier: ";
    std::cin >> BoostMultiplier;

    if (BoostMultiplier <= 0) {
        std::cout << "Invalid multiplier, Please enter a value greater than 0.";
        return;
    }

    OriginalTemperature = Temperature;

    if (Temperature * BoostMultiplier > 100) {
        Temperature = 100;
    }
    else {
        Temperature *= BoostMultiplier;
    }

    std::cout << "Heating boost enabled, current temperature: " << Temperature << " Degrees";
}

void HeatingThermostat::StopHeatingBoost() {
    Temperature = OriginalTemperature;
    std::cout << "Heating boost disabled, temperature reset to: " << Temperature << " Degrees";
}


bool HeatingThermostat::GetOn() {
    return OnorOff;
}

int HeatingThermostat::GetTemp() {
    return Temperature;
}