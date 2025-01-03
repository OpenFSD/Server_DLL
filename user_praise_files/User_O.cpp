#include "User_O.h"
#include <cstddef>

namespace ServerLibrary
{
	class Praise0_Output* User_O::ptr_Praise0_Output = NULL;

	User_O::User_O()
	{
		ptr_Praise0_Output = new class ServerLibrary::Praise0_Output();
		while (ptr_Praise0_Output == NULL) { /* wait untill class constructed */ }
	}
	User_O::~User_O()
	{
		delete ptr_Praise0_Output;
	}

	class Praise0_Output* User_O::Get_Praise0_Output()
	{
		return ptr_Praise0_Output;
	}
}