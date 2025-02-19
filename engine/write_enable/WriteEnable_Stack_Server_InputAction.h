#pragma once
#include "WriteEnable_Stack_Server_InputAction_Control.h"
#include "WriteEnable_Stack_Server_InputAction_Global.h"
#include "WriteEnable_Stack_Server_InputAction_Framework.h"

namespace WaitEnableWrite
{
    class WriteEnable_Stack_Server_InputAction
    {
    public:
        WriteEnable_Stack_Server_InputAction();
        virtual ~WriteEnable_Stack_Server_InputAction();
        void Initialise_Control(
            class Global_WriteEnable_Stack_Server_InputAction* ptr_Global
        );
        void Write_End(__int8 coreId);
        void Write_Start(__int8 coreId);

        class WriteEnable_Control_Stack_Server_InputAction* Get_WriteEnable_Control();
        class Global_WriteEnable_Stack_Server_InputAction* Get_GlobalForWriteControl();
    protected:

    private:
        static class Global_WriteEnable_Stack_Server_InputAction* ptr_Global;
        static class WriteEnable_Control_Stack_Server_InputAction* ptr_WriteEnable_Control;
    };
}