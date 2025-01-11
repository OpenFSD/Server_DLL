#pragma once
#include <array>
#include <thread>

namespace Server_Library
{
    class Execute_Control
    {
    public:
        Execute_Control(unsigned char number_Implemented_Cores);
        virtual ~Execute_Control();

        bool GetFlag_SystemInitialised(unsigned char number_Implemented_Cores);
        bool GetFlag_ThreadInitialised(unsigned char coreId);

        void SetConditionCodeOfThisThreadedCore(unsigned char coreId);

    protected:

    private:
        void SetFlag_ThreadInitialised(unsigned char coreId);

        static bool flag_SystemInitialised;
        static bool flag_ThreadInitialised[4];//NUMBER OF CORES
    };
}