#include "Manager.h"
#include <chrono>

Manager::Manager()
{
	srand((unsigned)time(NULL));
	clients_.insert({
		{ GPSLocation, {std::make_shared<Client>(std::rand())} },
		{ motionDetection, {std::make_shared<Client>(std::rand())} },
		{ cellularConnectionChange, {std::make_shared<Client>(std::rand())} },
		{ batteryStateChange, {std::make_shared<Client>(std::rand())} }
		}
	);
}
void Manager::run()
{
	bool stillLauching = getStillLaunchingEvents();
	Event event = getEventFromConsole();
}
void Manager::addClients(Event event)
{
	srand((unsigned)time(NULL));
	clients_[event].push_back(std::make_shared<Client>(std::rand()));
}

bool Manager::getStillLaunchingEvents()
{
	std::string eventToLaunch;
	std::cout << "Voulez-vous lancer un evenement? o/n" << std::endl;
	std::cin >> eventToLaunch;
	if (eventToLaunch == "o")
	{
		return true;
	}
	return false;
}

Event Manager::getEventFromConsole()
{
	std::cout << "Veuillez selectionner l'evenement a lancer" << std::endl
	<< "1 - GPS Location" << std::endl
	<< "2 - Motion Detection" << std::endl
	<< "3 - Cellular Connection Change" << std::endl
	<< "4 - Battery State Charge" << std::endl;
	int eventInteger;
	std::cin >> eventInteger;
	switch (eventInteger)
	{
	case 1:
		return GPSLocation;
	case 2:
		return motionDetection;
	case 3:
		return cellularConnectionChange;
	case 4:
		return batteryStateChange;
	}
}
