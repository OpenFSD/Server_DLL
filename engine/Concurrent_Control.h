#pragma once
#include "Framework.h"
#include "..\\user_praise_files\\Praise0_Algorithm.h"

namespace ServerLibrary
{
    class Concurrent_Control
    {
    public:
        Concurrent_Control();
        virtual ~Concurrent_Control();
        void SelectSet_Algorithm_Subset_For_Given_PraiseEventId(
            int* ptr_praiseEventId,
            unsigned char concurrent_coreId
        );

    protected:

    private:

    };
}