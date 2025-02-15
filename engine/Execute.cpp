#include "Execute.h"
#include <cstddef>

namespace Server_Library
{
    class Execute_Control* Execute::ptr_Execute_Control = NULL;
    class ConcurrentQue::Framework_ConcurrentQue_Server* Execute::ptr_LaunchConcurrency_ServerSide = NULL;
    std::thread* Execute::ptr_Thread_WithCoreId[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CORES
    class WaitEnableWrite::Framework_WriteEnable_Server_InputAction* Execute::ptr_WriteEnable_Stack_InputPraise = NULL;
    class WaitEnableWrite::Framework_WriteEnable_Server_OutputRecieve* Execute::ptr_WriteEnable_Stack_OutputPraise = NULL;

    Execute::Execute(
        Global* ptr_Global,
        unsigned char number_Implemented_Cores
    )
    {
        ptr_Execute_Control = NULL;

        ptr_LaunchConcurrency_ServerSide = new class ConcurrentQue::Framework_ConcurrentQue_Server();
        while (ptr_LaunchConcurrency_ServerSide == NULL) { /* wait untill created */ }
        ptr_LaunchConcurrency_ServerSide->Create_ConcurrentQue();
        ptr_LaunchConcurrency_ServerSide->Get_LaunchConcurrency()->Initialise_Control(ptr_LaunchConcurrency_ServerSide->Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency(), number_Implemented_Cores);
               
        ptr_WriteEnable_Stack_InputPraise = new class WaitEnableWrite::Framework_WriteEnable_Server_InputAction();
        while (ptr_WriteEnable_Stack_InputPraise == NULL) { /* wait untill created */ }
        ptr_WriteEnable_Stack_InputPraise->Create_WriteEnable();
        ptr_WriteEnable_Stack_InputPraise->Get_WriteEnable()->Initialise_Control(ptr_WriteEnable_Stack_InputPraise->Get_WriteEnable()->Get_GlobalForWriteControl());

        ptr_WriteEnable_Stack_OutputPraise = new class WaitEnableWrite::Framework_WriteEnable_Server_OutputRecieve();
        while (ptr_WriteEnable_Stack_OutputPraise == NULL) { /* wait untill created */ }
        ptr_WriteEnable_Stack_OutputPraise->Create_WriteEnable();
        ptr_WriteEnable_Stack_OutputPraise->Get_WriteEnable()->Initialise_Control(ptr_WriteEnable_Stack_OutputPraise->Get_WriteEnable()->Get_GlobalForWriteControl());
    }

    Execute::~Execute()
    {
        delete ptr_Execute_Control;
        delete ptr_LaunchConcurrency_ServerSide;
        delete ptr_WriteEnable_Stack_InputPraise;
        delete ptr_WriteEnable_Stack_OutputPraise;
        for (int index = 0; index < 4; index++)
        {
            delete ptr_Thread_WithCoreId[index];
        }//NUMBER OF CORES
    }

    void Execute::Initialise()
    {
        Server_Library::Framework_Server::Get_HostServer()->Get_Algorithms()->Initialise(
            Server_Library::Framework_Server::Get_HostServer()->Get_Global()->Get_NumCores()
        );
    }

    void Execute::Initialise_Control(
        unsigned char number_Implemented_Cores,
        Server_Library::Global* ptr_Global
    )
    {
        ptr_Execute_Control = new class Server_Library::Execute_Control(number_Implemented_Cores);
        while (ptr_Execute_Control == NULL) { /* wait untill created */ }
    }

    void Execute::Initialise_Threads()
    {
        for (unsigned char coreId = 1; coreId < Server_Library::Framework_Server::Get_HostServer()->Get_Global()->Get_NumCores(); coreId++)
        {
            ptr_Thread_WithCoreId[coreId] = new std::thread(
                Server_Library::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_Concurren_Array(int(coreId))->Thread_Concurrency,
                unsigned char(coreId),
                Server_Library::Framework_Server::Get_HostServer()->Get_Global()->Get_NumCores()
            );
            while (ptr_Thread_WithCoreId[coreId] == NULL) { /* wait untill created */ }
            Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_Execute_Control()->SetConditionCodeOfThisThreadedCore(coreId);
        }

        while (Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_Execute_Control()->GetFlag_SystemInitialised(Server_Library::Framework_Server::Get_HostServer()->Get_Global()->Get_NumCores()) != false)
        {

        }
    }

    class Execute_Control* Execute::Get_Execute_Control()
    {
        return ptr_Execute_Control;
    }

    class ConcurrentQue::Framework_ConcurrentQue_Server* Execute::Get_LaunchConcurrency_ServerSide()
    {
        return ptr_LaunchConcurrency_ServerSide;
    }

    class WaitEnableWrite::Framework_WriteEnable_Server_InputAction* Execute::Get_WriteEnable_Stack_InputPraise()
    {
        return ptr_WriteEnable_Stack_InputPraise;
    }

    class WaitEnableWrite::Framework_WriteEnable_Server_OutputRecieve* Execute::Get_WriteEnable_Stack_OutputPraise()
    {
        return ptr_WriteEnable_Stack_OutputPraise;
    }
}