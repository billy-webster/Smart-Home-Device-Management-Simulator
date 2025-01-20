#include "Socket.h"
#include <iostream>

Socket::Socket(const std::string& name, bool OnorOff, float EnergyUsage)
    : Device(name), OnorOff(OnorOff), EnergyUsage(EnergyUsage) {}

Socket::~Socket() {}

void Socket::QuickAction() {
    OnorOff = !OnorOff;
    if (OnorOff) {
        std::cout << NameGetter() << " is now On";
    }
    else {
        std::cout << NameGetter() << " is now Off";
    }
}

void Socket::QuickView() const {
    std::cout << NameGetter() << ": ";
    if (OnorOff) {
        std::cout << "On";
    }
    else {
        std::cout << "Off";
    }
    std::cout << " Current Energy Usage: " << EnergyUsage << " kWh";
}

void Socket::TurnOn() {
    OnorOff = true;
    std::cout << NameGetter() << " is now On";
}

void Socket::TurnOff() {
    OnorOff = false;
    std::cout << NameGetter() << " is now Off";
}

void Socket::SetSchedule() {
    std::string scheduletime;
    float scheduleenergy;

    std::cout << "Enter time for the schedule: ";
    std::cin >> scheduletime;

    std::cout << "Enter energy usage for the schedule per hour: ";
    std::cin >> scheduleenergy;

    if (scheduleenergy < 0) {
        std::cout << "Invalid input, Please enter a value greater than 0 kWh per hour.";
        return;
    }

    Schedule.push_back({ scheduletime, scheduleenergy });
    std::cout << "Scheduled for " << scheduletime << " with " << scheduleenergy << " kWh per hour energy usage.";
}

void Socket::ShowSchedule() const {
    if (Schedule.empty()) {
        std::cout << "No schedules set for " << NameGetter() << ".";
    }
    else {
        std::cout << "Schedules for " << NameGetter() << ":";
        std::vector<std::pair<std::string, float>>::const_iterator iterator = Schedule.begin();

        while (iterator != Schedule.end()) {
            std::cout << "Scheduled for " << (*iterator).first << " with " << (*iterator).second << " kWh per hour energy usage.";
            ++iterator;
        }
    }
}

void Socket::SleepTimer() {
    int duration;
    std::cout << "Enter sleep time in minutes: ";
    std::cin >> duration;

    TurnOff();
    std::cout << NameGetter() << " is now off. Turning off for " << duration << " minutes";

    TurnOn();
    std::cout << NameGetter() << " is now turned on";
}

void Socket::ShowEnergyUsage() {

}

void Socket::HistoricData() const {
}