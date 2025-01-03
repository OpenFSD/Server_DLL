#include "Framework.h"
#include <cstddef>

namespace ServerLibrary
{
	class ServerLibrary::Server* Framework::ptr_Server = NULL;

	Framework::Framework()
	{
		ptr_Server = new class ServerLibrary::Server();
		while (ptr_Server == NULL) { /* wait untill created */ }
		ptr_Server->Get_Execute()->Initialise();
		ptr_Server->Get_Execute()->Initialise_Threads();
	}

	Framework::~Framework()
	{

	}

	ServerLibrary::Server* Framework::Get_Server()
	{
		return ptr_Server;
	}

}