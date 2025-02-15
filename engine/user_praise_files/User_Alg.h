#pragma once
#include "Praise0_Algorithm.h"
#include "Praise1_Algorithm.h"

namespace Server_Library
{
	class User_Alg
	{
	public:
		User_Alg();
		virtual ~User_Alg();
		class Praise0_Algorithm* Get_Praise0_Algorithm();
		class Praise1_Algorithm* Get_Praise1_Algorithm();

	protected:

	private:
		static class Praise0_Algorithm* ptr_Praise0_Algorithm;
		static class Praise1_Algorithm* ptr_Praise1_Algorithm;
	};
}

