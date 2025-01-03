#include "Praise0_Input.h"

namespace ServerLibrary
{
	unsigned short int ServerLibrary::Praise0_Input::mouse_X;
	unsigned short int ServerLibrary::Praise0_Input::mouse_Y;

	Praise0_Input::Praise0_Input()
	{
		mouse_X = unsigned short int(0);
		mouse_Y = unsigned short int(0);
	}

	Praise0_Input::~Praise0_Input()
	{
	}

	unsigned short int Praise0_Input::Get_mouse_X()
	{
		return mouse_X;
	}

	unsigned short int Praise0_Input::Get_mouse_Y()
	{
		return mouse_Y;
	}

	void Praise0_Input::Set_mouse_X(unsigned short int value)
	{
		mouse_X = value;
	}

	void Praise0_Input::Set_mouse_Y(unsigned short int value)
	{
		mouse_Y = value;
	}
}