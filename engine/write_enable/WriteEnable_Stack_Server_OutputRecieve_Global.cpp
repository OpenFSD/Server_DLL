#include "WriteEnable_Stack_Server_OutputRecieve_Global.h"
#include <cstddef>

namespace WaitEnableWrite
{

    bool WriteEnable_Stack_Server_OutputRecieve_Global::flag_write_IDLE[2] = { NULL, NULL };
    bool WriteEnable_Stack_Server_OutputRecieve_Global::flag_write_WAIT[2] = { NULL, NULL };
    bool WriteEnable_Stack_Server_OutputRecieve_Global::flag_write_WRITE[2] = { NULL, NULL };
    unsigned char WriteEnable_Stack_Server_OutputRecieve_Global::ptr_num_Implemented_Cores = NULL;

    WriteEnable_Stack_Server_OutputRecieve_Global::WriteEnable_Stack_Server_OutputRecieve_Global()
    {
        flag_write_IDLE[0] = bool(false);
        flag_write_IDLE[1] = bool(false);

        flag_write_WAIT[0] = bool(false);
        flag_write_WAIT[1] = bool(true);

        flag_write_WRITE[0] = bool(true);
        flag_write_WRITE[1] = bool(false);

        ptr_num_Implemented_Cores = unsigned char(4);//NUMBER OF CORES
    }

    WriteEnable_Stack_Server_OutputRecieve_Global::~WriteEnable_Stack_Server_OutputRecieve_Global()
    {
        
    }

    unsigned char WriteEnable_Stack_Server_OutputRecieve_Global::Get_NumCores()
    {
        return ptr_num_Implemented_Cores;
    }
    bool WriteEnable_Stack_Server_OutputRecieve_Global::GetConst_Write_IDLE(unsigned char index)
    {
        return flag_write_IDLE[index];
    }
    bool WriteEnable_Stack_Server_OutputRecieve_Global::GetConst_Write_WAIT(unsigned char index)
    {
        return flag_write_WAIT[index];
    }
    bool WriteEnable_Stack_Server_OutputRecieve_Global::GetConst_Write_WRITE(unsigned char index)
    {
        return flag_write_WRITE[index];
    }
}