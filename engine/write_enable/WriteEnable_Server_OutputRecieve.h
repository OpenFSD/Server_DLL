#pragma once
#include "WriteEnable_Control_Server_OutputRecieve.h"
#include "Global_WriteEnable_Server_OutputRecieve.h"
#include "Framework_WriteEnable_Server_OutputRecieve.h"

namespace WaitEnableWrite
{
    class WriteEnable_Server_OutputRecieve
    {
    public:
        WriteEnable_Server_OutputRecieve();
        virtual ~WriteEnable_Server_OutputRecieve();
        void Initialise_Control(
            class Global_WriteEnable_Server_OutputRecieve* ptr_Global
        );
        void Write_End(unsigned char coreId);
        void Write_Start(unsigned char coreId);

        class WriteEnable_Control_Server_OutputRecieve* Get_WriteEnable_Control();
        class Global_WriteEnable_Server_OutputRecieve* Get_GlobalForWriteControl();
    protected:

    private:
        static class Global_WriteEnable_Server_OutputRecieve* ptr_Global;
        static class WriteEnable_Control_Server_OutputRecieve* ptr_WriteEnable_Control;
    };
}