#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include "Server.h"
#include "Data.h"
#include "Input.h"
#include "Output.h"
#include "user_praise_files\\Praise0_Input.h"
#include "user_praise_files\\Praise0_Output.h"
#include "..\\engine\write_enable\WriteEnable_Stack_Server_InputAction_Framework.h"
#include "..\\engine\\write_enable\\WriteEnable_Stack_Server_OutputRecieve_Framework.h"

namespace Server_Library
{
    class Framework_Server
    {
    public:
        Framework_Server();
        virtual ~Framework_Server();

        static void Create_Hosting_Server();
        static void End_Write_Stack_Server_InputAction(__int8 coreId);
        static void End_Write_Stack_Server_OutputAction(__int8 coreId);
        static void Flip_InBufferToWrite();
        static void Flip_OutBufferToWrite();
        static void Request_Write_Stack_Server_InputAction(__int8 coreId);
        static void Request_Write_Stack_Server_OutputAction(__int8 coreId);

        static void Pop_Stack_InputPraises(__int8 concurrentCoreId);
        static void Pop_Stack_Output();

        static class Server* Get_HostServer();
        static __int8 Get_NumberOfCores();
        static class WaitEnableWrite::WriteEnable_Stack_Server_InputAction_Framework* Get_WriteEnable_Stack_InputPraise();
        static class WaitEnableWrite::WriteEnable_Stack_Server_OutputRecieve_Framework* Get_WriteEnable_Stack_OutputPraise();

        static __int16 Get_PraiseEventId();
        static void Set_PraiseEventId(__int16 value);
//===
        static float Get_Praise1_pitch();
        static float Get_Praise1_yaw();
        
        static void Set_Praise1_mousePos_X(__int16 value);
        static void Set_Praise1_mousePos_Y(__int16 value);
//===
    protected:

    private:
        static class Server_Library::Server* ptr_HostServer;
    };
}