#include "ListenRespond_Control.h"

namespace Server_Library
{
    bool ListenRespond_Control::flag_Acknowledge_Input = false;
    bool ListenRespond_Control::flag_IO_ThreadState = false;

    ListenRespond_Control::ListenRespond_Control()
    {
        flag_IO_ThreadState = new bool(true);
    }
    ListenRespond_Control::~ListenRespond_Control()
    {

    }

    bool ListenRespond_Control::GetFlag_Acknowledge_Input()
    {
        return flag_Acknowledge_Input;
    }

    bool ListenRespond_Control::GetFlag_IO_ThreadState()
    {
        return flag_IO_ThreadState;
    }

    void ListenRespond_Control::SetFlag_Acknowledge_Input(bool value)
    {
        flag_Acknowledge_Input = value;
    }

    void ListenRespond_Control::SetFlag_IO_ThreadState(bool value)
    {
        flag_IO_ThreadState = value;
    }
}