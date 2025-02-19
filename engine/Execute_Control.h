#pragma once
#include <array>
#include <thread>
#include "Framework_Server.h"

namespace Server_Library
{
    class Execute_Control
    {
    public:
        Execute_Control(__int8 number_Implemented_Cores);
        virtual ~Execute_Control();

        bool GetFlag_SystemInitialised();
        bool GetFlag_ThreadInitialised(__int8 coreId);

        void SetConditionCodeOfThisThreadedCore(__int8 coreId);

    protected:

    private:
        void SetFlag_ThreadInitialised(__int8 coreId);

        static bool flag_SystemInitialised;
        static bool flag_ThreadInitialised[4];//NUMBER OF CORES
    };
}