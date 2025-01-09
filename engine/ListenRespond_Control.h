#pragma once

namespace Server_Library
{
    class ListenRespond_Control
    {
    public:
        ListenRespond_Control();
        ~ListenRespond_Control();

        bool GetFlag_Acknowledge_Input_Capture();
        bool GetFlag_IO_ThreadState();

        void SetFlag_Acknowledge_Input_Capture(bool value);
        void SetFlag_IO_ThreadState(bool value);

    protected:

    private:
        static bool flag_Ack_InputAction_Capture;
        static bool flag_IO_ThreadState;
    };
}
