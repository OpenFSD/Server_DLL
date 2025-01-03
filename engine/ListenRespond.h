#pragma once
#include "ListenRespond_Control.h"
#include "Framework.h"

namespace ServerLibrary
{
    class ListenRespond
    {
    public:
        ListenRespond();
        virtual ~ListenRespond();
        void Initialise_Control();

        class ListenRespond_Control* Get_ListenRespond_Control();

    protected:

    private:
        static class ListenRespond_Control* ptr_ListenRespond_Control;
    };
}