#pragma once
#include <array>

namespace Server_Library
{
    class Global
    {
    public:
        Global();
        ~Global();
        unsigned char Get_NumCores();
        unsigned char Get_NumPraiseEvetns();

    protected:

    private:
        static unsigned char number_Implemented_Cores;
        static unsigned char number_Praise_Events;
    };
}
