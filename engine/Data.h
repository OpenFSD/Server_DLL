#pragma once
#include <array>
#include <vector>
#include "Data_Control.h"
#include "Input.h"
#include "Output.h"
#include "user_praise_files\\Praise0_Input.h"
#include "user_praise_files\\Praise0_Output.h"
#include "user_praise_files\\User_I.h"
#include "user_praise_files\\User_O.h"

namespace Server_Library
{
    class Data
    {
    public:
        Data(__int8 number_Implemented_Cores);
        virtual ~Data();

        __int8 BoolToInt(bool bufferSide);
        void Flip_Input_DoubleBuffer();
        void Flip_Output_DoubleBuffer();
        void Initialise_Control();

        class Game* GetGameInstance();
        class Data_Control* Get_Data_Control();
        class Input* GetBuffer_InputFrontDouble();
        class Input* GetBuffer_InputBackDouble();
        class Input* Get_InputRefferenceOfCore(__int8 concurrent_coreId);
        class Output* GetBuffer_OututFrontDouble();
        class Output* GetBuffer_OutputBackDouble();
        class Output* Get_OutputRefferenceOfCore(__int8 concurrent_coreId);
        class Input* Get_New_InputBuffer();
        class Output* Get_New_OutputBuffer();
        bool GetState_InputBuffer();
        bool GetState_OutputBuffer();
        std::vector<class Input*>* Get_Stack_InputPraise();
        std::vector<class Output*>* Get_Stack_OutputPraise();
        class User_I* Get_User_I();
        class User_O* Get_User_O();

        void Set_InputRefferenceOfCore(__int8 concurrent_coreId, class Input* value_Input);
        void Set_OutputRefferenceOfCore(__int8 concurrent_coreId, class Output* value_Output);

    protected:

    private:
        static class Game* ptr_GameInstance;
    //buffers
        static class Input* ptr_EmptyBuffer_Input;
        static class Output* ptr_EmptyBuffer_Output;
        static class Input* ptr_Buffer_InputDouble[2];
        static class Input* ptr_Buffer_InputReference_ForCore[4];//NUMBER OF CONCURRENT CORES
        static class Output* ptr_Buffer_OututDouble[2];
        static class Output* ptr_Buffer_OutputReference_ForCore[4];//NUMBER OF CONCURRENT CORES
        static class Data_Control* ptr_Data_Control;
        static std::vector<class Input*>* ptr_Stack_InputPraise;
        static std::vector<class Output*>* ptr_Stack_OutputPraise;
    //buffer sub sets
        static class User_I* ptr_User_I;
        static class User_O* ptr_User_O;

        static bool state_InBufferToWrite;
        static bool state_OutBufferToWrite;
    };
}