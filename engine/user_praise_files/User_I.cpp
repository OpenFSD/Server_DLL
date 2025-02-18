#include "User_I.h"
#include <cstddef>

namespace Server_Library
{
	class Praise0_Input* Server_Library::User_I::ptr_Praise0_Input = NULL;
	class Praise1_Input* Server_Library::User_I::ptr_Praise1_Input = NULL;

	User_I::User_I()
	{
		ptr_Praise0_Input = new class Server_Library::Praise0_Input();
		while (ptr_Praise0_Input == NULL) { /* wait untill class constructed */ }
	}
	User_I::~User_I()
	{
		delete ptr_Praise0_Input;
	}

	Praise0_Input* User_I::Get_Praise0_Input()
	{
		return ptr_Praise0_Input;
	}
	Praise1_Input* User_I::Get_Praise1_Input()
	{
		return ptr_Praise1_Input;
	}
}