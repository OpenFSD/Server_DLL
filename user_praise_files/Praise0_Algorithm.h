#pragma once
#include "Praise0_Input.h"
#include "Praise0_Output.h"

namespace ServerLibrary
{
    class Praise0_Algorithm
    {
    public:
        Praise0_Algorithm();
        virtual ~Praise0_Algorithm();
        void Do_Praise(
            class ServerLibrary::Praise0_Input* ptr_In_SubSet,
            class ServerLibrary::Praise0_Output* ptr_Out_SubSet
        );

    protected:

    private:

    };
}