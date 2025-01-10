#include "Data_Control.h"

namespace Server_Library
{
    bool Data_Control::flag_isLoaded_Stack_InputPraise = false;
    bool Data_Control::flag_isLoaded_Stack_OutputPraise = false;

    Data_Control::Data_Control()
    {
        flag_isLoaded_Stack_InputPraise = bool(false);
        flag_isLoaded_Stack_OutputPraise = bool(false);
    }
    Data_Control::~Data_Control()
    {

    }

    void Server_Library::Data_Control::PopFromStackOfInputPraises(
        class Server_Library::Input* referenceForCore,
        std::vector<class Server_Library::Input*>* ptr_inputStack
    )
    {

    }

    void Data_Control::PopFromStackOfOutput(
        class Server_Library::Output* distributeBuffer,
        std::vector<class Server_Library::Output*>* ptr_outputStack
    )
    {

    }

    void Data_Control::PushToStackOfInputPraises(
        std::vector<class Server_Library::Input*>* ptr_InputStack,
        class Server_Library::Input* ptr_Buffer_Praise
    )
    {

    }

    void Data_Control::PushToStackOfOutput(
        std::vector<class Server_Library::Output*>* ptr_outputStack,
        class Server_Library::Output* ptr_referenceForCore
    )
    {

    }

    bool Data_Control::GetFlag_InputStackLoaded()
    {
        return flag_isLoaded_Stack_InputPraise;
    }
    bool Data_Control::GetFlag_OutputStackLoaded()
    {
        return flag_isLoaded_Stack_OutputPraise;
    }


    void Data_Control::SetFlag_InputStackLoaded(bool value)
    {
        flag_isLoaded_Stack_InputPraise = value;
    }
    void Data_Control::SetFlag_OutputStackLoaded(bool value)
    {
        flag_isLoaded_Stack_OutputPraise = value;
    }
}