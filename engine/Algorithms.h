#pragma once
#include <array>
#include "Concurrent.h"
#include "user_praise_files\\User_Alg.h"

namespace Server_Library
{
    class Algorithms
    {
    public:
        Algorithms();
        virtual ~Algorithms();
        
        void Initialise(__int8 ptr_NumberOfImplementedCores);

        class Concurrent* Get_Concurren_Array(__int8 concurrent_coreId);
        class ListenRespond* Get_ListenRespond();
        class User_Alg* Get_User_Algorithms();

    protected:

    private:
        static class Concurrent** ptr_Concurrent_Array;
        static class Concurrent* ptr_Concurrent[4];//NUMBER OF CONCURRENT CORES
        static class Concurrent* ptr_New_Concurrent;
        static class User_Alg* ptr_User_Algorithms;
    };
}