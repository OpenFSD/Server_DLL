#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <bitset>
#include "WriteEnable_Stack_Server_OutputRecieve.h"

namespace WaitEnableWrite
{
    class WriteEnable_Stack_Server_OutputRecieve_Framework
    {
    public:
        WriteEnable_Stack_Server_OutputRecieve_Framework();
        virtual ~WriteEnable_Stack_Server_OutputRecieve_Framework();

        static void Create_WriteEnable();
        static void Write_End(unsigned char coreId);
        static void Write_Start(unsigned char coreId);

        static class WriteEnable_Stack_Server_OutputRecieve* Get_WriteEnable();

    protected:

    private:
        static class WriteEnable_Stack_Server_OutputRecieve* ptr_WriteEnable;
    };
}