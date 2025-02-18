#include "Data.h"
#include <cstddef>

namespace Server_Library
{
    class Game* Data::ptr_GameInstance = NULL;
    //buffers
    class Input* Data::ptr_EmptyBuffer_Input = NULL;
    class Output* Data::ptr_EmptyBuffer_Output = NULL;
    class Input* Data::ptr_Buffer_InputDouble[2] = { NULL, NULL };
    class Input* Data::ptr_Buffer_InputReference_ForCore[3] = { NULL, NULL, NULL };//NUMBER OF CONCURRENT CORES
    class Output* Data::ptr_Buffer_OututDouble[2] = { NULL, NULL };
    class Output* Data::ptr_Buffer_OutputReference_ForCore[3] = { NULL, NULL, NULL };//NUMBER OF CONCURRENT CORES
    class Data_Control* Data::ptr_Data_Control = NULL;
    std::vector<class Input*>* Data::ptr_Stack_InputPraise = NULL;
    std::vector<class Output*>* Data::ptr_Stack_OutputPraise = NULL;

    //buffer sub sets
    class User_I* Data::ptr_User_I = NULL;
    class User_O* Data::ptr_User_O = NULL;

    bool Data::state_InBufferToWrite = true;
    bool Data::state_OutBufferToWrite = true;

    Data::Data(unsigned char number_Implemented_Cores)
    {
       // ptr_GameInstance = new class Server_Library::Game();
       // while (ptr_GameInstance == NULL) { /* wait untill created */ }

        ptr_EmptyBuffer_Input = new class Server_Library::Input();
        while (ptr_EmptyBuffer_Input == NULL) { /* wait untill created */ }
        ptr_EmptyBuffer_Input->Initialise_Control();

        ptr_EmptyBuffer_Output = new class Server_Library::Output();
        while (ptr_EmptyBuffer_Output == NULL) { /* wait untill created */ }
        ptr_EmptyBuffer_Output->Initialise_Control();

        for (__int8 index = 0; index < 2; index++)
        {
            ptr_Buffer_InputDouble[index] = new Input();
            while (ptr_Buffer_InputDouble[index] == NULL) { /* wait untill created */ }
        }
        for (__int8 index = 0; index < 2; index++)
        {
            ptr_Buffer_OututDouble[index] = new Output();
            while (ptr_Buffer_OututDouble[index] == NULL) { /* wait untill created */ }
        }
        for (__int8 index = 0; index < (4 - 1); index++)//Number Of Cores
        {
            ptr_Buffer_InputReference_ForCore[index] = new Input();
            while (ptr_Buffer_InputReference_ForCore[index] == NULL) { /* wait untill created */ }
        }
        for (__int8 index = 0; index < (Server_Library::Framework_Server::Get_HostServer()->Get_Global()->Get_NumCores() - 1); index++)
        {
            ptr_Buffer_OutputReference_ForCore[index] = new Output();
            while (ptr_Buffer_OutputReference_ForCore[index] == NULL) { /* wait untill created */ }
        }

        ptr_Data_Control = new Data_Control();
        while (ptr_User_I == NULL) { /* wait untill created */ }

        ptr_Stack_InputPraise = new std::vector<class Server_Library::Input*>;
        while (ptr_Stack_InputPraise == NULL) { /* wait untill created */ }
        ptr_Stack_InputPraise->resize(1);
        ptr_Stack_InputPraise->at(0) = ptr_EmptyBuffer_Input;

        ptr_Stack_OutputPraise = new std::vector<class Server_Library::Output*>;
        while (ptr_Stack_OutputPraise == NULL) { /* wait untill created */ }
        ptr_Stack_OutputPraise->resize(1);
        ptr_Stack_OutputPraise->at(0) = ptr_EmptyBuffer_Output;

        ptr_User_I = new User_I();
        while (ptr_User_I == NULL) { /* wait untill created */ }

        ptr_User_O = new User_O();
        while (ptr_User_O == NULL) { /* wait untill created */ }

        delete ptr_EmptyBuffer_Input;
        delete ptr_EmptyBuffer_Output;
    }

