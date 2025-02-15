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

    void Server_Library::Data_Control::Pop_Stack_InputPraises(__int8 concurrentCoreId)
    {
        class Server_Library::Input* referenceForCore = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_InputRefferenceOfCore(concurrentCoreId);
        std::vector<class Server_Library::Input*>* ptr_inputStack = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Stack_InputPraise();
        referenceForCore = ptr_inputStack->at(1);
        ptr_inputStack->erase(ptr_inputStack->begin()+1);
        if (sizeof(ptr_inputStack) < 2)
        {
            SetFlag_InputStackLoaded(false);
        }
        else
        {
            SetFlag_InputStackLoaded(true);
        }
    }

    void Data_Control::Pop_Stack_Output()
    {
        class Output* distributeBuffer = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_OutputBackDouble();
        std::vector<class Output*>* ptr_outputStack = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Stack_OutputPraise();
        distributeBuffer = ptr_outputStack->at(1);
        ptr_outputStack->erase(ptr_outputStack->begin()+1);
        if (sizeof(ptr_outputStack) < 2)
        {
            SetFlag_OutputStackLoaded(false);
        }
        else
        {
            SetFlag_OutputStackLoaded(true);
        }
    }

    void Data_Control::Push_Stack_InputPraises()
    {
        std::vector<class Server_Library::Input*>* ptr_InputStack = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Stack_InputPraise();
        class Server_Library::Input* ptr_Buffer_Praise = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputBackDouble();
        ptr_InputStack->push_back(ptr_InputStack->at(0));
        ptr_InputStack->at(ptr_InputStack->size()) = ptr_Buffer_Praise;
        if (sizeof(ptr_InputStack) < 2)
        {
            SetFlag_InputStackLoaded(false);
        }
        else
        {
            SetFlag_InputStackLoaded(true);
        }
    }

    void Data_Control::Push_Stack_Output(__int8 concurrentCoreId)
    {
        std::vector<class Server_Library::Output*>* ptr_outputStack = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_Stack_OutputPraise();
        class Server_Library::Output* ptr_referenceForCore = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_OutputRefferenceOfCore(concurrentCoreId);
        ptr_outputStack->push_back(ptr_outputStack->at(0));
        ptr_outputStack->at(ptr_outputStack->size()) = ptr_referenceForCore;
        if (sizeof(ptr_outputStack) < 2)
        {
            SetFlag_OutputStackLoaded(false);
        }
        else
        {
            SetFlag_OutputStackLoaded(true);
        }
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