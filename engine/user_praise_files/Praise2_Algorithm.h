#pragma once
#include "Praise2_Input.h"
#include "Praise2_Output.h"

namespace Server_Library
{
    class Praise2_Algorithm
    {
    public:
        Praise2_Algorithm();
        virtual ~Praise2_Algorithm();
        void Do_Praise(
            class Server_Library::Praise2_Input* ptr_In_SubSet,
            class Server_Library::Praise2_Output* ptr_Out_SubSet
        );

    protected:

    private:

    };
}