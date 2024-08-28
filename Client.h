#pragma once
#include <string>
#include "events.h"
#include <iostream>
class Client
{
public:
	Client(int clientName);
	void executeEvent(Event event);
	void executeGPSLocation();
	void executeMotionDetection();
	void executeCellularConnectionChange();
	void executeBatteryStateChange();
	int getClientName();
	bool isClientAvailable();
	void setClientAvailable(bool isAvailable);

private:
	int clientName_;
	Event event_;
	bool available_ = true;
};

