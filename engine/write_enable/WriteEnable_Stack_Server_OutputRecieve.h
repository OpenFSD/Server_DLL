#pragma once
#include "WriteEnable_Stack_Server_OutputRecieve_Global.h"
#include "WriteEnable_Stack_Server_OutputRecieve_Control.h"
#include "WriteEnable_Stack_Server_OutputRecieve_Framework.h"

namespace WaitEnableWrite
{
    class WriteEnable_Stack_Server_OutputRecieve
    {
    public:
        WriteEnable_Stack_Server_OutputRecieve();
        virtual ~WriteEnable_Stack_Server_OutputRecieve();
        void Initialise_Control(
            class WriteEnable_Stack_Server_OutputRecieve_Global* ptr_Global
        );
        void Write_End(unsigned char coreId);
        void Write_Start(unsigned char coreId);

        class WriteEnable_Stack_Server_OutputRecieve_Control* Get_WriteEnable_Control();
        class WriteEnable_Stack_Server_OutputRecieve_Global* Get_GlobalForWriteControl();
    protected:

    private:
        static class WriteEnable_Stack_Server_OutputRecieve_Global* ptr_Global;
        static class WriteEnable_Stack_Server_OutputRecieve_Control* ptr_WriteEnable_Control;
    };
}