#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include "Server.h"
#include "Data.h"
#include "user_praise_files\\Praise0_Input.h"
#include "user_praise_files\\Praise0_Output.h"

namespace Server_Library
{
    class Framework_Server
    {
    public:
        Framework_Server();
        virtual ~Framework_Server();

        static void Create_Server();
        static Framework_Server Get_HostServer();

        static bool Get_Ack_InputAction_Capture();
        static __int16 Get_PraiseEventId();
        static float Get_Praise0_pitch();
        static float Get_Praise0_yaw();

        static bool Set_Ack_InputAction_Capture(bool value);
        static void Set_PraiseEventId(__int16 value);
        static void Set_Praise0_mousePos_X(__int16 value);
        static void Set_Praise0_mousePos_Y(__int16 value);

    protected:

    private:
        static class Framework_Server* ptr_HostServer;
    };
}