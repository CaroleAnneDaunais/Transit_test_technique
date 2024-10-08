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
	bool getStillLaunchingEvents() const;
	Event getEventFromConsole() const;
	void executeEvent(Event event);
	std::unordered_map<Event, std::vector<std::shared_ptr<Client>>> clients_;
};

