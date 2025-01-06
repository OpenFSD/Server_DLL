#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include "Server.h"
#include "user_praise_files\\Praise0_Input.h"
#include "user_praise_files\\Praise0_Output.h"

namespace Server_Library
{
    public class Framework_Server
    {
    public:
        Framework_Server();
        virtual ~Framework_Server();

        static void Create_Server();

        static float Get_Praise0_pitch();
        static float Get_Praise0_yaw();
        static void Set_Praise0_mousePos_X(__int16 value);
        static void Set_Praise0_mousePos_Y(__int16 value);

        static class Server* Get_Server();

    protected:

    private:
        static class Server* ptr_Server;
    };
}