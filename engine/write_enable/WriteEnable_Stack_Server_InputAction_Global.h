#pragma once
#include <array>

namespace WaitEnableWrite
{
    class Global_WriteEnable_Stack_Server_InputAction
    {
    public:
        Global_WriteEnable_Stack_Server_InputAction();
        ~Global_WriteEnable_Stack_Server_InputAction();
        __int8 Get_NumCores();
        bool GetConst_Write_IDLE(__int8 index);
        bool GetConst_Write_WAIT(__int8 index);
        bool GetConst_Write_WRITE(__int8 index);

    protected:

    private:
        static bool flag_write_IDLE[2];
        static bool flag_write_WAIT[2];
        static bool flag_write_WRITE[2];
        static __int8 ptr_num_Implemented_Cores;
    };
}
