#pragma once
#include <unordered_map>
#include <vector>
#include "Client.h"
#include "events.h"
#include <memory>
#include <iostream>
#include <thread>
#include <utility>

class Manager
{
public:
	Manager();
	void run();

private:
	std::shared_ptr<Client> newClient(Event event);
	bool getStillLaunchingEvents();
	Event getEventFromConsole();
	void executeEvent(Event event);
	std::unordered_map<Event, std::vector<std::shared_ptr<Client>>> clients_;
};

