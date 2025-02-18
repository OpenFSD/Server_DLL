#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <bitset>
#include "WriteEnable_Stack_Server_InputAction.h"

namespace WaitEnableWrite
{
    class WriteEnable_Stack_Server_InputAction_Framework
    {
    public:
        WriteEnable_Stack_Server_InputAction_Framework();
        virtual ~WriteEnable_Stack_Server_InputAction_Framework();

        static void Create_WriteEnable();
        static void Write_End(unsigned char coreId);
        static void Write_Start(unsigned char coreId);

        static class WriteEnable_Stack_Server_InputAction* Get_WriteEnable();

    protected:

    private:
        static class WriteEnable_Stack_Server_InputAction* ptr_WriteEnable;
    };
}