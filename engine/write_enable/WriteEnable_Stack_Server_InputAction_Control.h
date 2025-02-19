#pragma once
#include "WriteEnable_Stack_Server_InputAction_Global.h"

namespace WaitEnableWrite
{
    class WriteEnable_Control_Stack_Server_InputAction
    {
    public:
        WriteEnable_Control_Stack_Server_InputAction(
            class WaitEnableWrite::Global_WriteEnable_Stack_Server_InputAction* ptr_Global
        );
        ~WriteEnable_Control_Stack_Server_InputAction();
        void WriteEnable_Activate(
            __int8 coreId,
            class WaitEnableWrite::Global_WriteEnable_Stack_Server_InputAction* ptr_Global
        );
        void WriteEnable_SortQue(
            class WaitEnableWrite::Global_WriteEnable_Stack_Server_InputAction* ptr_Global
        );
        void WriteEnable_Request(
            __int8 coreId,
            class WaitEnableWrite::Global_WriteEnable_Stack_Server_InputAction* ptr_Global
        );
        void WriteQue_Update(
            class WaitEnableWrite::Global_WriteEnable_Stack_Server_InputAction* ptr_Global
        );

        __int8 Get_coreIdForWritePraiseIndex();
        int Get_count_WriteActive(__int8 coreId);
        int Get_count_WriteIdle(__int8 coreId);
        int Get_count_WriteWait(__int8 coreId);
        __int8 GetFlag_CoreId_WriteEnable();
        __int8 Get_new_coreIdForWritePraiseIndex();
        __int8 Get_que_CoreToWrite(__int8 coreId);

        void Set_count_WriteActive(__int8 coreId, int value);
        void Set_count_WriteIdle(__int8 coreId, int value);
        void Set_count_WriteWait(__int8 coreId, int value);
        void SetFlag_readWrite_Open(bool value);
        void SetFlag_writeState(__int8 coreId, __int8 index, bool value);
        void Set_new_coreIdForWritePraiseIndex(__int8 value);
        void Set_que_CoreToWrite(__int8 index, __int8 value);

    protected:

    private:
        void DynamicStagger(
            __int8 coreId
        );
        void WriteEnable_ShiftQueValues(
            __int8 concurrent_CoreId_A,
            __int8 concurrent_CoreId_B
        );

        bool GetFlag_readWrite_Open();
        bool GetFlag_writeState(__int8 coreId, __int8 index);

        void Set_coreIdForWritePraiseIndex(__int8 value);

        static __int8 coreId_For_WritePraise_Index;
        static int ptr_count_CoreId_WriteActive[4];//NUMBER OF CORES
        static int ptr_count_CoreId_WriteIdle[4];//NUMBER OF CORES
        static int ptr_count_CoreId_WriteWait[4];//NUMBER OF CORES
        static bool flag_WriteState[4][2];//NUMBER OF CORES
        static __int8 ptr_new_coreId_For_WritePraise_Index;
        static bool praisingWrite;
        static __int8 ptr_que_CoreToWrite[4];//NUMBER OF CORES
    };
}