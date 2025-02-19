#include "ConcurrentQue_Server_LaunchConcurrency_Control.h"
#include <cstddef>
#include <vector>

namespace ConcurrentQue
{
    bool ConcurrentQue_Server_LaunchConcurrency_Control::state_ConcurrentCore[3] = { NULL, NULL, NULL };//NUMBER OF CONCURRENT CORES
    bool ConcurrentQue_Server_LaunchConcurrency_Control::flag_praisingLaunch = NULL;
    __int8 ConcurrentQue_Server_LaunchConcurrency_Control::concurrent_CoreId_Index = NULL;
    int ConcurrentQue_Server_LaunchConcurrency_Control::count_LaunchActive_For[3] = { NULL, NULL, NULL };//NUMBER OF CONCURNT CORES
    int ConcurrentQue_Server_LaunchConcurrency_Control::count_LaunchIdle_For[3] = { NULL, NULL, NULL };//NUMBER OF CONCURNT CORES
    __int8 ConcurrentQue_Server_LaunchConcurrency_Control::new_concurrent_CoreId_Index = NULL;
    __int8 ConcurrentQue_Server_LaunchConcurrency_Control::que_CoreToLaunch[3] = { NULL, NULL, NULL };//NUMBER OF CONCURRENT CORES
    
    std::vector<__int8>* ConcurrentQue_Server_LaunchConcurrency_Control::stack_PriseEventId;

    ConcurrentQue_Server_LaunchConcurrency_Control::ConcurrentQue_Server_LaunchConcurrency_Control(
        ConcurrentQue::ConcurrentQue_Server_Global* ptr_Global,
        __int8 number_Implemented_Cores
    )
    {
        bool state_ConcurrentCore[3] = { bool(false), bool(false), bool(false) };//NUMBER OF CONCURRENT CORES
        flag_praisingLaunch = bool(false);
        concurrent_CoreId_Index = __int8(0);
        int count_LaunchActive_For[3] = { int(0), int(0), int(0) };//NUMBER OF CONCURNT CORES
        int count_LaunchIdle_For[3] = { int(0), int(0), int(0) };//NUMBER OF CONCURNT CORES
        new_concurrent_CoreId_Index = __int8(0);
        __int8 que_CoreToLaunch[3] = { __int8(0), __int8(0), __int8(0) };//NUMBER OF CONCURNT CORES
        for (__int8 index = 0; index < (number_Implemented_Cores-1); index++)
        {
            state_ConcurrentCore[index] = ptr_Global->GetConst_Core_IDLE();
            count_LaunchActive_For[index] = int(0);
            count_LaunchIdle_For[index] = int(0);
            que_CoreToLaunch[index] = index;
        }
        std::vector<__int8>* stack_PriseEventId = new std::vector<__int8>;
    }

    ConcurrentQue_Server_LaunchConcurrency_Control::~ConcurrentQue_Server_LaunchConcurrency_Control()
    {

    }

    void ConcurrentQue_Server_LaunchConcurrency_Control::LaunchEnable_Activate(
        class ConcurrentQue::ConcurrentQue_Server_Global* ptr_Global
    )
    {
        SetFlag_ConcurrentCoreState(GetFlag_CoreId_Of_CoreToLaunch(), ptr_Global->GetConst_Core_ACTIVE());
    }

    void ConcurrentQue_Server_LaunchConcurrency_Control::LaunchEnable_Request(
        __int8 concurrent_CoreId,
        class ConcurrentQue::ConcurrentQue_Server_Global* ptr_Global
    )
    {
        while (Get_State_ConcurrentCore(GetFlag_CoreId_Of_CoreToLaunch()) != ptr_Global->GetConst_Core_IDLE())
        {

        }
        while (GetFlag_PraisingLaunch() == true)
        {
            DynamicStagger(concurrent_CoreId);
        }
        SetFlag_PraisingLaunch(true);
        Set_concurrent_CoreId_Index(Get_new_concurrent_CoreId_Index());
        if (Get_concurrent_CoreId_Index() == concurrent_CoreId)
        {

        }
        else
        {
            Set_new_concurrent_CoreId_Index(Get_concurrent_CoreId_Index() + 1);
            if (Get_concurrent_CoreId_Index() == 3)
            {
                Set_new_concurrent_CoreId_Index(0);
            }
            SetFlag_PraisingLaunch(false);
            LaunchEnable_Request(
                concurrent_CoreId,
                ptr_Global
            );
        }
    }

