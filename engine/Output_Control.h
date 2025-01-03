#pragma once
#include "Framework.h"

namespace ServerLibrary
{
    class Output_Control
    {
    public:
        Output_Control();
        virtual ~Output_Control();
        void LoadValuesInToInputSubset(unsigned char concurrent_CoreId, int* praiseEventId);
        void SelectSetOutputSubset(int* ptr_praiseEventId, unsigned char concurrent_coreId);

    protected:

    private:

    };
}