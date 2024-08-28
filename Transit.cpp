#include "Client.h"
#include "Manager.h"
#include <thread> 

int main()
{
    Manager manager;
    manager.run();
    return 0;
}

