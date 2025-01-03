#pragma once

namespace ServerLibrary
{
    class ListenRespond_Control
    {
    public:
        ListenRespond_Control();
        ~ListenRespond_Control();
        bool GetFlag_IO_ThreadState();
        void SetFlag_IO_ThreadState(bool value);

    protected:

    private:
        static bool flag_IO_ThreadState;
    };
}
