#pragma once
#include <array>
#include <thread>
#include "Execute_Control.h"
#include "Framework_Server.h"
#include "Global.h"
#include "..\\engine\\concurrent_que\\LaunchConcurrency_Server.h"
#include "..\\engine\\write_enable\\WriteEnable_Server_InputAction.h"
#include "..\\engine\\write_enable\\WriteEnable_Server_OutputRecieve.h"

namespace Server_Library
{
    class Execute
    {
    public:
        Execute(
            class Global* ptr_Global,
            unsigned char number_Implemented_Cores
        );
        virtual ~Execute();
        void Initialise();
        void Initialise_Control(
            unsigned char number_Implemented_Cores,
            class Global* ptr_Global
        );
        void Initialise_Threads();

        class Execute_Control* Get_Execute_Control();
        class ConcurrentQue::Framework_ConcurrentQue_Server* Get_LaunchConcurrency_ServerSide();
        class WaitEnableWrite::Framework_WriteEnable_Server_InputAction* Get_WriteEnable_Stack_InputPraise();
        class WaitEnableWrite::Framework_WriteEnable_Server_OutputRecieve* Get_WriteEnable_Stack_OutputPraise();

    protected:

    private:
        static class Execute_Control* ptr_Execute_Control;
        static class ConcurrentQue::Framework_ConcurrentQue_Server* ptr_LaunchConcurrency_ServerSide;
        static std::thread* ptr_Thread_WithCoreId[4];//NUMBER OF CORES
        static class WaitEnableWrite::Framework_WriteEnable_Server_InputAction* ptr_WriteEnable_Stack_InputPraise;
        static class WaitEnableWrite::Framework_WriteEnable_Server_OutputRecieve* ptr_WriteEnable_Stack_OutputPraise;
    };
}