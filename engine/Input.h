#pragma once
#include "Framework.h"
#include "Input_Control.h"

namespace ServerLibrary
{
    class Input
    {
    public:
        Input();
        virtual ~Input();
        void Initialise_Control();

        class Input_Control* Get_Input_Control();
        class Object* Get_InputBufferSubset();
        int* GetPraiseEventId();

        void Set_Subset_InputBuffer(Object* value);
        void SetPraiseEventId(int value);

    protected:

    private:
        static class Input_Control* ptr_Input_Control;
        static class Object* ptr_Buffer_SubSet_InputPraise;
        static int* ptr_in_praiseEventId;

    };
}