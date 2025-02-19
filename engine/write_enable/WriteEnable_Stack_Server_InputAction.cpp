#include "WriteEnable_Stack_Server_InputAction.h"
#include <cstddef>

namespace WaitEnableWrite
{
    class WaitEnableWrite::Global_WriteEnable_Stack_Server_InputAction* WriteEnable_Stack_Server_InputAction::ptr_Global = NULL;
    class WaitEnableWrite::WriteEnable_Control_Stack_Server_InputAction* WriteEnable_Stack_Server_InputAction::ptr_WriteEnable_Control = NULL;

    WriteEnable_Stack_Server_InputAction::WriteEnable_Stack_Server_InputAction()

    {
        ptr_Global = new WaitEnableWrite::Global_WriteEnable_Stack_Server_InputAction();
        while (ptr_Global == NULL) { /* wait untill created */ }
        ptr_WriteEnable_Control = NULL;
    }

    WriteEnable_Stack_Server_InputAction::~WriteEnable_Stack_Server_InputAction()
    {
        delete ptr_WriteEnable_Control;
    }

    void WriteEnable_Stack_Server_InputAction::Initialise_Control(
        class WaitEnableWrite::Global_WriteEnable_Stack_Server_InputAction* ptr_Global
    )
    {
        ptr_WriteEnable_Control = new class WaitEnableWrite::WriteEnable_Control_Stack_Server_InputAction(ptr_Global);
        while (ptr_WriteEnable_Control == NULL) { /* wait untill created */ }
    }

    void WriteEnable_Stack_Server_InputAction::Write_End(__int8 coreId)
    {
        class WaitEnableWrite::WriteEnable_Control_Stack_Server_InputAction* ptr_WriteEnable_Control = WaitEnableWrite::WriteEnable_Stack_Server_InputAction_Framework::Get_WriteEnable()->Get_WriteEnable_Control();
        class WaitEnableWrite::Global_WriteEnable_Stack_Server_InputAction* ptr_Global = WaitEnableWrite::WriteEnable_Stack_Server_InputAction_Framework::Get_WriteEnable()->Get_GlobalForWriteControl();
        for (__int8 index = 0; index < 2; index++)
        {
            ptr_WriteEnable_Control->SetFlag_writeState(coreId, index, ptr_Global->GetConst_Write_IDLE(index));
        }
        ptr_WriteEnable_Control->Set_new_coreIdForWritePraiseIndex(ptr_WriteEnable_Control->Get_coreIdForWritePraiseIndex() + 1);
        if (int(ptr_WriteEnable_Control->Get_new_coreIdForWritePraiseIndex()) == 3)
        {
            ptr_WriteEnable_Control->Set_new_coreIdForWritePraiseIndex(0);
        }
        ptr_WriteEnable_Control->WriteQue_Update(
            ptr_Global
        );
        ptr_WriteEnable_Control->WriteEnable_SortQue(
            ptr_Global
        );
        ptr_WriteEnable_Control->SetFlag_readWrite_Open(false);
    }
    void WriteEnable_Stack_Server_InputAction::Write_Start(__int8 coreId)
    {
        ptr_WriteEnable_Control->WriteEnable_Request(
            coreId,
            ptr_Global
        );
        ptr_WriteEnable_Control->WriteQue_Update(
            ptr_Global
        );
        ptr_WriteEnable_Control->WriteEnable_SortQue(
            ptr_Global
        );
        ptr_WriteEnable_Control->WriteEnable_Activate(
            coreId,
            ptr_Global
        );
    }

    WriteEnable_Control_Stack_Server_InputAction* WriteEnable_Stack_Server_InputAction::Get_WriteEnable_Control()
    {
        return ptr_WriteEnable_Control;
    }

    WaitEnableWrite::Global_WriteEnable_Stack_Server_InputAction* WriteEnable_Stack_Server_InputAction::Get_GlobalForWriteControl()
    {
        return ptr_Global;
    }
}