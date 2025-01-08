#include "Algorithms.h"
#include <cstddef>

namespace Server_Library
{
    class Concurrent** Algorithms::ptr_Concurrent_Array = NULL;
    class Concurrent* Algorithms::ptr_Concurrent[3] = { NULL, NULL, NULL };//NUMBER OF CONCURRENT CORES
    class Concurrent* Algorithms::ptr_New_Concurrent = NULL;
    class ListenRespond* Algorithms::ptr_ListenRespond = NULL;
    class User_Alg* Algorithms::ptr_User_Algorithms = NULL;

    Algorithms::Algorithms()
    {
        ptr_User_Algorithms = new class Server_Library::User_Alg();
        while (ptr_User_Algorithms == NULL) { /* wait untill class constructed */ }
    }

    Algorithms::~Algorithms()
    {
        for (int index = 0; index < 3; index++)//NUMBER OF CONCURRENT CORES
        {
            delete ptr_Concurrent[index];
        }
        delete ptr_Concurrent_Array;
        delete ptr_New_Concurrent;
        delete ptr_ListenRespond;
        delete ptr_User_Algorithms;;
    }

    Concurrent* Algorithms::Get_Concurren_Array(int concurrent_coreId)
    {
        return ptr_Concurrent[concurrent_coreId];
    }

    ListenRespond* Algorithms::Get_ListenRespond()
    {
        return ptr_ListenRespond;
    }

    User_Alg* Algorithms::Get_User_Algorithms()
    {
        return ptr_User_Algorithms;
    }


    void Algorithms::Initialise(unsigned char* ptr_NumberOfImplementedCores)
    {
        ptr_ListenRespond = new class Server_Library::ListenRespond();
        while (ptr_ListenRespond == NULL) { /* wait untill created */ }
        ptr_ListenRespond->Initialise_Control();

        ptr_New_Concurrent = new class Server_Library::Concurrent();
        while(ptr_New_Concurrent == NULL) { /* wait untill created */ }
        ptr_New_Concurrent->Initialise_Control();

        for (unsigned char index = 0; index < *ptr_NumberOfImplementedCores - 1; index++)
        {
            ptr_Concurrent[index] = ptr_New_Concurrent;
        }
        delete ptr_New_Concurrent;
        ptr_Concurrent_Array = ptr_Concurrent;
        while (ptr_Concurrent_Array == NULL) { /* wait untill class constructed */ }
    }
}