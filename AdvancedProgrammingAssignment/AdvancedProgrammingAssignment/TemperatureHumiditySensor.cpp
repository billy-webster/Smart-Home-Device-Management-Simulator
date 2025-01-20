#include "TemperatureHumiditySensor.h"
#include <iostream>

TemperatureHumiditySensor::TemperatureHumiditySensor(const std::string& name, float Temperature, float Humidity)
    : Device(name), Temperature(Temperature), Humidity(Humidity) {}

TemperatureHumiditySensor::~TemperatureHumiditySensor() {}

void TemperatureHumiditySensor::QuickView() const {
    std::cout << Name << ": " << Temperature << "Degrees, " << Humidity << "% humidity\n";
}

void TemperatureHumiditySensor::UpdateData(float Temperature, float Humidity) {
    this->Temperature = Temperature;
    this->Humidity = Humidity;
    DataStorage.push_back({ Temperature, Humidity });
    std::cout << "Updated data: " << Temperature << "Degrees, " << Humidity << "% humidity\n";
}


void TemperatureHumiditySensor::HistoricData() const{
    std::vector<std::pair<float, float>>::const_iterator iterator = DataStorage.begin();

    while (iterator != DataStorage.end()) {
        std::cout << "Temperature: " << (*iterator).first << "Degrees, Humidity: " << (*iterator).second << "%\n";
        ++iterator;
    }
}

float TemperatureHumiditySensor::GetTemp() {
    return Temperature;
}

float TemperatureHumiditySensor::GetHumidity() {
    return Humidity;
}