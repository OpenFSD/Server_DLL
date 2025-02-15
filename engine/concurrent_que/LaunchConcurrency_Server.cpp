#include "LaunchConcurrency_Server.h"
#include <cstddef>

namespace ConcurrentQue
{
    class Global_ConcurrentQue_Server* LaunchConcurrency_Server::ptr_Global = NULL;
    class LaunchConcurrency_Control_Server* LaunchConcurrency_Server::ptr_LaunchConcurrency_Control = NULL;

    LaunchConcurrency_Server::LaunchConcurrency_Server()
    {
        ptr_Global = new class Global_ConcurrentQue_Server();
        ptr_LaunchConcurrency_Control = NULL;
    }

    LaunchConcurrency_Server::~LaunchConcurrency_Server()
    {
        delete ptr_LaunchConcurrency_Control;
    }

    void LaunchConcurrency_Server::Thread_Start()
    {
        class ConcurrentQue::LaunchConcurrency_Control_Server* ptr_LaunchConcurrency_Control = ConcurrentQue::Framework_ConcurrentQue_Server::Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency();
        class ConcurrentQue::Global_ConcurrentQue_Server* ptr_Global = ConcurrentQue::Framework_ConcurrentQue_Server::Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency();
        unsigned char concurrent_CoreId = ConcurrentQue::LaunchConcurrency_Server::Get_Control_Of_LaunchConcurrency()->Get_coreId_To_Launch();

        ptr_LaunchConcurrency_Control->LaunchEnable_Request(concurrent_CoreId, ptr_Global);
        ptr_LaunchConcurrency_Control->LaunchQue_Update(ptr_Global->Get_NumCores());
        ptr_LaunchConcurrency_Control->LaunchEnable_SortQue(ptr_Global, ptr_Global->Get_NumCores());
        ptr_LaunchConcurrency_Control->LaunchEnable_Activate(ptr_Global);
        ptr_LaunchConcurrency_Control->LaunchQue_Update(ptr_Global->Get_NumCores());
        ptr_LaunchConcurrency_Control->LaunchEnable_SortQue(ptr_Global, ptr_Global->Get_NumCores());
        ptr_LaunchConcurrency_Control->SetFlag_PraisingLaunch(false);
    }

    void LaunchConcurrency_Server::Initialise_Control(
        class ConcurrentQue::Global_ConcurrentQue_Server* ptr_Global,
        unsigned char ptr_MyNumImplementedCores
    )
    {
        ptr_LaunchConcurrency_Control = new class ConcurrentQue::LaunchConcurrency_Control_Server(ptr_Global, ptr_MyNumImplementedCores);
        while (ptr_LaunchConcurrency_Control == NULL) { /* wait untill created */ }
    }

    void LaunchConcurrency_Server::Thread_End(unsigned char concurrent_CoreId)
    {
        class ConcurrentQue::LaunchConcurrency_Control_Server* ptr_LaunchConcurrency_Control = ConcurrentQue::Framework_ConcurrentQue_Server::Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency();
        class ConcurrentQue::Global_ConcurrentQue_Server* ptr_Global = ConcurrentQue::Framework_ConcurrentQue_Server::Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency();
        while (ptr_LaunchConcurrency_Control->GetFlag_PraisingLaunch() == true)
        {

        }
        ptr_LaunchConcurrency_Control->SetFlag_PraisingLaunch(true);
        ptr_LaunchConcurrency_Control->Set_concurrent_CoreId_Index(ptr_LaunchConcurrency_Control->Get_new_concurrent_CoreId_Index());
        if (ptr_LaunchConcurrency_Control->Get_concurrent_CoreId_Index() == concurrent_CoreId)
        {
            ptr_LaunchConcurrency_Control->SetFlag_ConcurrentCoreState(concurrent_CoreId, ptr_Global->GetConst_Core_IDLE());
        }
        else
        {
            ptr_LaunchConcurrency_Control->Set_new_concurrent_CoreId_Index(ptr_LaunchConcurrency_Control->Get_concurrent_CoreId_Index() + 1);

            if (ptr_LaunchConcurrency_Control->Get_new_concurrent_CoreId_Index() == 3)//NUMBER OF CONCURNT CORES
            {
                ptr_LaunchConcurrency_Control->Set_new_concurrent_CoreId_Index(0);
            }
            ptr_LaunchConcurrency_Control->SetFlag_PraisingLaunch(false);
            Thread_End(concurrent_CoreId);
        }
    }

    class LaunchConcurrency_Control_Server* LaunchConcurrency_Server::Get_Control_Of_LaunchConcurrency()
    {
        return ptr_LaunchConcurrency_Control;
    }

    Global_ConcurrentQue_Server* LaunchConcurrency_Server::Get_GlobalForLaunchConcurrency()
    {
        return ptr_Global;
    }
}