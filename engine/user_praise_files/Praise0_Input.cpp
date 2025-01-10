#include "Praise0_Input.h"

namespace Server_Library
{
	__int16 Server_Library::Praise0_Input::mouse_X;
	__int16 Server_Library::Praise0_Input::mouse_Y;

	Praise0_Input::Praise0_Input()
	{
		mouse_X = __int16(0);
		mouse_Y = __int16(0);
	}

	Praise0_Input::~Praise0_Input()
	{
	}

	__int16 Praise0_Input::Get_mouse_X()
	{
		return mouse_X;
	}

	__int16 Praise0_Input::Get_mouse_Y()
	{
		return mouse_Y;
	}

	void Praise0_Input::Set_mouse_X(__int16 value)
	{
		mouse_X = value;
	}

	void Praise0_Input::Set_mouse_Y(__int16 value)
	{
		mouse_Y = value;
	}
}