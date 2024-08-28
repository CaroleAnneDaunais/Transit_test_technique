#pragma once
#include <string>
#include <chrono>
#include <thread>
#include <iostream>
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
	void setClientAvailable(bool isAvailable);

private:
	int clientName_;
	Event event_;
	bool available_ = true;
};