    Data::~Data()
    {
        delete ptr_Data_Control;
        delete ptr_Buffer_InputDouble;
        delete ptr_EmptyBuffer_Output;

        for (int index = 0; index < 3; index++)
        {
            delete ptr_Buffer_InputReference_ForCore[index];
            delete ptr_Buffer_OutputReference_ForCore[index];
        }
        delete ptr_Stack_InputPraise;
        delete ptr_Stack_OutputPraise;
    }

    __int8 Data::BoolToInt(bool bufferSide)
    {
        __int8 temp = 2;
        if(bufferSide)
        {
            temp = 1;
        }
        else
        {
            temp = 0;
        }
        return temp;
    }

    void Data::Flip_Input_DoubleBuffer()
    {
        state_InBufferToWrite = !state_InBufferToWrite;
    }

    void Data::Flip_Output_DoubleBuffer()
    {
        state_OutBufferToWrite = !state_OutBufferToWrite;
    }

    void Data::Initialise_Control()
    {
        ptr_Data_Control = new Server_Library::Data_Control();
        while (ptr_Data_Control == NULL) { /* wait untill created */ }
    }

    Game* Data::GetGameInstance()
    {
        return ptr_GameInstance;
    }

    class Data_Control* Data::Get_Data_Control()
    {
        return ptr_Data_Control;
    }

    Input* Data::GetBuffer_InputFrontDouble()
    {
        return ptr_Buffer_InputDouble[BoolToInt(GetState_InputBuffer())];
    }

    Input* Data::GetBuffer_InputBackDouble()
    {
        return ptr_Buffer_InputDouble[BoolToInt(!GetState_InputBuffer())];
    }

    class Output* Data::GetBuffer_OututFrontDouble()
    {
        return ptr_Buffer_OututDouble[BoolToInt(GetState_InputBuffer())];
    }

    Output* Data::GetBuffer_OutputBackDouble()
    {
        return ptr_Buffer_OututDouble[BoolToInt(!GetState_InputBuffer())];
    }

    class Input* Data::Get_InputRefferenceOfCore(unsigned char concurrent_coreId)
    {
        return ptr_Buffer_InputReference_ForCore[concurrent_coreId];
    }

    class Output* Data::Get_OutputRefferenceOfCore(unsigned char concurrent_coreId)
    {
        return ptr_Buffer_OutputReference_ForCore[concurrent_coreId];
    }

    Input* Data::Get_New_InputBuffer()
    {
        return ptr_EmptyBuffer_Input;
    }

    Output* Data::Get_New_OutputBuffer()
    {
        return ptr_EmptyBuffer_Output;
    }

    bool Data::GetState_InputBuffer()
    {
        return state_InBufferToWrite;
    }

    bool Data::GetState_OutputBuffer()
    {
        return state_OutBufferToWrite;
    }

    std::vector<class Server_Library::Input*>* Data::Get_Stack_InputPraise()
    {
        return ptr_Stack_InputPraise;
    }

    std::vector<class Server_Library::Output*>* Data::Get_Stack_OutputPraise()
    {
        return ptr_Stack_OutputPraise;
    }

    class User_I* Data::Get_User_I()
    {
        return ptr_User_I;
    }

    User_O* Data::Get_User_O()
    {
        return ptr_User_O;
    }

    void Data::Set_InputRefferenceOfCore(unsigned char concurrent_coreId, class Server_Library::Input* value_Input)
    {
        ptr_Buffer_InputReference_ForCore[concurrent_coreId] = value_Input;
    }

    void Data::Set_OutputRefferenceOfCore(unsigned char concurrent_coreId, class Server_Library::Output* value_Output)
    {
        ptr_Buffer_OutputReference_ForCore[concurrent_coreId] = value_Output;
    }
}