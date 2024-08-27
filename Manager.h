#pragma once
#include <unordered_map>
#include <vector>
#include "Client.h"
#include "events.h"
#include <memory>
#include <iostream>
class Manager
{
public:
	Manager();
	void run();
	void addClients(Event event);
private:
	bool getStillLaunchingEvents();
	Event getEventFromConsole();
	std::unordered_map<Event, std::vector<std::shared_ptr<Client>>> clients_;
};

