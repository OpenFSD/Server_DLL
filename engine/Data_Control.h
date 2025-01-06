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
        void PopFromStackOfInputPraises(
            class Input* referenceForCore,
            std::vector<class Input*>* ptr_inputStack
        );
        void PopFromStackOfOutput(
            class Output* distributeBuffer,
            std::vector<class Output*>* ptr_outputStack
        );
        void PushToStackOfInputPraises(
            std::vector<class Input*>* ptr_InputStack,
            class Input* ptr_Buffer_Praise
        );
        void PushToStackOfOutput(
            std::vector<class Output*>* ptr_outputStack,
            class Output* ptr_referenceForCore
        );

        bool GetFlag_InputStackLoaded();
        bool GetFlag_OutputStackLoaded();

        void SetFlag_InputStackLoaded(bool value);
        void SetFlag_OutputStackLoaded(bool value);

    protected:

    private:
        static bool flag_InputStackLoaded;
        static bool flag_OutputStackLoaded;
    };
}