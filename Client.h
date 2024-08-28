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
	const bool isClientAvailable();

private:
	void executeGPSLocation();
	void executeMotionDetection();
	void executeCellularConnectionChange();
	void executeBatteryStateChange();
	const int getClientName();
	void setClientAvailable(bool isAvailable);

	int clientName_;
	Event event_;
	bool available_ = true;
};

