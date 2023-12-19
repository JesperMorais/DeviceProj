#include "device.h"
#include <windows.h>

void IoTDevice::pingDevice()
{
	cout << "ping IoTDevice: " << name << endl;
}

void SuperDevice::pingDevice()
{
	cout << "ping SuperDevice: "<< name << endl;
}

void device::printDevice(int level)
{
    for (int i = 0; i < level; ++i)
        cout << "  ";

    cout << "Device: [" << this->getName() << "]" << endl;

    if (leftDevice != nullptr)
        leftDevice->printDevice(level + 1);

    if (rightDevice != nullptr)
        rightDevice->printDevice(level + 1);
}