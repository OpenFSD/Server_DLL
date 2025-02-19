#include "Global.h"
#include <cstddef>

namespace Server_Library
{
    __int8 Global::number_Implemented_Cores = NULL;
    __int8 Global::number_Praise_Events = NULL;

    Global::Global()
    {
        number_Implemented_Cores = __int8(4);//NUMBER OF CORES
        number_Praise_Events = __int8(2);
    }

    Global::~Global()
    {
        
    }

    __int8 Global::Get_NumCores()
    {
        return number_Implemented_Cores;
    }
    __int8 Global::Get_NumPraiseEvetns()
    {
        return number_Praise_Events;
    }
}