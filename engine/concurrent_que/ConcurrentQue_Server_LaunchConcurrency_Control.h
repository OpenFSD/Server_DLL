#pragma once
#include <array>
#include <vector>
#include "ConcurrentQue_Server_Global.h"

namespace ConcurrentQue
{
    class ConcurrentQue_Server_LaunchConcurrency_Control
    {
    public:
        ConcurrentQue_Server_LaunchConcurrency_Control(
            class ConcurrentQue::ConcurrentQue_Server_Global* ptr_Global,
            __int8 number_Implemented_Cores
        );
        virtual ~ConcurrentQue_Server_LaunchConcurrency_Control();

        void LaunchEnable_Activate(
            class ConcurrentQue::ConcurrentQue_Server_Global* ptr_Global
        );
        void LaunchEnable_Request(
            __int8 concurrent_CoreId,
            class ConcurrentQue::ConcurrentQue_Server_Global* ptr_Global
        );
        void LaunchEnable_SortQue(
            class ConcurrentQue::ConcurrentQue_Server_Global* ptr_Global,
            __int8 number_Implemented_Cores
        );
        void LaunchQue_Update(
            __int8 number_Implemented_Cores
        );

        __int8 Get_concurrent_CoreId_Index();
        __int8 Get_coreId_To_Launch();
        bool Get_State_ConcurrentCore(__int8 concurrent_CoreId);
        bool GetFlag_PraisingLaunch();
        __int8 Get_new_concurrent_CoreId_Index();
        std::vector<__int8>* Get_Stack_PriseEventId();

        void Set_concurrent_CoreId_Index(__int8 index);
        void SetFlag_ConcurrentCoreState(__int8 concurrent_CoreId, bool value);
        void SetFlag_PraisingLaunch(bool value);
        void Set_new_concurrent_CoreId_Index(__int8 index);


    protected:

    private:
        void DynamicStagger(
            __int8 ptr_coreId
        );
        void LaunchEnable_ShiftQueValues(
            __int8 concurrent_CoreId_A,
            __int8 concurrent_CoreId_B
        );

        int Get_count_LaunchActive_For(__int8 concurrent_CoreId);
        int Get_count_LaunchIdle_For(__int8 concurrent_CoreId);
        __int8 GetFlag_CoreId_Of_CoreToLaunch();
        __int8 Get_que_CoreToLaunch(__int8 index);
        void Set_count_LaunchActive_For(__int8 concurrent_CoreId, int value);
        void Set_count_LaunchIdle_For(__int8 concurrent_CoreId, int value);
        void Set_que_CoreToLaunch(__int8 concurrent_CoreId, __int8 value);

        static bool flag_praisingLaunch;
        static bool state_ConcurrentCore[3];//NUMBER OF CONCURRENT CORES
        static __int8 concurrent_CoreId_Index;
        static int count_LaunchActive_For[3];//NUMBER OF CONCURRENT CORES
        static int count_LaunchIdle_For[3];//NUMBER OF CONCURRENT CORES
        static __int8 new_concurrent_CoreId_Index;
        static __int8 que_CoreToLaunch[3];//NUMBER OF CONCURRENT CORES
        static std::vector<__int8>* stack_PriseEventId;
    };
}