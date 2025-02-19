#include "Server.h"
#include <cstddef>
#include <iostream>

namespace Server_Library
{
    class Algorithms* Server::ptr_Algorithms = NULL;
    class Data* Server::ptr_Data = NULL;
    class Execute* Server::ptr_Execute = NULL;
    class Global* Server::ptr_Global = NULL;

    Server::Server()
    {
        ptr_Global = new class Server_Library::Global();
        while (ptr_Global == NULL) { /* wait untill created */ }
        std::cout << "Created => Server_Library::Global()" << std::endl;

        ptr_Algorithms = new class Server_Library::Algorithms();
        while (ptr_Algorithms == NULL) { /* wait untill created */ }
        std::cout << "Created => Server_Library::Algorithms()" << std::endl;

        ptr_Data = new class Server_Library::Data(ptr_Global->Get_NumCores());
        while (ptr_Data == NULL) { /* wait untill created */ }
        ptr_Data->Initialise_Control();
        std::cout << "Created => Server_Library::Data()" << std::endl;

        ptr_Execute = new class Server_Library::Execute(ptr_Global, ptr_Global->Get_NumCores());
        while (ptr_Execute == NULL) { /* wait untill created */ }
        ptr_Execute->Initialise_Control(Get_Global()->Get_NumCores(), ptr_Global);
        std::cout << "Created => Server_Library::Execute" << std::endl;
    }

    Server::~Server()
    {
        delete ptr_Global;
        delete ptr_Algorithms;
        delete ptr_Data;
        delete ptr_Execute;
    }

    class Algorithms* Server::Get_Algorithms()
    {
        return ptr_Algorithms;
    }

    class Data* Server::Get_Data()
    {
        return ptr_Data;
    }

    class Execute* Server::Get_Execute()
    {
        return ptr_Execute;
    }

    class Global* Server::Get_Global()
    {
        return ptr_Global;
    }
}