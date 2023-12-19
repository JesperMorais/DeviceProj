#include "device.h"

void device::AddConnectedDevice(device* connectDevice) {
	if (connectedDevice == nullptr) { //det går endast att ha en device connected
		connectedDevice = connectDevice;
		cout << "Device connected" << endl;
	}
	else if (connectDevice == nullptr) {
		connectedDevice = nullptr;
		cout << "Device disconnected" << endl;
	}
	else {
		cout << "There cannot be more then 1 connection to this device" << endl;
	}
	return;
}

void device::pingDevice() {

	cout << name << " has been pinged" << endl;
	if (connectedDevice != nullptr)
	{
		cout << connectedDevice->getName() << " has been pinged" << endl;
	}

	return;
}
