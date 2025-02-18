#pragma once
#include <vector>
#include "Input.h"
#include "Output.h"

namespace Server_Library
{
    class Data_Control
    {
    public:
        Data_Control();
        virtual ~Data_Control();
        void Pop_Stack_InputPraises(__int8 concurrentCoreId);
        void Pop_Stack_Output();
        void Push_Stack_InputPraises();
        void Push_Stack_Output(__int8 concurrentCoreId);

        bool GetFlag_InputStackLoaded();
        bool GetFlag_OutputStackLoaded();

    protected:

    private:
        static bool flag_isLoaded_Stack_InputPraise;
        static bool flag_isLoaded_Stack_OutputPraise;

        void SetFlag_InputStackLoaded(bool value);
        void SetFlag_OutputStackLoaded(bool value);
    };
}