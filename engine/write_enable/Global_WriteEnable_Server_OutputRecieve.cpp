#include "Global_WriteEnable_Server_OutputRecieve.h"
#include <cstddef>

namespace WaitEnableWrite
{

    bool Global_WriteEnable_Server_OutputRecieve::flag_write_IDLE[2] = { NULL, NULL };
    bool Global_WriteEnable_Server_OutputRecieve::flag_write_WAIT[2] = { NULL, NULL };
    bool Global_WriteEnable_Server_OutputRecieve::flag_write_WRITE[2] = { NULL, NULL };
    unsigned char Global_WriteEnable_Server_OutputRecieve::ptr_num_Implemented_Cores = NULL;

    Global_WriteEnable_Server_OutputRecieve::Global_WriteEnable_Server_OutputRecieve()
    {
        flag_write_IDLE[0] = bool(false);
        flag_write_IDLE[1] = bool(false);

        flag_write_WAIT[0] = bool(false);
        flag_write_WAIT[1] = bool(true);

        flag_write_WRITE[0] = bool(true);
        flag_write_WRITE[1] = bool(false);

        ptr_num_Implemented_Cores = unsigned char(4);//NUMBER OF CORES
    }

    Global_WriteEnable_Server_OutputRecieve::~Global_WriteEnable_Server_OutputRecieve()
    {
        
    }

    unsigned char Global_WriteEnable_Server_OutputRecieve::Get_NumCores()
    {
        return ptr_num_Implemented_Cores;
    }
    bool Global_WriteEnable_Server_OutputRecieve::GetConst_Write_IDLE(unsigned char index)
    {
        return flag_write_IDLE[index];
    }
    bool Global_WriteEnable_Server_OutputRecieve::GetConst_Write_WAIT(unsigned char index)
    {
        return flag_write_WAIT[index];
    }
    bool Global_WriteEnable_Server_OutputRecieve::GetConst_Write_WRITE(unsigned char index)
    {
        return flag_write_WRITE[index];
    }
}