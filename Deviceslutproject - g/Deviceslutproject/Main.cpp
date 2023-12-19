#include "device.h"
#include "deviceManager.h"
#include <iostream>
using namespace std;

int main()
{
	deviceManager deviceManager;
	int choice;
	do{
		cout << "---------------------" << endl;
		cout << "1. Create new device" << endl;
		cout << "2. Delete device" << endl;
		cout << "3. Ping device" << endl;
		cout << "4. Connect device" << endl;
		cout << "5. Print all devices" << endl;
		cout << "6. Disconnect device" << endl;
		cout << "7. Exit" << endl;
		cout << "Choice: ";
	
		cin >> choice;
		while (!cin)
		{
			cin.clear();           // Restore input stream to working state
			cin.ignore(100, '\n'); // Get rid of any garbage that user might have entered
			cout << "Invalid input, try again: ";
			cin >> choice; // After cin is restored and any garbage in the stream has been cleared, store user input in number again
			cout << endl;
		}

		switch (choice)
		{
		case(1):
		{
			string name;
			cout << "Enter name of device: ";
			cin >> name;
			deviceManager.creatNewDevice(name);
			break;
		}
		case(2):
		{
			string name;
			
			cout << "Enter name of device: ";
			cin >> name;
			device* TheDevice = deviceManager.getDevice(name);
			if (TheDevice != nullptr) {
					deviceManager.deleteDevice(TheDevice);
			}
			break;
		}
		case(3):
		{
			string name;
			cout << "Enter name of device you want to ping: ";
			cin >> name;
			device* TheDevice = deviceManager.getDevice(name);
			if (TheDevice != nullptr) {
				deviceManager.PingDevice(TheDevice);
			}
			break;
		}
		case(4):
		{
			string name;
			cout << "Enter name of device: ";
			cin >> name;
			device* TheDevice = deviceManager.getDevice(name);
			if (TheDevice != nullptr) {
				deviceManager.connectDevice(TheDevice);
			}
			break;
		}
		case(5):
		{
			deviceManager.printAllDevices();
			break;
		}
		case(6):
		{
			string name;
			cout << "Enter name of device: ";
			cin >> name;
			device* TheDevice = deviceManager.getDevice(name);
			if (TheDevice != nullptr) {
				deviceManager.disconnectDevice(TheDevice);
			}
			break;
		}
		default:
			break;
		}
	} while (choice != 7);
 
}