    void ConcurrentQue_Server_LaunchConcurrency_Control::LaunchEnable_SortQue(
        class ConcurrentQue::ConcurrentQue_Server_Global* ptr_Global,
        __int8 number_Implemented_Cores
    )
    {
        for (__int8 index_A = 0; index_A < number_Implemented_Cores - 2; index_A++)
        {
            for (__int8 index_B = index_A + 1; index_B < number_Implemented_Cores - 1; index_B++)
            {
                if (Get_State_ConcurrentCore(Get_que_CoreToLaunch(index_A)) == ptr_Global->GetConst_Core_ACTIVE())
                {
                    if (Get_State_ConcurrentCore(Get_que_CoreToLaunch(index_B)) == ptr_Global->GetConst_Core_IDLE())
                    {
                        LaunchEnable_ShiftQueValues(index_A, index_B);
                    }
                    else if (Get_State_ConcurrentCore(Get_que_CoreToLaunch(index_B)) == ptr_Global->GetConst_Core_ACTIVE())
                    {
                        if (Get_count_LaunchActive_For(index_A) > Get_count_LaunchActive_For(index_B))
                        {
                            LaunchEnable_ShiftQueValues(index_A, index_B);
                        }
                    }
                }
                else if (Get_State_ConcurrentCore(Get_que_CoreToLaunch(index_A)) == ptr_Global->GetConst_Core_IDLE())

                    if (Get_State_ConcurrentCore(Get_que_CoreToLaunch(index_B)) == ptr_Global->GetConst_Core_IDLE())
                    {
                        if (Get_count_LaunchIdle_For(index_A) < Get_count_LaunchIdle_For(index_B))
                        {
                            LaunchEnable_ShiftQueValues(index_A, index_B);
                        }
                    }
            }
        }
    }

    void ConcurrentQue_Server_LaunchConcurrency_Control::LaunchQue_Update(
        __int8 number_Implemented_Cores
    )
    {
        for (__int8 index = 0; index < number_Implemented_Cores; index++)
        {
            switch (Get_State_ConcurrentCore(index))
            {
            case false:
            {
                Set_count_LaunchActive_For(index, 0);
                Set_count_LaunchIdle_For(index, Get_count_LaunchIdle_For(index) + 1);
                break;
            }
            case true:
            {
                Set_count_LaunchActive_For(index, Get_count_LaunchActive_For(index) + 1);
                Set_count_LaunchIdle_For(index, 0);
                break;
            }
            }
        }
    }

    __int8 ConcurrentQue_Server_LaunchConcurrency_Control::Get_concurrent_CoreId_Index()
    {
        return concurrent_CoreId_Index;
    }

    __int8 ConcurrentQue_Server_LaunchConcurrency_Control::Get_coreId_To_Launch()
    {
        return que_CoreToLaunch[0];
    }

    bool ConcurrentQue_Server_LaunchConcurrency_Control::Get_State_ConcurrentCore(__int8 concurrent_CoreId)
    {
        return state_ConcurrentCore[concurrent_CoreId];
    }

    void ConcurrentQue_Server_LaunchConcurrency_Control::SetFlag_PraisingLaunch(bool value)
    {
        flag_praisingLaunch = value;
    }

    __int8 ConcurrentQue_Server_LaunchConcurrency_Control::Get_new_concurrent_CoreId_Index()
    {
        return new_concurrent_CoreId_Index;
    }

    std::vector<__int8>* ConcurrentQue_Server_LaunchConcurrency_Control::Get_Stack_PriseEventId()
    {
        return stack_PriseEventId;
    }

