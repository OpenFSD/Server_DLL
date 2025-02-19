#pragma once
#include "Framework_Server.h"

namespace Server_Library
{
    class Output_Control
    {
    public:
        Output_Control();
        virtual ~Output_Control();
        void LoadValuesInToInputSubset(__int8 concurrent_CoreId, int* praiseEventId);
        void SelectSetOutputSubset(int* ptr_praiseEventId, __int8 concurrent_coreId);

    protected:

    private:

    };
}