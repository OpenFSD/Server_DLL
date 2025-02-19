#pragma once
#include <array>

namespace ConcurrentQue
{
    class ConcurrentQue_Server_Global
    {
    public:
        ConcurrentQue_Server_Global();
        ~ConcurrentQue_Server_Global();
        bool GetConst_Core_IDLE();
        bool GetConst_Core_ACTIVE();
        __int8 Get_NumCores();

    protected:

    private:
        static bool flag_core_IDLE;
        static bool flag_core_ACTIVE;
        static __int8 number_Implemented_Cores;
    };
}
