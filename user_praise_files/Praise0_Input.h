#pragma once

namespace ServerLibrary
{
	class Praise0_Input
	{
	public:
		Praise0_Input();
		virtual ~Praise0_Input();

		unsigned short int Get_mouse_X();
		unsigned short int Get_mouse_Y();

		void Set_mouse_X(unsigned short int value);
		void Set_mouse_Y(unsigned short int value);

	protected:

	private:
		static unsigned short int mouse_X;
		static unsigned short int mouse_Y;
	};
}