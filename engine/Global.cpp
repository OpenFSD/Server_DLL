#include "Global.h"
#include <cstddef>

namespace Server_Library
{
    unsigned char* Global::ptr_num_Implemented_Cores = NULL;

    Global::Global()
    {
        ptr_num_Implemented_Cores = new unsigned char(4);//NUMBER OF CORES
    }

    Global::~Global()
    {
        delete ptr_num_Implemented_Cores;
    }

    unsigned char* Global::Get_NumCores()
    {
        return ptr_num_Implemented_Cores;
    }
}