    void ConcurrentQue_Server_LaunchConcurrency_Control::Set_concurrent_CoreId_Index(__int8 value)
    {
        concurrent_CoreId_Index = value;
    }

    void ConcurrentQue_Server_LaunchConcurrency_Control::SetFlag_ConcurrentCoreState(__int8 concurrent_CoreId, bool value)
    {
        state_ConcurrentCore[concurrent_CoreId] = value;
    }


    bool ConcurrentQue_Server_LaunchConcurrency_Control::GetFlag_PraisingLaunch()
    {
        return flag_praisingLaunch;
    }

    void ConcurrentQue_Server_LaunchConcurrency_Control::Set_new_concurrent_CoreId_Index(__int8 value)
    {
        new_concurrent_CoreId_Index = value;
    }

    void ConcurrentQue_Server_LaunchConcurrency_Control::DynamicStagger(
        __int8 ptr_coreId
    )
    {
        if (Get_concurrent_CoreId_Index() == ptr_coreId)
        {
            //exit early
        }
        else
        {
            int ptr_count = int(0);
            while (ptr_count < 20)//todo time till flag change
            {

                ptr_count = ptr_count + 1;
            }
        }
    }

    void ConcurrentQue_Server_LaunchConcurrency_Control::LaunchEnable_ShiftQueValues(
        __int8 concurrent_CoreId_A,
        __int8 concurrent_CoreId_B
    )
    {
        int temp_Int;// = new int(0);
        temp_Int = Get_count_LaunchActive_For(concurrent_CoreId_A);
        Set_count_LaunchActive_For(concurrent_CoreId_A, Get_count_LaunchActive_For(concurrent_CoreId_B));
        Set_count_LaunchActive_For(concurrent_CoreId_B, temp_Int);

        temp_Int = Get_count_LaunchIdle_For(concurrent_CoreId_A);
        Set_count_LaunchIdle_For(concurrent_CoreId_A, Get_count_LaunchIdle_For(concurrent_CoreId_B));
        Set_count_LaunchIdle_For(concurrent_CoreId_B, temp_Int);

        __int8 temp_UnnsignedChar;// = new __int8(0);
        temp_UnnsignedChar = Get_que_CoreToLaunch(concurrent_CoreId_A);
        Set_que_CoreToLaunch(concurrent_CoreId_A, Get_que_CoreToLaunch(concurrent_CoreId_B));
        Set_que_CoreToLaunch(concurrent_CoreId_B, temp_UnnsignedChar);
    }

    int ConcurrentQue_Server_LaunchConcurrency_Control::Get_count_LaunchActive_For(__int8 concurrent_CoreId)
    {
        return count_LaunchActive_For[concurrent_CoreId];
    }

    int ConcurrentQue_Server_LaunchConcurrency_Control::Get_count_LaunchIdle_For(__int8 concurrent_CoreId)
    {
        return count_LaunchIdle_For[concurrent_CoreId];
    }

    __int8 ConcurrentQue_Server_LaunchConcurrency_Control::GetFlag_CoreId_Of_CoreToLaunch()
    {
        return que_CoreToLaunch[0];
    }

    __int8 ConcurrentQue_Server_LaunchConcurrency_Control::Get_que_CoreToLaunch(__int8 index)
    {
        return que_CoreToLaunch[index];
    }

    void ConcurrentQue_Server_LaunchConcurrency_Control::Set_count_LaunchActive_For(__int8 concurrent_CoreId, int value)
    {
        count_LaunchActive_For[concurrent_CoreId] = value;
    }

    void ConcurrentQue_Server_LaunchConcurrency_Control::Set_count_LaunchIdle_For(__int8 concurrent_CoreId, int value)
    {
        count_LaunchIdle_For[concurrent_CoreId] = value;
    }

    void ConcurrentQue_Server_LaunchConcurrency_Control::Set_que_CoreToLaunch(__int8 concurrent_CoreId, __int8 value)
    {
        que_CoreToLaunch[concurrent_CoreId] = value;
    }
}