#include "Input_Control.h"
#include <cstddef>

namespace ServerLibrary
{

	Input_Control::Input_Control()
	{

	}
	Input_Control::~Input_Control()
	{

	}

    void Input_Control::LoadValuesInToInputSubset(unsigned char concurrent_CoreId, int* praiseEventId)
    {
        class Object* subSet_BackBuffer = NULL; 
        class Object* subSet_ThirdBuffer = NULL;

        switch (*praiseEventId)
        {
            case 0: {
                Praise0_Input* subSet_ThirdBuffer = reinterpret_cast <class Praise0_Input*>(ServerLibrary::Framework::Get_Server()->Get_Data()->Get_InputRefferenceOfCore(concurrent_CoreId)->Get_InputBufferSubset());
                Praise0_Input* subSet_BackBuffer = reinterpret_cast <class Praise0_Input*>(ServerLibrary::Framework::Get_Server()->Get_Data()->GetBuffer_InputBackDouble()->Get_InputBufferSubset());
                subSet_ThirdBuffer->Set_mouse_X(subSet_BackBuffer->Get_mouse_X());
                subSet_ThirdBuffer->Set_mouse_Y(subSet_BackBuffer->Get_mouse_Y());
                break;
            }
            case 1: {
                Praise1_Input* subSet_ThirdBuffer = reinterpret_cast <class Praise1_Input*>(ServerLibrary::Framework::Get_Server()->Get_Data()->Get_InputRefferenceOfCore(concurrent_CoreId)->Get_InputBufferSubset());
                Praise1_Input* subSet_BackBuffer = reinterpret_cast <class Praise1_Input*>(ServerLibrary::Framework::Get_Server()->Get_Data()->GetBuffer_InputBackDouble()->Get_InputBufferSubset());
                subSet_ThirdBuffer->SetPlayer_Positiion_X(subSet_BackBuffer->GetPlayer_Position_X());
                subSet_ThirdBuffer->SetPlayer_Positiion_Y(subSet_BackBuffer->GetPlayer_Position_Y());
                subSet_ThirdBuffer->SetPlayer_Positiion_Z(subSet_BackBuffer->GetPlayer_Position_Z());
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
            ServerLibrary::Framework::Get_Server()->Get_Data()->GetBuffer_InputFrontDouble()->Set_Subset_InputBuffer(
                reinterpret_cast<class Object*>(ServerLibrary::Framework::Get_Server()->Get_Data()->Get_User_I()->Get_Praise0_Input())
            );
            break;

        case 1:
            ServerLibrary::Framework::Get_Server()->Get_Data()->GetBuffer_InputFrontDouble()->Set_Subset_InputBuffer(
                reinterpret_cast<class Object*>(ServerLibrary::Framework::Get_Server()->Get_Data()->Get_User_I()->Get_Praise1_Input())
            );
            break;
        }
    }
}