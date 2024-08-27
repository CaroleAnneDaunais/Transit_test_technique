#pragma once
#include <string>
#include "events.h"
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

private:
	int clientName_;
	Event event_;
	bool available_ = true;
};

