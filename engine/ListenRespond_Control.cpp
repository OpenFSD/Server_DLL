#include "ListenRespond_Control.h"

namespace Server_Library
{
    bool ListenRespond_Control::flag_Ack_InputAction_Capture = false;
    bool ListenRespond_Control::flag_IO_ThreadState = false;

    ListenRespond_Control::ListenRespond_Control()
    {
        flag_IO_ThreadState = new bool(true);
    }
    ListenRespond_Control::~ListenRespond_Control()
    {

    }

    bool ListenRespond_Control::GetFlag_Acknowledge_Input_Capture()
    {
        return flag_Ack_InputAction_Capture;
    }

    bool ListenRespond_Control::GetFlag_IO_ThreadState()
    {
        return flag_IO_ThreadState;
    }

    void ListenRespond_Control::SetFlag_Acknowledge_Input_Capture(bool value)
    {
        flag_Ack_InputAction_Capture = value;
    }

    void ListenRespond_Control::SetFlag_IO_ThreadState(bool value)
    {
        flag_IO_ThreadState = value;
    }
}