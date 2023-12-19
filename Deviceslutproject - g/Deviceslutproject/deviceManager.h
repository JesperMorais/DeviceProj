#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "device.h"
using namespace std;

class device;

class deviceManager {
private:
	vector <device*> deviceList;
public:
	deviceManager() {};
	~deviceManager() {};
	void creatNewDevice(string name);
	void deleteDevice(device* device);
	void PingDevice(device* device);
	device* getDevice(string name);
	void connectDevice(device* device);
	void printAllDevices();
	void disconnectDevice(device* InputDevice);
};

