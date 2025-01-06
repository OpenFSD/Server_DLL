#include "Input.h"
#include <cstddef>

namespace Server_Library
{
    class Input_Control* Input::ptr_Input_Control = NULL;
    class Object* Input::ptr_Buffer_SubSet_InputPraise = NULL;
    int* Input::ptr_in_praiseEventId = NULL;

    Input::Input()
    {
        ptr_Buffer_SubSet_InputPraise = NULL;
        
        ptr_in_praiseEventId = new int(0);
        while (ptr_in_praiseEventId == NULL) { /* wait untill created */ }
    }

    Input::~Input()
    {
        delete ptr_Input_Control;
        delete ptr_Buffer_SubSet_InputPraise;
        delete ptr_in_praiseEventId;
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

    int* Input::GetPraiseEventId()
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

    void Input::SetPraiseEventId(int value)
    {
        ptr_in_praiseEventId = &value;
    }
}