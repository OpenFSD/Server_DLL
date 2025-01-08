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
        Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_Execute_Control()->SetConditionCodeOfThisThreadedCore(coreId);
        while (Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_Execute_Control()->GetFlag_SystemInitialised(ptr_MyNumImplementedCores) != false)
        {
            // wait untill ALL threads initalised in preperation of system init.
        }
        switch (Server_Library::Framework_Server::Get_Server()->Get_Algorithms()->Get_ListenRespond()->Get_ListenRespond_Control()->GetFlag_IO_ThreadState())
        {
            case true:
            {
                Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_WriteEnable_StackOfInput()->Write_Start(
                    Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_WriteEnable_StackOfInput()->Get_WriteEnable_Control(),
                    &coreId,
                    ptr_MyNumImplementedCores,
                    Server_Library::Framework_Server::Get_Server()->Get_Global()
                );

                while (!Server_Library::Framework_Server::Get_Server()->Get_Algorithms()->Get_ListenRespond()->Get_ListenRespond_Control()->GetFlag_Acknowledge_Input())
                {
                    //wait for acknowledge
                }

                //TODO> client praise networking accepted and captured
                Server_Library::Framework_Server::Get_Server()->Get_Data()->GetBuffer_InputFrontDouble()->SetPraiseEventId(0);

                Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_PraiseBuffer()->Set_InputBuffer_SubSet(
                    Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_PraiseBuffer()->Get_InputBufferSubset()
                );
                Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_PraiseBuffer()->Get_InputBufferSubset()->Set_A(new bool(false));
                Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_PraiseBuffer()->Get_InputBufferSubset()->Set_B(new bool(false));
                //END TODO> client praise networking accepted and captured

                Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_Control_Of_Data()->PushToStackOfInputPraises(
                    Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_StackOfInputPraise(),
                    Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_PraiseBuffer()
                );

                Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_Control_Of_Data()->SetFlag_InputStackLoaded(true);

                while (Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->GetFlag_ConcurrentCoreState(
                    Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->Get_coreId_To_Launch()) == Server_Library::Framework_Server::Get_Server()->Get_Global()->GetConst_Core_ACTIVE()
                    ) {/* wait untill a core is free */
                }

                Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_LaunchConcurrency()->Concurrent_Thread_Start(
                    Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency(),
                    Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->Get_coreId_To_Launch(),
                    Server_Library::Framework_Server::Get_Server()->Get_Global(),
                    ptr_MyNumImplementedCores
                );//Dynamic Launch

                Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_WriteEnable()->Write_End(
                    Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_WriteEnable()->Get_WriteEnable_Control(),
                    &coreId,
                    ptr_MyNumImplementedCores,
                    Server_Library::Framework_Server::Get_Server()->Get_Global()
                );

                Server_Library::Framework_Server::Get_Server()->Get_Algorithms()->Get_ListenRespond()->Get_ListenRespond_Control()->SetFlag_IO_ThreadState(false);//DISTRIBUTE=FALSE
                break;
            }
            case false:
            {
                if (Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_Control_Of_Data()->GetFlag_OutputStackLoaded() == true)
                {
                    Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_WriteEnable()->Write_Start(
                        Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_WriteEnable()->Get_WriteEnable_Control(),
                        &coreId,
                        ptr_MyNumImplementedCores,
                        Server_Library::Framework_Server::Get_Server()->Get_Global()
                    );
                    Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_Control_Of_Data()->PopFromStackOfOutput(
                        Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_DistributeBuffer(),
                        Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_StackOfDistributeBuffer()
                    );
                    if (sizeof(Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_StackOfDistributeBuffer()) < 1)
                    {
                        Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_Control_Of_Data()->SetFlag_OutputStackLoaded(false);
                    }
                    else
                    {
                        Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_Control_Of_Data()->SetFlag_OutputStackLoaded(true);
                    }
                    //TODO> Server_Library::Framework_Server::Get_Server() distribute networking
                    /*
                    *  send registers in distribute buffer
                    *  set ACK distribute sent to equal TRUE
                    */
                    Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_WriteEnable()->Write_End(
                        Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_WriteEnable()->Get_WriteEnable_Control(),
                        &coreId,
                        ptr_MyNumImplementedCores,
                        Server_Library::Framework_Server::Get_Server()->Get_Global()
                    );
                }
                Server_Library::Framework_Server::Get_Server()->Get_Algorithms()->Get_ListenRespond()->Get_ListenRespond_Control()->SetFlag_IO_ThreadState(true);//LISTEN=TRUE
                break;
            }
        }
    }

    class ListenRespond_Control* ListenRespond::Get_ListenRespond_Control()
    {
        return ptr_ListenRespond_Control;
    }
}
