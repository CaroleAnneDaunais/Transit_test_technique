#pragma once
#include <unordered_map>
#include <vector>
#include <memory>
#include <iostream>
#include <thread>
#include <utility>
#include "Client.h"

class Manager
{
public:
	Manager();
	void run();

private:
	std::shared_ptr<Client> newClient(Event event);
	const bool getStillLaunchingEvents();
	const Event getEventFromConsole();
	void executeEvent(Event event);
	std::unordered_map<Event, std::vector<std::shared_ptr<Client>>> clients_;
};

