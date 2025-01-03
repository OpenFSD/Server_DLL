#include "Data_Control.h"

namespace ServerLibrary
{
    bool Data_Control::flag_InputStackLoaded = false;
    bool Data_Control::flag_OutputStackLoaded = false;

    Data_Control::Data_Control()
    {
        flag_InputStackLoaded = bool(false);
        flag_OutputStackLoaded = bool(false);
    }
    Data_Control::~Data_Control()
    {

    }

    void ServerLibrary::Data_Control::PopFromStackOfInputPraises(
        class ServerLibrary::Input* referenceForCore,
        std::vector<class ServerLibrary::Input*>* ptr_inputStack
    )
    {

    }

    void Data_Control::PopFromStackOfOutput(
        class ServerLibrary::Output* distributeBuffer,
        std::vector<class ServerLibrary::Output*>* ptr_outputStack
    )
    {

    }

    void Data_Control::PushToStackOfInputPraises(
        std::vector<class ServerLibrary::Input*>* ptr_InputStack,
        class ServerLibrary::Input* ptr_Buffer_Praise
    )
    {

    }

    void Data_Control::PushToStackOfOutput(
        std::vector<class ServerLibrary::Output*>* ptr_outputStack,
        class ServerLibrary::Output* ptr_referenceForCore
    )
    {

    }

    bool Data_Control::GetFlag_InputStackLoaded()
    {
        return flag_InputStackLoaded;
    }
    bool Data_Control::GetFlag_OutputStackLoaded()
    {
        return flag_OutputStackLoaded;
    }


    void Data_Control::SetFlag_InputStackLoaded(bool value)
    {
        flag_InputStackLoaded = value;
    }
    void Data_Control::SetFlag_OutputStackLoaded(bool value)
    {
        flag_OutputStackLoaded = value;
    }
}