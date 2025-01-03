#include "ListenRespond.h"
#include <cstddef>

namespace ServerLibrary
{
    class ListenRespond_Control* ListenRespond::ptr_ListenRespond_Control = NULL;

    ListenRespond::ListenRespond()
    {
        ptr_ListenRespond_Control = NULL;
    }

    ListenRespond::~ListenRespond()
    {
        delete ptr_ListenRespond_Control;
    }

    void ListenRespond::Initialise_Control()
    {
        ptr_ListenRespond_Control = new class ServerLibrary::ListenRespond_Control();
        while (ptr_ListenRespond_Control == NULL) { /* wait untill class constructed */ }
    }

    class ListenRespond_Control* ListenRespond::Get_ListenRespond_Control()
    {
        return ptr_ListenRespond_Control;
    }
}
