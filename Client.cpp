#include "Client.h"


Client::Client(int clientName)
{
	clientName_ = clientName;
}
void Client::executeEvent(Event event)
{
	
}
void Client::executeGPSLocation()
{

}
void Client::executeMotionDetection()
{

}
void Client::executeCellularConnectionChange()
{

}
void Client::executeBatteryStateChange()
{

}

int Client::getClientName()
{
	return clientName_;
}

bool Client::isClientAvailable()
{
	return available_;
}
