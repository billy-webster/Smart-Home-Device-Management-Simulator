#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "Device.h"
#include "Speaker.h"
#include "HeatingThermostat.h"
#include "RadiatorValve.h"
#include "Light.h"
#include "TemperatureHumiditySensor.h"
#include <thread>  
#include <chrono> 
#include <cstdlib> 

void clearScreen() {  // Clear screen function to reset the console after an input for cleanup  
    
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void loadDevices(const std::string& filename, std::vector<Device*>& devices) {  //Reads txt file and creates an array of pointers to objects to store them
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string devicetype;
            std::string name;
            int volume;
            float temperature;
            float humidity;
            bool OnorOff;

            std::getline(ss, devicetype, ',');
            std::getline(ss, name, ',');
            std::string onOffString;
            std::getline(ss, onOffString, ',');
            OnorOff = (onOffString == "1");

            if (devicetype == "Speaker") {
                ss >> volume;
                devices.push_back(new Speaker(name, volume, OnorOff));
            }
            else if (devicetype == "HeatingThermostat") {
                ss >> temperature;
                devices.push_back(new HeatingThermostat(name, temperature, OnorOff));
            }
            else if (devicetype == "RadiatorValve") {
                ss >> temperature;
                devices.push_back(new RadiatorValve(name, temperature, OnorOff));
            }
            else if (devicetype == "Light") {
                ss >> temperature;
                devices.push_back(new Light(name, OnorOff, temperature));
            }
            else if (devicetype == "TemperatureHumiditySensor") {
                ss >> temperature >> humidity;
                devices.push_back(new TemperatureHumiditySensor(name, temperature, humidity));
            }
            else {
                std::cout << "Unknown device: " << devicetype;
            }
        }
    }
    else {
        std::cout << "Failed to open: " << filename;
    }
}


bool CompareName(Device* a, Device* b) {
    return a->NameGetter() < b->NameGetter();            // Returns the smaller alphabetical name
}

bool CompareByType(Device* a, Device* b) {              
    return a->DeviceType() < b->DeviceType();
}

void sortDevicesByName(std::vector<Device*>& devices) {
    std::sort(devices.begin(), devices.end(), CompareName);
    std::cout << "\nDevices sorted by name.\n";
    std::cout << "\nDo you wish to return to main menu? Y/N \n";
    
    std::this_thread::sleep_for(std::chrono::seconds(2));
    clearScreen();
    
}

void sortDevicesByType(std::vector<Device*>& devices) {
    std::sort(devices.begin(), devices.end(), CompareByType);
    std::cout << "\nDevices sorted by type.\n";
    std::string answer;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    clearScreen();
 
    
}



void showDeviceMenu() {                          // Output main menu screen
    std::cout << "\nMenu:\n";
    std::cout << "1. View all devices\n";
    std::cout << "2. Perform quick action on a device\n";
    std::cout << "3. Sort devices by name\n";
    std::cout << "4. Sort devices by type\n";
    std::cout << "5. Select device to interact with its full feature set\n";
    std::cout << "6. Add a new device\n";
    std::cout << "7. Exit\n";
}


