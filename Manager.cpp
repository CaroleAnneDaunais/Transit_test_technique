#include "Manager.h"

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
	std::vector<std::thread*> threads(1);
	while(getStillLaunchingEvents())
	{ 
		Event event = getEventFromConsole();
		threads.back() = new std::thread(&Manager::executeEvent, this, event);
	}
	for (auto& t : threads)
	{
		t->join();
		delete t;
	}
	std::cout << "Au revoir!"<<std::endl;
}
std::shared_ptr<Client> Manager::newClient(Event event)
{
	srand((unsigned)time(NULL));
	clients_[event].push_back(std::make_shared<Client>(std::rand()));
	return clients_[event].back();
}

bool Manager::getStillLaunchingEvents()
{
	bool entreeValide = false;
	while (!entreeValide)
	{
		std::string eventToLaunch;
		std::cout << "Voulez-vous lancer un evenement? o/n" << std::endl;
		std::cin >> eventToLaunch;
		if (eventToLaunch == "o")
		{
			entreeValide = true;
			return true;
		}
		else if (eventToLaunch == "n")
		{
			entreeValide = true;
			return false; 
		}
		else
		{
			std::cout << "Seules les entrees o et n sont valides." << std::endl;
		}
	}
}

Event Manager::getEventFromConsole()
{
	bool validInformation = false;

	while (!validInformation)
	{
		validInformation = true;

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
		default:
			validInformation = false;
			std::cout << "Seules les valeurs de 1 a 4 sont valides."<<std::endl;
		}
	}
	std::cout<<std::endl;
}

void Manager::executeEvent(Event event)
{
	bool clientFound = false;
	for (std::shared_ptr<Client>& client : clients_[event])
	{
		if (client->isClientAvailable())
		{
			clientFound = true;
			client->executeEvent(event);
			break;
		}
	}
	if (!clientFound)
	{
		std::shared_ptr<Client> client = newClient(event);
		client->executeEvent(event);
	}
	
}
