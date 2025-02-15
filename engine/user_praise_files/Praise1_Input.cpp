#include "Praise1_Input.h"

namespace Server_Library
{
	__int16 Praise1_Input::mouse_X;
	__int16 Praise1_Input::mouse_Y;

	Praise1_Input::Praise1_Input()
	{

	}

	Praise1_Input::~Praise1_Input()
	{
	}
	__int16 Praise1_Input::Get_mouse_X()
	{
		return mouse_X;
	}
	__int16 Praise1_Input::Get_mouse_Y()
	{
		return mouse_Y;
	}
	void Praise1_Input::Set_mouse_X(__int16 value)
	{
		mouse_X = value;
	}
	void Praise1_Input::Set_mouse_Y(__int16 value)
	{
		mouse_Y = value;
	}
}