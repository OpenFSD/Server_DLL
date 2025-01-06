#include "Concurrent.h"
#include <cstddef>


namespace Server_Library
{
    class Concurrent_Control* Concurrent::ptr_Concurrent_Control = NULL;
    class Object* Concurrent::ptr_Algorithms_Subset = NULL;

    Concurrent::Concurrent()
    {
        ptr_Concurrent_Control = NULL;
        ptr_Algorithms_Subset = NULL;
    }

    Concurrent::~Concurrent()
    {
        delete ptr_Concurrent_Control;
        delete ptr_Algorithms_Subset;
    }

    void Concurrent::Initialise_Control()
    {
        ptr_Concurrent_Control = new class Server_Library::Concurrent_Control();
        while (ptr_Concurrent_Control == NULL) { /* wait untill class constructed */ }
    }

    void Concurrent::Thread_Concurrency(unsigned char concurrent_coreId, unsigned char* ptr_MyNumImplementedCores)
    {
        Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_Execute_Control()->SetConditionCodeOfThisThreadedCore(concurrent_coreId);
        while (Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_Execute_Control()->GetFlag_SystemInitialised(ptr_MyNumImplementedCores) != false)
        {
            // wait untill thread initalised
        }
        if (Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->GetFlag_ConcurrentCoreState(&concurrent_coreId) == Server_Library::Framework_Server::Get_Server()->Get_Global()->GetConst_Core_ACTIVE())
        {
            if (Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_Data_Control()->GetFlag_InputStackLoaded() == true)
            {
                Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_WriteEnable_StackOfInput()->Write_Start(
                    Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_WriteEnable_StackOfInput()->Get_WriteEnable_Control(),
                    &concurrent_coreId,
                    ptr_MyNumImplementedCores,
                    Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_WriteEnable_StackOfInput()->Get_GlobalForWriteControl()
                );
                Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_Data_Control()->PopFromStackOfInputPraises(
                    Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_InputRefferenceOfCore(concurrent_coreId),
                    Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_StackOfInputPraise()
                );
                if (sizeof(Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_StackOfInputPraise()) <= 1)
                {
                    Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_Data_Control()->SetFlag_InputStackLoaded(false);
                }
                else
                {
                    Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_Data_Control()->SetFlag_InputStackLoaded(true);
                }

                Server_Library::Framework_Server::Get_Server()->Get_Algorithms()->Get_Concurren_Array(concurrent_coreId)->Get_Concurrent_Control()->SelectSet_Algorithm_Subset_For_Given_PraiseEventId(
                    Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_InputRefferenceOfCore(concurrent_coreId)->GetPraiseEventId(),
                    concurrent_coreId
                );

                Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->Get_Control_Of_Output()->SelectSetOutputSubset(
                    Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->GetPraiseEventId(),
                    concurrent_coreId
                );

                 Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_WriteEnable_StackOfInput()->Write_End(
                    Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_WriteEnable_StackOfInput()->Get_WriteEnable_Control(),
                    &concurrent_coreId,
                    ptr_MyNumImplementedCores,
                    Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_WriteEnable_StackOfInput()->Get_GlobalForWriteControl()
                );

                Server_Library::Framework_Server::Get_Server()->Get_Algorithms()->Get_Concurren_Array(int(concurrent_coreId))->Do_Concurrent_Algorithm_For_PraiseEventId(
                    Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_InputRefferenceOfCore(concurrent_coreId)->GetPraiseEventId(),
                    Server_Library::Framework_Server::Get_Server()->Get_Algorithms()->Get_Concurren_Array(int(concurrent_coreId))->Get_Algorithm_Subset(),
                    Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_InputRefferenceOfCore(int(concurrent_coreId))->Get_InputBufferSubset(),
                    Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_OutputRefferenceOfCore(int(concurrent_coreId))->Get_OutputBuffer_Subset()
                );
                Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_WriteEnable_StackOfInput()->Write_Start(
                    Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_WriteEnable_StackOfInput()->Get_WriteEnable_Control(),
                    &concurrent_coreId,
                    ptr_MyNumImplementedCores,
                    Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_WriteEnable_StackOfInput()->Get_GlobalForWriteControl()
                );
                Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_Data_Control()->PushToStackOfOutput(
                    Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_StackOfDistributeBuffer(),
                    Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)
                );
                if (sizeof(Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_StackOfInputPraise()) < 1)
                {
                    Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_Data_Control()->SetFlag_InputStackLoaded(false);
                }
                else
                {
                    Server_Library::Framework_Server::Get_Server()->Get_Data()->Get_Data_Control()->SetFlag_InputStackLoaded(true);
                }
                Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_LaunchConcurrency()->Thread_End(
                    &concurrent_coreId,
                    Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency()
                );
                Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_WriteEnable_StackOfInput()->Write_End(
                    Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_WriteEnable_StackOfInput()->Get_WriteEnable_Control(),
                    &concurrent_coreId,
                    ptr_MyNumImplementedCores,
                    Server_Library::Framework_Server::Get_Server()->Get_Execute()->Get_WriteEnable_StackOfInput()->Get_GlobalForWriteControl()
                );
            }
        }
    }

    void  Concurrent::Do_Concurrent_Algorithm_For_PraiseEventId(
        int* ptr_praiseEventId,
        Object* ptr_Algorithm_Subset,
        Object* ptr_Input_Subset,
        Object* ptr_Output_Subset
    )
    {
        switch(*ptr_praiseEventId)
        {
            case 0: {
                Praise0_Algorithm* ptr_Algorithm_Subset_Praise0 = reinterpret_cast <Server_Library::Praise0_Algorithm*> (ptr_Algorithm_Subset);
                Praise0_Input* ptr_Input_Subset_Praise0 = reinterpret_cast <Server_Library::Praise0_Input*> (ptr_Input_Subset);
                Praise0_Output* ptr_Output_Subset_Praise0 = reinterpret_cast <Server_Library::Praise0_Output*> (ptr_Output_Subset);
                ptr_Algorithm_Subset_Praise0->Do_Praise(
                    ptr_Input_Subset_Praise0,
                    ptr_Output_Subset_Praise0
                );
                break;
            }
    
        }
    }

    class Object* Concurrent::Get_Algorithm_Subset()
    {
        return ptr_Algorithms_Subset;
    }

    class Concurrent_Control* Concurrent::Get_Concurrent_Control()
    {
        return ptr_Concurrent_Control;
    }

    void Concurrent::Set_Algorithm_Subset(class Object* value_algorithm)
    {
        ptr_Algorithms_Subset = value_algorithm;
    }
}