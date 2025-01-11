#pragma once
#include <array>
#include "Concurrent.h"
#include "ListenRespond.h"
#include "user_praise_files\\User_Alg.h"

namespace Server_Library
{
    class Algorithms
    {
    public:
        Algorithms();
        virtual ~Algorithms();
        
        void Initialise(unsigned char ptr_NumberOfImplementedCores);

        class Concurrent* Get_Concurren_Array(int concurrent_coreId);
        class ListenRespond* Get_ListenRespond();
        class User_Alg* Get_User_Algorithms();

    protected:

    private:
        static class Concurrent** ptr_Concurrent_Array;
        static class Concurrent* ptr_Concurrent[3];
        static class ListenRespond* ptr_ListenRespond;
        static class Concurrent* ptr_New_Concurrent;
        static class User_Alg* ptr_User_Algorithms;
    };
}