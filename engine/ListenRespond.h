#pragma once
#include "ListenRespond_Control.h"
#include "Framework_Server.h"

namespace Server_Library
{
    class ListenRespond
    {
    public:
        ListenRespond();
        virtual ~ListenRespond();

        void Initialise_Control();
        static void Thread_IO_ListenDistribute(
            unsigned char coreId,
            unsigned char* ptr_MyNumImplementedCores
        );

        class ListenRespond_Control* Get_ListenRespond_Control();

    protected:

    private:
        static class ListenRespond_Control* ptr_ListenRespond_Control;
    };
}