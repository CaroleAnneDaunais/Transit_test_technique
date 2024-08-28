#include "Client.h"
#include <thread>
#include <chrono>


Client::Client(int clientName)
{
	clientName_ = clientName;
}
void Client::executeEvent(Event event)
{
	setClientAvailable(false);
	switch (event)
	{
	case GPSLocation:
		executeGPSLocation();
		break;
	case motionDetection:
		executeMotionDetection();
		break;
	case cellularConnectionChange:
		executeCellularConnectionChange();
		break;
	case batteryStateChange:
		executeBatteryStateChange();
		break;
	}
	setClientAvailable(true);
}
void Client::executeGPSLocation()
{
	std::cout << "** Le client " << clientName_ << " debute l'execution de l'evenement GPS Location." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "** Le client " << clientName_ << " termine l'execution de l'evenement GPS Location." << std::endl;
}
void Client::executeMotionDetection()
{
	std::cout << "** Le client " << clientName_ << " debute l'execution de l'evenement Motion Detection." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "** Le client " << clientName_ << " termine l'execution de l'evenement Motion Detection." << std::endl;
}
void Client::executeCellularConnectionChange()
{
	std::cout << "** Le client " << clientName_ << " debute l'execution de l'evenement Cellular connection change." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "** Le client " << clientName_ << " termine l'execution de l'evenement Cellular connection change." << std::endl;
}
void Client::executeBatteryStateChange()
{
	std::cout << "** Le client " << clientName_ << " debute l'execution de l'evenement Battery state change." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(25));
	std::cout << "** Le client " << clientName_ << " termine l'execution de l'evenement Battery state change." << std::endl;
}

int Client::getClientName()
{
	return clientName_;
}

bool Client::isClientAvailable()
{
	return available_;
}

void Client::setClientAvailable(bool isAvailable)
{
	available_ = isAvailable;
}
