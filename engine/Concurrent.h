#pragma once
#include "Concurrent_Control.h"
#include "Framework_Server.h"
#include "user_praise_files\\Praise0_Algorithm.h"
#include "user_praise_files\\Praise0_Input.h"
#include "user_praise_files\\Praise0_Output.h"

namespace Server_Library
{
    class Concurrent
    {
    public:
        Concurrent();
        virtual ~Concurrent();

        void Initialise_Control();
        static void Thread_Concurrency(
            unsigned char concurrent_coreId,
            unsigned char number_Implemented_Cores
        );
        void Do_Concurrent_Algorithm_For_PraiseEventId(
            __int16 ptr_praiseEventId,
            class Object* ptr_Algorithm_Subset,
            class Object* ptr_Input_Subset,
            class Object* ptr_Output_Subset
        );

        class Object* Get_Algorithm_Subset();
        class Concurrent_Control* Get_Concurrent_Control();

        void Set_Algorithm_Subset(class Object* value_algorithm);

    protected:

    private:
        static class Concurrent_Control* ptr_Concurrent_Control;
        static class Object* ptr_Algorithms_Subset;

    };
}