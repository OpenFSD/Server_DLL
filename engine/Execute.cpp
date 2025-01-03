#include "Execute.h"
#include <cstddef>

namespace ServerLibrary
{
    class Execute_Control* Execute::ptr_Execute_Control = NULL;
    class ConcurrentQue::LaunchConcurrency* Execute::ptr_LaunchConcurrency = NULL;
    std::thread* Execute::ptr_Thread_WithCoreId[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CORES
    class WaitEnableWrite::WriteEnable* Execute::ptr_WriteEnable_StackOfInput = NULL;
    class WaitEnableWrite::WriteEnable* Execute::ptr_WriteEnable_StackOfOutput = NULL;

    Execute::Execute(
        Global* ptr_Global,
        unsigned char* ptr_MyNumImplementedCores
    )
    {
        ptr_Execute_Control = NULL;

        ptr_LaunchConcurrency = new class ConcurrentQue::LaunchConcurrency();
        while (ptr_LaunchConcurrency == NULL) { /* wait untill created */ }
        ptr_LaunchConcurrency->Initialise_Control(ptr_LaunchConcurrency->Get_GlobalForLaunchConcurrency(), ptr_MyNumImplementedCores);

        ptr_WriteEnable_StackOfInput = new class WaitEnableWrite::WriteEnable();
        while (ptr_WriteEnable_StackOfInput == NULL) { /* wait untill created */ }
        ptr_WriteEnable_StackOfInput->Initialise_Control(ptr_WriteEnable_StackOfInput->Get_GlobalForWriteControl(), ptr_MyNumImplementedCores);

        ptr_WriteEnable_StackOfOutput = new class WaitEnableWrite::WriteEnable();
        while (ptr_WriteEnable_StackOfOutput == NULL) { /* wait untill created */ }
        ptr_WriteEnable_StackOfOutput->Initialise_Control(ptr_WriteEnable_StackOfOutput->Get_GlobalForWriteControl(), ptr_MyNumImplementedCores);
    }

    Execute::~Execute()
    {
        delete ptr_Execute_Control;
        delete ptr_LaunchConcurrency;
        delete ptr_WriteEnable_StackOfInput;
        delete ptr_WriteEnable_StackOfOutput;
        for (int index = 0; index < 4; index++)
        {
            delete ptr_Thread_WithCoreId[index];
        }//NUMBER OF CORES
    }

    void Execute::Initialise()
    {
        ServerLibrary::Framework::Get_Server()->Get_Algorithms()->Initialise(ServerLibrary::Framework::Get_Server()->Get_Global()->Get_NumCores());
    }

    void Execute::Initialise_Control(
        unsigned char* ptr_MyNumImplementedCores,
        ServerLibrary::Global* ptr_Global
    )
    {
        ptr_Execute_Control = new class ServerLibrary::Execute_Control(ptr_MyNumImplementedCores);
        while (ptr_Execute_Control == NULL) { /* wait untill created */ }
    }

    void Execute::Initialise_Threads()
    {
        for (unsigned char index = 0; index < *ServerLibrary::Framework::Get_Server()->Get_Global()->Get_NumCores(); index++)
        {
            ptr_Thread_WithCoreId[index] = new std::thread(
                ServerLibrary::Framework::Get_Server()->Get_Algorithms()->Get_Concurren_Array(int(index))->Thread_Concurrency,
                unsigned char(index),
                ServerLibrary::Framework::Get_Server()->Get_Global()->Get_NumCores()
            );
        }
        while (ServerLibrary::Framework::Get_Server()->Get_Execute()->Get_Execute_Control()->GetFlag_SystemInitialised(ServerLibrary::Framework::Get_Server()->Get_Global()->Get_NumCores()) != false)
        {

        }
    }

    class Execute_Control* Execute::Get_Execute_Control()
    {
        return ptr_Execute_Control;
    }

    class ConcurrentQue::LaunchConcurrency* Execute::Get_LaunchConcurrency()
    {
        return ptr_LaunchConcurrency;
    }

    class WaitEnableWrite::WriteEnable* Execute::Get_WriteEnable_StackOfInput()
    {
        return ptr_WriteEnable_StackOfInput;
    }

    class WaitEnableWrite::WriteEnable* Execute::Get_WriteEnable_StackOfOutput()
    {
        return ptr_WriteEnable_StackOfOutput;
    }
}