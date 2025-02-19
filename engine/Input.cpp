#include "Input.h"
#include <cstddef>

namespace Server_Library
{
    class Input_Control* Input::ptr_Input_Control = NULL;
    class Object* Input::ptr_Buffer_SubSet_InputPraise = NULL;
    __int16 Input::ptr_in_praiseEventId = NULL;

    Input::Input()
    {
        ptr_Input_Control = NULL;
        ptr_Buffer_SubSet_InputPraise = NULL;
        ptr_in_praiseEventId = __int16(0);
    }

    Input::~Input()
    {
        delete ptr_Input_Control;
        delete ptr_Buffer_SubSet_InputPraise;
    }

    void Input::Initialise_Control()
    {
        ptr_Input_Control = new class Server_Library::Input_Control();
        while (ptr_Input_Control == NULL) { /* wait untill created */ }
    }

    class Input_Control* Input::Get_Input_Control()
    {
        return ptr_Input_Control;
    }

    __int16 Input::GetPraiseEventId()
    {
        return ptr_in_praiseEventId;
    }

    class Object* Input::Get_InputBufferSubset()
    {
        return ptr_Buffer_SubSet_InputPraise;
    }

    void Input::Set_Subset_InputBuffer(Object* value)
    {
        ptr_Buffer_SubSet_InputPraise = value;
    }

    void Input::SetPraiseEventId(__int16 value)
    {
        ptr_in_praiseEventId = value;
    }
}