void displaySpeakerFeatures(Device* device) {             // Secondary menu for every device
    std::cout << "\n--- Speaker Features ---\n";
    std::cout << "1. Turn On\n";
    std::cout << "2. Turn Off\n";
    std::cout << "3. Change Volume\n";
    std::cout << "4. Quick View\n";
    std::cout << "5. Delete Device\n";
    std::cout << "6. Change Name\n";
    std::cout << "Enter your choice: ";

    int choice;
    std::cin >> choice;

    
    Speaker* speaker = dynamic_cast<Speaker*>(device);

    if (speaker) {
        switch (choice) {
        case 1:
            speaker->TurnOn();
            std::cout << "Speaker turned on.\n";
            break;

        case 2:
            speaker->TurnOff();
            std::cout << "Speaker turned off.\n";
            break;

        case 3: {
            int volume;
            std::cout << "Enter new volume (0-100): ";
            std::cin >> volume;
            speaker->ChangeVolume(volume);
            std::cout << "Volume set to " << volume << ".\n";
            break;
        }

        case 4:
            std::cout << "\n--- Speaker Quick View ---\n";
            speaker->QuickView(); 
            break;

        case 5:
            std::cout << "Deleting device...\n";
            delete speaker;
            speaker = nullptr;
            device = nullptr;
            break;
        case 6: {
            std::string NewName;
            std::cout << "Enter New Name For Device: ";
            std::cin >> NewName;
            speaker->NameSetter(NewName);
            std::cout << "Name Changed.\n";
            break;
        }

        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
    else {
        std::cout << "Error: Device is not a Speaker.\n";
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    clearScreen();
}


void displayHeatingThermostatFeatures(Device* device) {
    std::cout << "\n--- Heating Thermostat Features ---\n";
    std::cout << "1. Turn On\n";
    std::cout << "2. Turn Off\n";
    std::cout << "3. Set Temperature\n";
    std::cout << "4. Set Schedule\n";
    std::cout << "5. Show Schedule\n";
    std::cout << "6. Activate Heating Boost\n";
    std::cout << "7. Deactivate Heating Boost\n";
    std::cout << "8. Quick View\n";
    std::cout << "9. Delete Device\n";
    std::cout << "10. Change Name\n";
    std::cout << "Enter your choice: ";

    int choice;
    std::cin >> choice;

    HeatingThermostat* thermostat = dynamic_cast<HeatingThermostat*>(device);

    if (thermostat) {
        switch (choice) {
        case 1:
            thermostat->TurnOn();
            std::cout << "Heating Thermostat turned on.\n";
            break;

        case 2:
            thermostat->TurnOff();
            std::cout << "Heating Thermostat turned off.\n";
            break;

        case 3: {
            float temperature;
            std::cout << "Enter new temperature: ";
            std::cin >> temperature;
            thermostat->SetTemperature(temperature);
            std::cout << "Temperature set to " << temperature << "°C.\n";
            break;
        }

        case 4:
            thermostat->SetSchedule();
            std::cout << "Schedule set.\n";
            break;

        case 5:
            thermostat->ShowSchedule();
            break;

        case 6:
            thermostat->HeatingBoost();
            std::cout << "Heating Boost activated.\n";
            break;

        case 7:
            thermostat->StopHeatingBoost();
            std::cout << "Heating Boost deactivated.\n";
            break;

        case 8:
            std::cout << "\n--- Heating Thermostat Quick View ---\n";
            thermostat->QuickView();
            break;

        case 9:
            std::cout << "Deleting device...\n";
            delete thermostat;
            thermostat = nullptr;
            device = nullptr;
            break;
        case 10: {
            std::string NewName;
            std::cout << "Enter New Name For Device: ";
            std::cin >> NewName;
            thermostat->NameSetter(NewName);
            std::cout << "Name Changed.\n";
            break;
        }

        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
    else {
        std::cout << "Error: Device is not a Heating Thermostat.\n";
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    clearScreen();
}


void displayRadiatorValveFeatures(Device* device) {
    std::cout << "\n--- Radiator Valve Features ---\n";
    std::cout << "1. Turn On\n";
    std::cout << "2. Turn Off\n";
    std::cout << "3. Set Temperature\n";
    std::cout << "4. Quick View\n";
    std::cout << "5. Delete Device\n";
    std::cout << "6. Change Name\n";
    std::cout << "Enter your choice: ";

    int choice;
    std::cin >> choice;

    RadiatorValve* valve = dynamic_cast<RadiatorValve*>(device);

    if (valve) {
        switch (choice) {
        case 1:
            valve->TurnOn();
            std::cout << "Radiator Valve turned on.\n";
            break;

        case 2:
            valve->TurnOff();
            std::cout << "Radiator Valve turned off.\n";
            break;

        case 3: {
            float temperature;
            std::cout << "Enter new temperature: ";
            std::cin >> temperature;
            valve->UpdateTemp(temperature);
            std::cout << "Temperature set to " << temperature << "°C.\n";
            break;
        }

        case 4:
            std::cout << "\n--- Radiator Valve Quick View ---\n";
            valve->QuickView();
            break;

        case 5:
            std::cout << "Deleting device...\n";
            delete valve;
            valve = nullptr;
            device = nullptr;
            break;

        case 6: {
            std::string NewName;
            std::cout << "Enter New Name For Device: ";
            std::cin >> NewName;
            valve->NameSetter(NewName);
            std::cout << "Name Changed.\n";
            break;
        }

        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
    else {
        std::cout << "Error: Device is not a Radiator Valve.\n";
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));
    clearScreen();
}


void displayLightFeatures(Device* device) {
    std::cout << "\n--- Light Features ---\n";
    std::cout << "1. Turn On\n";
    std::cout << "2. Turn Off\n";
    std::cout << "3. Change Brightness\n";
    std::cout << "4. Sleep Timer\n";
    std::cout << "5. Quick View\n";
    std::cout << "6. Delete Device\n";
    std::cout << "7. Change Name\n"; 
    std::cout << "Enter your choice: ";

    int choice;
    std::cin >> choice;

   
    Light* light = dynamic_cast<Light*>(device);

    if (light) {
        switch (choice) {
        case 1:
            light->TurnOn();
            std::cout << "Light turned on.\n";
            break;

        case 2:
            light->TurnOff();
            std::cout << "Light turned off.\n";
            break;

        case 3: {
            int brightness;
            std::cout << "Enter new brightness (0-100): ";
            std::cin >> brightness;
            light->ChangeBrightness(brightness);
            std::cout << "Brightness set to " << brightness << ".\n";
            break;
        }
        case 4: {
            int time;
            std::cout << "Set time you want to sleep in minutes: ";
            std::cin >> time;
            light->SleepTimer(time);
            break; 
        }
        case 5:
            std::cout << "\n--- Light Quick View ---\n";
            light->QuickView();  
            break;

        case 6:
            std::cout << "Deleting device...\n";
            delete light;
            light = nullptr;
            device = nullptr;
            break;
        case 7: {
            std::string NewName;
            std::cout << "Enter New Name For Device: ";
            std::cin >> NewName;
            light->NameSetter(NewName);
            std::cout << "Name Changed.\n";
            break;
        }

        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
    else {
        std::cout << "Error: Device is not a Light.\n";
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    clearScreen();
}



void displayTemperatureHumiditySensorFeatures(Device* device) {
    std::cout << "\n--- Temperature Humidity Sensor Features ---\n";
    std::cout << "1. View Current Data\n";
    std::cout << "2. View Historical Data\n";
    std::cout << "3. Delete Device\n";
    std::cout << "4. Change Name\n";
    std::cout << "Enter your choice: ";

    int choice;
    std::cin >> choice;

    TemperatureHumiditySensor* sensor = dynamic_cast<TemperatureHumiditySensor*>(device);

    if (sensor) {
        switch (choice) {
        case 1:
            sensor->QuickView();
            break;

        case 2:
            sensor->HistoricData();
            break;

        case 3:
            std::cout << "Deleting device...\n";
            delete sensor;
            sensor = nullptr;
            device = nullptr;
            break;
        case 4: {
            std::string NewName;
            std::cout << "Enter New Name For Device: ";
            std::cin >> NewName;
            sensor->NameSetter(NewName);
            std::cout << "Name Changed.\n";
            break;
        }

        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
    else {
        std::cout << "Error: Device is not a Temperature Humidity Sensor.\n";
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    clearScreen();
}



void interactWithDevice(std::vector<Device*>& devices, const std::string& deviceName) {
    bool deviceFound = false;

    for (size_t i = 0; i < devices.size(); ++i) {
        if (devices[i]->NameGetter() == deviceName) {
            deviceFound = true;
            Device* device = devices[i];

            std::cout << "\nInteracting with device: " << deviceName << "\n";

            if (device->DeviceType() == "Speaker") {
                displaySpeakerFeatures(device);
            }
            else if (device->DeviceType() == "HeatingThermostat") {
                displayHeatingThermostatFeatures(device);
            }
            else if (device->DeviceType() == "RadiatorValve") {
                displayRadiatorValveFeatures(device);
            }
            else if (device->DeviceType() == "Light") {
                displayLightFeatures(device);
            }
            else if (device->DeviceType() == "TemperatureHumiditySensor") {
                displayTemperatureHumiditySensorFeatures(device);
            }
            else {
                std::cout << "Unknown device type.\n";
            }

            break;
        }
    }

    if (!deviceFound) {
        std::cout << "Device with name \"" << deviceName << "\" not found.\n";
    }
}

void addDevice(std::vector<Device*>& devices) {
    std::cout << "\n--- Add Device ---\n";
    std::cout << "Select the device type to add:\n";
    std::cout << "1. Speaker\n";
    std::cout << "2. Heating Thermostat\n";
    std::cout << "3. Radiator Valve\n";
    std::cout << "4. Light\n";
    std::cout << "5. Temperature Humidity Sensor\n";
    std::cout << "Enter your choice: ";

    int choice;
    std::cin >> choice;
    std::string name;

    std::cout << "Enter the device name: ";
    std::cin >> name;

    switch (choice) {
    case 1:
        devices.push_back(new Speaker(name, 0, false));  
        std::cout << "Device: " << name << " is successfully created as a Speaker.\n";
        break;
    case 2:
        devices.push_back(new HeatingThermostat(name, 0.0, false)); 
        std::cout << "Device: " << name << " is successfully created as a Heating Thermostat.\n";
        break;
    case 3:
        devices.push_back(new RadiatorValve(name, 0.0, false));  
        std::cout << "Device: " << name << " is successfully created as a Radiator Valve.\n";
        break;
    case 4:
        devices.push_back(new Light(name, false, 0));  
        std::cout << "Device: " << name << " is successfully created as a Light.\n";
        break;
    case 5:
        devices.push_back(new TemperatureHumiditySensor(name, 0.0, 0.0));  
        std::cout << "Device: " << name << " is successfully created as a Temperature Humidity Sensor.\n";
        break;
    default:
        std::cout << "Invalid choice. Device not created.\n";
        break;
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    clearScreen();
}

void saveDevices(const std::string& filename, const std::vector<Device*>& devices) {         // Uses device type to create a new line for each object in the array
    std::ofstream file(filename);
    if (file.is_open()) {
        std::vector<Device*>::const_iterator it = devices.begin();
        while (it != devices.end()) {
            Device* device = *it;

            if (device->DeviceType() == "Speaker") {
                Speaker* speaker = dynamic_cast<Speaker*>(device);
                file << "Speaker," << speaker->NameGetter() << "," << (speaker->GetOn() ? "1" : "0") << "," << speaker->GetVolume() << "\n";  // On or Off stored as 1 or 0
            }
            else if (device->DeviceType() == "HeatingThermostat") {
                HeatingThermostat* thermostat = dynamic_cast<HeatingThermostat*>(device);
                file << "HeatingThermostat," << thermostat->NameGetter() << "," << (thermostat->GetOn() ? "1" : "0") << "," << thermostat->GetTemp() << "\n";
            }
            else if (device->DeviceType() == "RadiatorValve") {
                RadiatorValve* valve = dynamic_cast<RadiatorValve*>(device);
                file << "RadiatorValve," << valve->NameGetter() << "," << (valve->getOn() ? "1" : "0") << "," << valve->GetTemp() << "\n";
            }
            else if (device->DeviceType() == "Light") {
                Light* light = dynamic_cast<Light*>(device);
                file << "Light," << light->NameGetter() << "," << (light->GetOn() ? "1" : "0") << "," << light->getBrightness() << "\n";
            }
            else if (device->DeviceType() == "TemperatureHumiditySensor") {
                TemperatureHumiditySensor* sensor = dynamic_cast<TemperatureHumiditySensor*>(device);
                file << "TemperatureHumiditySensor," << sensor->NameGetter() << "," << sensor->GetTemp() << "," << sensor->GetHumidity() << "\n";
            }

            ++it;
        }
        file.close();
        std::cout << "Devices saved successfully to " << filename << ".\n";
    }
    else {
        std::cout << "Failed to open file: " << filename;
    }
}



int main() {
#ifdef _DEBUG
    _onexit(_CrtDumpMemoryLeaks);
#endif

    std::vector<Device*> devices;
    loadDevices("data.txt", devices);

    int choice;
    do {
        showDeviceMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {              // Switch case for all options on menu
        case 1: {
            clearScreen();
            std::cout << "\n--- Device List ---\n";
            for (size_t i = 0; i < devices.size(); ++i) {
                std::cout << i << ": ";
                devices[i]->QuickView();
                std::cout << "\n";
            }
            std::cout << "\nDo you want to return to the menu? Y/N: ";
            std::string answer;
            std::cin >> answer;    
            if (answer == "Y" || answer == "y") {
                std::this_thread::sleep_for(std::chrono::seconds(2)); 
                clearScreen();  
            }
        }
            break;

        case 2:
            std::cout << "Enter device number (0 to " << devices.size() - 1 << "): ";
            int index;
            std::cin >> index;
            if (index >= 0 && index < devices.size()) {
                devices[index]->QuickAction();
            }
            else {
                std::cout << "Invalid device number";
            }
            break;

        case 3:
            sortDevicesByName(devices);
            break;

        case 4:
            sortDevicesByType(devices);
            break;

        case 5: {
            std::cout << "Enter device name to display full feature set: ";
            std::string deviceName;
            std::cin >> deviceName;
            interactWithDevice(devices, deviceName);
            break;
        }
        case 6: {
            addDevice(devices);
            break;
        }

        case 7:
            std::cout << "Saving and Exiting...\n";
            saveDevices("data.txt", devices);
            break;

        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

        std::this_thread::sleep_for(std::chrono::seconds(2));
        clearScreen();

    } while (choice != 7);


    
    std::vector<Device*>::iterator it = devices.begin();  //Iterator to clean up the pointers for the dynamic array
    while (it != devices.end()) {
        delete* it;
        ++it;
    }

    return 0;
}
