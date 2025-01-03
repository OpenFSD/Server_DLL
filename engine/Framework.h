#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include "Server.h"

namespace ServerLibrary
{
    class Framework
    {
    public:
        Framework();
        virtual ~Framework();
        static class Server* Get_Server();

    protected:

    private:
        static class Server* ptr_Server;
    };
}