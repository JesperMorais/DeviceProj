#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;



class device 
{
private:
	string name;
	device* connectedDevice; //det går endast att ha en device connected
	public:
		~device() {};
		device(string name) : name(name) {};
		device() {};
		void AddConnectedDevice(device* device);
		device* getConnectedDevice() { return connectedDevice; };
		string getName() const { return name; };		
		void pingDevice();
};



