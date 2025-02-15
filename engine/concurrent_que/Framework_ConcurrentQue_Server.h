#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include "LaunchConcurrency_Server.h"

namespace ConcurrentQue
{
    class Framework_ConcurrentQue_Server
    {
    public:
        Framework_ConcurrentQue_Server();
        virtual ~Framework_ConcurrentQue_Server();
        static void Request_Wait_Launch_ConcurrentThread();
        static void Concurrent_Thread_End(unsigned char concurrent_CoreId);

        static void Create_ConcurrentQue();
        static class LaunchConcurrency_Server* Get_LaunchConcurrency();
        
        static __int16 Get_coreId_To_Launch();
        static bool Get_Flag_Active();
        static bool Get_Flag_Idle();
        static bool Get_State_LaunchBit();

    protected:

    private:
        static class LaunchConcurrency_Server* ptr_LaunchConcurrency;
    };
}