#pragma once
#include <array>
#include <thread>
#include "Execute_Control.h"
#include "Framework_Server.h"
#include "Global.h"
#include "..\\include\\concurrent_que\\LaunchConcurrency.h"
#include "Framework_Server.h"
#include "..\\include\\write_enable\\WriteEnable.h"

namespace Server_Library
{
    class Execute
    {
    public:
        Execute(
            class Global* ptr_Global,
            unsigned char* ptr_MyNumImplementedCores
        );
        virtual ~Execute();
        void Initialise();
        void Initialise_Control(
            unsigned char* ptr_MyNumImplementedCores,
            class Global* ptr_Global
        );
        void Initialise_Threads();

        class Execute_Control* Get_Execute_Control();
        class ConcurrentQue::LaunchConcurrency* Get_LaunchConcurrency();
        class WaitEnableWrite::WriteEnable* Get_WriteEnable_Stack_InputPraise();
        class WaitEnableWrite::WriteEnable* Get_WriteEnable_Stack_OutputPraise();

    protected:

    private:
        static class Execute_Control* ptr_Execute_Control;
        static class ConcurrentQue::LaunchConcurrency* ptr_LaunchConcurrency;
        static std::thread* ptr_Thread_WithCoreId[4];//NUMBER OF CORES
        static class WaitEnableWrite::WriteEnable* ptr_WriteEnable_Stack_InputPraise;
        static class WaitEnableWrite::WriteEnable* ptr_WriteEnable_Stack_OutputPraise;
    };
}