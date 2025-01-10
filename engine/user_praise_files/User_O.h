#pragma once
#include "Praise0_Output.h"

namespace Server_Library
{
	class User_O
	{
	public:
		User_O();
		virtual ~User_O();
		class Praise0_Output* Get_Praise0_Output();

	protected:

	private:
		static class Praise0_Output* ptr_Praise0_Output;
	};
}