#include "Input_Control.h"
#include <cstddef>

namespace Server_Library
{

	Input_Control::Input_Control()
	{

	}
	Input_Control::~Input_Control()
	{

	}

    void Input_Control::LoadValuesInToInputSubset(__int8 concurrent_CoreId, int* praiseEventId)
    {
        switch (*praiseEventId)
        {
        case 0: {

            break;
        }
        case 1: {
            Server_Library::Praise1_Input* subSet_ThirdBuffer = reinterpret_cast <class Praise1_Input*>(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_InputRefferenceOfCore(concurrent_CoreId)->Get_InputBufferSubset());
            Server_Library::Praise1_Input* subSet_BackBuffer = reinterpret_cast <class Praise1_Input*>(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputBackDouble()->Get_InputBufferSubset());
            subSet_ThirdBuffer->Set_mouse_X(subSet_BackBuffer->Get_mouse_X());
            subSet_ThirdBuffer->Set_mouse_Y(subSet_BackBuffer->Get_mouse_Y());
            break;
        }
        case 2: {
            Server_Library::Praise2_Input* subSet_ThirdBuffer = reinterpret_cast <class Praise2_Input*>(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_InputRefferenceOfCore(concurrent_CoreId)->Get_InputBufferSubset());
            Server_Library::Praise2_Input* subSet_BackBuffer = reinterpret_cast <class Praise2_Input*>(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputBackDouble()->Get_InputBufferSubset());
            subSet_ThirdBuffer->SetPlayer_Position_X(subSet_BackBuffer->GetPlayer_Position_X());
            subSet_ThirdBuffer->SetPlayer_Position_Y(subSet_BackBuffer->GetPlayer_Position_Y());
            subSet_ThirdBuffer->SetPlayer_Position_Z(subSet_BackBuffer->GetPlayer_Position_Z());
            break;
        }
        }
    }

    void Input_Control::SelectSetInputSubset(
        int* praiseEventId
    )
    {
        switch (*praiseEventId)
        {
        case 0:
            Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputFrontDouble()->Set_Subset_InputBuffer(
                reinterpret_cast<class Object*>(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_User_I()->Get_Praise0_Input())
            );
            break;

        case 1:
            Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputFrontDouble()->Set_Subset_InputBuffer(
                reinterpret_cast<class Object*>(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->Get_User_I()->Get_Praise1_Input())
            );
            break;
        }
    }
}