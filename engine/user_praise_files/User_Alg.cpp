#include "User_Alg.h"
#include <cstddef>

namespace Server_Library
{
	class Praise0_Algorithm* User_Alg::ptr_Praise0_Algorithm = NULL;
	class Praise1_Algorithm* User_Alg::ptr_Praise1_Algorithm = NULL;

	User_Alg::User_Alg()
	{
		ptr_Praise0_Algorithm = new class Server_Library::Praise0_Algorithm();
		while (ptr_Praise0_Algorithm == NULL) { /* wait untill class constructed */ }

		ptr_Praise1_Algorithm = new class Server_Library::Praise1_Algorithm();
		while (ptr_Praise1_Algorithm == NULL) { /* wait untill class constructed */ }
	}
	User_Alg::~User_Alg()
	{
		delete ptr_Praise0_Algorithm;
	}

	class Praise0_Algorithm* User_Alg::Get_Praise0_Algorithm()
	{
		return ptr_Praise0_Algorithm;
	}

	class Praise1_Algorithm* User_Alg::Get_Praise1_Algorithm()
	{
		return ptr_Praise1_Algorithm;
	}
}       