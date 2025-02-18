#pragma once
#include <array>

namespace WaitEnableWrite
{
    class WriteEnable_Stack_Server_OutputRecieve_Global
    {
    public:
        WriteEnable_Stack_Server_OutputRecieve_Global();
        ~WriteEnable_Stack_Server_OutputRecieve_Global();
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
