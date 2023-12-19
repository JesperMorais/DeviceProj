#include "deviceManager.h"
#include <iostream>
#include "device.h"
using namespace std;


void deviceManager::creatNewDevice(string name) {
	if (deviceList.size() == 0)
	{
		device* newDevice = new device(name);
		deviceList.push_back(newDevice);
		cout << "Device created" << endl;
	}
	else
	{
		for (int i = 0; i < deviceList.size(); i++)
		{
			if (deviceList[i]->getName() == name)
			{
				cout << "Device name already exists" << endl;
				return;
			}
		}
		device* newDevice = new device(name);
		deviceList.push_back(newDevice);
		cout << "Device created" << endl;
	}	
	return;
}

device* deviceManager::getDevice(string name) {
	for (int i = 0; i < deviceList.size(); i++)
	{
		if (deviceList[i]->getName() == name)
		{
			return deviceList[i];
		}
	}
	cout << "Device does not exist" << endl;
	return nullptr;
}

void deviceManager::deleteDevice(device* deletDevice) {

	for (int i = 0; i < deviceList.size(); i++)
	{
		if (deviceList[i]->getName() == deletDevice->getName())
		{
			delete deletDevice;
			deviceList.erase(deviceList.begin() + i);
			cout << "Device deleted" << endl;
			return;
		}
	}
	cout << "Device does not exist" << endl;
	return;
}

void deviceManager::connectDevice(device* BaseDevice) {
	string name;
	cout << "Enter name of device to connect to: ";
	
	cin >> name;
	if (name == BaseDevice->getName())
	{
		cout << "You can't connect a device to itself" << endl;
		return;
	}

	device* connectDevice = getDevice(name);
	if (connectDevice != nullptr) {
		BaseDevice->AddConnectedDevice(connectDevice);
	}
	return;
}

void deviceManager::PingDevice(device* deviceInput) {
	deviceInput->pingDevice();
}

void deviceManager::printAllDevices() {
	cout << endl;

	for (int i = 0; i < deviceList.size(); i++)
	{
		cout << deviceList[i]->getName();
		if (deviceList[i]->getConnectedDevice() != nullptr)
		{
			cout << " - Connected to: " << deviceList[i]->getConnectedDevice()->getName() << endl;
		}
		else
		{
			cout << endl;
		}		
	}
	return;
}

void deviceManager::disconnectDevice(device* InputDevice) {
	InputDevice->AddConnectedDevice(nullptr);
	return;
}