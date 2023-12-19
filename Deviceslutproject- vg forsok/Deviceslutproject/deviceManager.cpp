#include "deviceManager.h"
#include <iostream>
#include "device.h"
#include <iomanip>
using namespace std;


void deviceManager::creatNewDevice(string name, int type) {
	if (type == 1) {
		if (deviceList.size() == 0)
		{
			device* newDevice = new IoTDevice(name);
			deviceList.push_back(newDevice);
			cout << "IoTDevice created" << endl;
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
			device* newDevice = new IoTDevice(name);
			deviceList.push_back(newDevice);
			cout << "IoTDevice created" << endl;
		}
	}
	else
	{
		if (deviceList.size() == 0)
		{
			device* newDevice = new SuperDevice(name);
			deviceList.push_back(newDevice);
			cout << "SuperDevice created" << endl;
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
			device* newDevice = new SuperDevice(name);
			deviceList.push_back(newDevice);
			cout << "SuperDevice created" << endl;
		}
	
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

void deviceManager::deleteDevice(device* deletDevice) { //fixa så att vi tar bort alla barnen också, rekursivt?

	if (deletDevice->getLeftDevice() != nullptr) //kollar om det finns en left child, om det finns så kallar den på sig själv igen
	{
		deleteDevice(deletDevice->getLeftDevice());
	}
	if (deletDevice->getRightDevice() != nullptr) //kollar om det finns en right child, om det finns så kallar den på sig själv igen
	{
		deleteDevice(deletDevice->getRightDevice());
	}
	for (int i = 0; i < deviceList.size(); i++)
	{
		if (deviceList[i] == deletDevice) //tar bort orginalet från listan
		{
			disconnectDevice(deviceList[i]);
			deviceList.erase(deviceList.begin() + i);
			delete deletDevice;
			cout << "Device deleted" << endl;
			return;
		}
	}

	return;
}

void deviceManager::connectDevice(device* BaseDevice) {
	string name;
	cout << "Enter name of device you want to connect to: ";
	cin >> name;
	device* connectedDevice = getDevice(name);
	device* temp = BaseDevice;

	while (temp->getParent() != nullptr) { //kollar om det finns en parent, om det finns så går den upp en nivå
		if (temp->getParent() == connectedDevice) { //kollar om den är connected till den vi vill connecta till
			cout << "Cycles is not allowed" << endl; 
			return;
		}
		temp = temp->getParent();
	}
	if (BaseDevice->getLeftDevice() == nullptr) { //kollar om left child är ledig
		BaseDevice->setLeftDevice(connectedDevice);
		connectedDevice->setParent(BaseDevice);
		cout << "Device connected" << endl;
		return;
	}
	else if(BaseDevice->getRightDevice() == nullptr) { //kollar om höger är ledig
		BaseDevice->setRightDevice(connectedDevice);
		connectedDevice->setParent(BaseDevice);;
		cout << "Device connected" << endl;
		return;
	}
	else { //om båda är upptagna så säger den att den redan är connected
		cout << "Device is already connected" << endl;
		return;
	}
}

void deviceManager::PingDevice(device* deviceInput) {
	
	if (deviceInput == nullptr) {
		return;
	}
	
	PingDevice(deviceInput->getParent());

	deviceInput->pingDevice();
}



void deviceManager::disconnectDevice(device* InputDevice) {
	if (InputDevice->getParent() == nullptr) //kollar om den är root
	{
		return;
	}
	else
		if (InputDevice->getParent()->getLeftDevice() == InputDevice) //kollar om den är left child
		{
			InputDevice->getParent()->setLeftDevice(nullptr);
			InputDevice->setParent(nullptr);
			cout << "Device disconnected" << endl;
			return;
		}
		else if (InputDevice->getParent()->getRightDevice() == InputDevice) //kollar om den är right child
		{
			InputDevice->getParent()->setRightDevice(nullptr);
			InputDevice->setParent(nullptr);
			cout << "Device disconnected" << endl;
			return;
		}
	return;
}

void deviceManager::printDevices() {
	for (device* device : deviceList) {
		device->printDevice(0);
	}
	return;
}