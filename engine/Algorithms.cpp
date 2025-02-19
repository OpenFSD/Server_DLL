#include "Algorithms.h"
#include <cstddef>

namespace Server_Library
{
    class Concurrent** Algorithms::ptr_Concurrent_Array = NULL;
    class Concurrent* Algorithms::ptr_Concurrent[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CONCURRENT CORES
    class Concurrent* Algorithms::ptr_New_Concurrent = NULL;
    class User_Alg* Algorithms::ptr_User_Algorithms = NULL;

    Algorithms::Algorithms()
    {
        ptr_User_Algorithms = new class Server_Library::User_Alg();
        while (ptr_User_Algorithms == NULL) { /* wait untill class constructed */ }
    }

    Algorithms::~Algorithms()
    {
        for (__int8 index = 0; index < 4; index++)//NUMBER OF CONCURRENT CORES
        {
            delete ptr_Concurrent[index];
        }
        delete ptr_Concurrent_Array;
        delete ptr_New_Concurrent;
        delete ptr_User_Algorithms;;
    }

    Concurrent* Algorithms::Get_Concurren_Array(__int8 concurrent_coreId)
    {
        return ptr_Concurrent[concurrent_coreId];
    }

    User_Alg* Algorithms::Get_User_Algorithms()
    {
        return ptr_User_Algorithms;
    }


    void Algorithms::Initialise(__int8 number_Implemented_Cores)
    {
        ptr_New_Concurrent = new class Server_Library::Concurrent();
        while(ptr_New_Concurrent == NULL) { /* wait untill created */ }
        ptr_New_Concurrent->Initialise_Control();

        for (__int8 index = 0; index < (number_Implemented_Cores - 1); index++)
        {
            ptr_Concurrent[index] = ptr_New_Concurrent;
        }
        delete ptr_New_Concurrent;
        ptr_Concurrent_Array = ptr_Concurrent;
        while (ptr_Concurrent_Array == NULL) { /* wait untill class constructed */ }
    }
}