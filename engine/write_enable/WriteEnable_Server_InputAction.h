#pragma once
#include "WriteEnable_Control_Server_InputAction.h"
#include "Global_WriteEnable_Server_InputAction.h"
#include "Framework_WriteEnable_Server_InputAction.h"

namespace WaitEnableWrite
{
    class WriteEnable_Server_InputAction
    {
    public:
        WriteEnable_Server_InputAction();
        virtual ~WriteEnable_Server_InputAction();
        void Initialise_Control(
            class Global_WriteEnable_Server_InputAction* ptr_Global
        );
        void Write_End(unsigned char coreId);
        void Write_Start(unsigned char coreId);

        class WriteEnable_Control_Server_InputAction* Get_WriteEnable_Control();
        class Global_WriteEnable_Server_InputAction* Get_GlobalForWriteControl();
    protected:

    private:
        static class Global_WriteEnable_Server_InputAction* ptr_Global;
        static class WriteEnable_Control_Server_InputAction* ptr_WriteEnable_Control;
    };
}