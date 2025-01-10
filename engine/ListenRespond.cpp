#include "ListenRespond.h"
#include <cstddef>

namespace Server_Library
{
    class ListenRespond_Control* ListenRespond::ptr_ListenRespond_Control = NULL;

    ListenRespond::ListenRespond()
    {
        ptr_ListenRespond_Control = NULL;
    }

    ListenRespond::~ListenRespond()
    {
        delete ptr_ListenRespond_Control;
    }

    void ListenRespond::Initialise_Control()
    {
        ptr_ListenRespond_Control = new class Server_Library::ListenRespond_Control();
        while (ptr_ListenRespond_Control == NULL) { /* wait untill class constructed */ }
    }

    void ListenRespond::Thread_IO_ListenDistribute(unsigned char coreId, unsigned char* ptr_MyNumImplementedCores)
    {
        Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_Execute_Control()->SetConditionCodeOfThisThreadedCore(coreId);
        while (Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_Execute_Control()->GetFlag_SystemInitialised(ptr_MyNumImplementedCores) != false)
        {
            // wait untill ALL threads initalised in preperation of system init.
        }
        switch (Server_Library::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_ListenRespond()->Get_ListenRespond_Control()->GetFlag_IO_ThreadState())
        {
            // while 
            case true://in
            {
                Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_InputPraise()->Write_Start(
                    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_InputPraise()->Get_WriteEnable_Control(),
                    &coreId,
                    ptr_MyNumImplementedCores,
                    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_InputPraise()->Get_GlobalForWriteControl()
                );

                Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Flip_Input_DoubleBuffer();

                Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->PushToStackOfInputPraises(
                    Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Stack_InputPraise(),
                    Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputBackDouble()
                );
                    // pop from inputpraise stack
                //put object on next concurrent thread or wait for it
                }


                

                Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->SetFlag_InputStackLoaded(true);

                while (Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->GetFlag_ConcurrentCoreState(
                    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->Get_coreId_To_Launch()) == Server_Library::Framework_Server::Get_HostServer()->Get_Global()->GetConst_Core_ACTIVE()
                    ) {/* wait untill a core is free */
                }

                Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency()->Concurrent_Thread_Start(
                    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->Get_coreId_To_Launch(),
                    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency(),
                    ptr_MyNumImplementedCores
                );//Dynamic Launch

                Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_InputPraise()->Write_End(
                    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_InputPraise()->Get_WriteEnable_Control(),
                    &coreId,
                    ptr_MyNumImplementedCores,
                    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_InputPraise()->Get_GlobalForWriteControl()
                );

                Server_Library::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_ListenRespond()->Get_ListenRespond_Control()->SetFlag_IO_ThreadState(false);//DISTRIBUTE=FALSE
                break;
            }
            case false://out
            {
                if (Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->GetFlag_OutputStackLoaded() == true)
                {
                    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_OutputPraise()->Write_Start(
                        Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_OutputPraise()->Get_WriteEnable_Control(),
                        &coreId,
                        ptr_MyNumImplementedCores,
                        Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_OutputPraise()->Get_GlobalForWriteControl()
                    );

                    Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Data_Control()->PopFromStackOfOutput(
                        Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_OutputBackDouble(),
                        Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_StackOfDistributeBuffer()
                    );
                    if (sizeof(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_StackOfDistributeBuffer()) < 1)
                    {
                        Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Control_Of_Data()->SetFlag_OutputStackLoaded(false);
                    }
                    else
                    {
                        Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Control_Of_Data()->SetFlag_OutputStackLoaded(true);
                    }
                    //TODO> Server_Library::Framework_Server::Get_HostServer() distribute networking
                    /*
                    *  send registers in distribute buffer
                    *  set ACK distribute sent to equal TRUE
                    */
                    Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable()->Write_End(
                        Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable()->Get_WriteEnable_Control(),
                        &coreId,
                        ptr_MyNumImplementedCores,
                        Server_Library::Framework_Server::Get_HostServer()->Get_Global()
                    );
                }
                Server_Library::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_ListenRespond()->Get_ListenRespond_Control()->SetFlag_IO_ThreadState(true);//LISTEN=TRUE
                break;
            }
        }
    }

    class ListenRespond_Control* ListenRespond::Get_ListenRespond_Control()
    {
        return ptr_ListenRespond_Control;
    }
}
