#pragma once
#include "Framework.h"
#include "..\\user_praise_files\\User_I.h"
#include "..\\user_praise_files\\Praise0_Input.h"
#include "..\\user_praise_files\\Praise1_Input.h"

namespace ServerLibrary
{
    class Input_Control
    {
    public:
        Input_Control();
        virtual ~Input_Control();
        
        void LoadValuesInToInputSubset(unsigned char concurrent_CoreId, int* praiseEventId);
        void SelectSetInputSubset(int* ptr_praiseEventId);

    protected:

    private:

    };
}