#pragma once
#include <array>

namespace WaitEnableWrite
{
    class Global_WriteEnable_Server_InputAction
    {
    public:
        Global_WriteEnable_Server_InputAction();
        ~Global_WriteEnable_Server_InputAction();
        unsigned char Get_NumCores();
        bool GetConst_Write_IDLE(unsigned char index);
        bool GetConst_Write_WAIT(unsigned char index);
        bool GetConst_Write_WRITE(unsigned char index);

    protected:

    private:
        static bool flag_write_IDLE[2];
        static bool flag_write_WAIT[2];
        static bool flag_write_WRITE[2];
        static unsigned char ptr_num_Implemented_Cores;
    };
}
