#include "Global.h"
#include <cstddef>

namespace Server_Library
{
    unsigned char Global::number_Implemented_Cores = NULL;
    unsigned char Global::number_Praise_Events = NULL;

    Global::Global()
    {
        number_Implemented_Cores = unsigned char(4);//NUMBER OF CORES
        number_Praise_Events = unsigned char(2);
    }

    Global::~Global()
    {
        
    }

    unsigned char Global::Get_NumCores()
    {
        return number_Implemented_Cores;
    }
    unsigned char Global::Get_NumPraiseEvetns()
    {
        return number_Praise_Events;
    }
}