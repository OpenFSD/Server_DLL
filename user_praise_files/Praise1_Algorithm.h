#pragma once
#include "Praise1_Input.h"
#include "Praise1_Output.h"

namespace ServerLibrary
{
    class Praise1_Algorithm
    {
    public:
        Praise1_Algorithm();
        virtual ~Praise1_Algorithm();
        void Do_Praise(
            class ServerLibrary::Praise1_Input* ptr_In_SubSet,
            class ServerLibrary::Praise1_Output* ptr_Out_SubSet
        );

    protected:

    private:

    };
}