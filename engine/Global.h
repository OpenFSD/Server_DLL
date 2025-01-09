#pragma once
#include <array>

namespace Server_Library
{
    class Global
    {
    public:
        Global();
        ~Global();
        unsigned char* Get_NumCores();

    protected:

    private:
        static unsigned char* ptr_num_Implemented_Cores;
    };
}
