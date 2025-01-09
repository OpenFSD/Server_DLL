#pragma once
#include "Output_Control.h"

namespace Server_Library
{
    class Output
    {
    public:
        Output();
        virtual ~Output();

        void Initialise_Control();

        class Output_Control* Get_Control_Of_Output();
        class Object* Get_OutputBuffer_Subset();
        int* GetPraiseEventId();

        void Set_OutputBuffer_Subset(class Object* value);
        void SetPraiseEventId(int value);

    protected:

    private:
        static class Output_Control* ptr_Control_Of_Output;
        static class Object* praiseOutputBuffer_Subset;
        static int* ptr_out_PraiseEventId;
    };
}