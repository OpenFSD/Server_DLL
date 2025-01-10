#pragma once
#include "Praise0_Algorithm.h"

namespace Server_Library
{
	class User_Alg
	{
	public:
		User_Alg();
		virtual ~User_Alg();
		class Praise0_Algorithm* Get_Praise0_Algorithm();

	protected:

	private:
		static class Praise0_Algorithm* ptr_Praise0_Algorithm;
	};
}

