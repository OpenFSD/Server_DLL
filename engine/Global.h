#pragma once
#include <array>

namespace Server_Library
{
    class Global
    {
    public:
        Global();
        ~Global();
        __int8 Get_NumCores();
        __int8 Get_NumPraiseEvetns();

    protected:

    private:
        static __int8 number_Implemented_Cores;
        static __int8 number_Praise_Events;
    };
}
