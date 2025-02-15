#pragma once
#include "Framework_ConcurrentQue_Server.h"
#include "LaunchConcurrency_Control_Server.h"
#include "Global_ConcurrentQue_Server.h"

namespace ConcurrentQue
{
    class LaunchConcurrency_Server
    {
    public:
        LaunchConcurrency_Server();
        virtual ~LaunchConcurrency_Server();

        void Thread_Start();
        void Initialise_Control(
            class Global_ConcurrentQue_Server* ptr_Global,
            unsigned char ptr_MyNumImplementedCores
        );
        void Thread_End(unsigned char concurrent_CoreId);

        class LaunchConcurrency_Control_Server* Get_Control_Of_LaunchConcurrency();
        class Global_ConcurrentQue_Server* Get_GlobalForLaunchConcurrency();

    protected:

    private:
        static class Global_ConcurrentQue_Server* ptr_Global;
        static class LaunchConcurrency_Control_Server* ptr_LaunchConcurrency_Control;
    };
}