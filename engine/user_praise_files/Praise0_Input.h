#pragma once

namespace Server_Library
{
	class Praise0_Input
	{
	public:
		Praise0_Input();
		virtual ~Praise0_Input();

		__int16 Get_mouse_X();
		__int16 Get_mouse_Y();

		void Set_mouse_X(__int16 value);
		void Set_mouse_Y(__int16 value);

	protected:

	private:
		static __int16 mouse_X;
		static __int16 mouse_Y;
	};
}