#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;



class device 
{
protected:
	string name;
	device* leftDevice = nullptr;
	device* rightDevice = nullptr;
	device* parent = nullptr;
	public:
		~device() {};
		device(string name) : name(name) {};
		device() {};
		string getName() const { return name; };		
		virtual void pingDevice() = 0;
		device* getLeftDevice() const { return leftDevice; };
		device* getRightDevice() const { return rightDevice; };
		device* getParent() const { return parent; };
		void setLeftDevice(device* device) { leftDevice = device; };
		void setRightDevice(device* device) { rightDevice = device; };
		void setParent(device* device) { parent = device; };
		void printDevice(int level);
};


class IoTDevice : public device
{
public:
	IoTDevice(string name) 
		: device(name) {};
	
	void pingDevice();
};;

class SuperDevice : public device
{

public:
	SuperDevice(string name) 
		: device(name) {};
	void pingDevice();
};