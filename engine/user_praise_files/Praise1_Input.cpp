#include "Praise1_Input.h"

namespace Server_Library
{
	double Praise1_Input::_player_position_X;
	double Praise1_Input::_player_position_Y;
	double Praise1_Input::_player_position_Z;

	Praise1_Input::Praise1_Input()
	{

	}

	Praise1_Input::~Praise1_Input()
	{

	}

	double Praise1_Input::GetPlayer_Position_X()
	{
		return _player_position_X;
	}
	double Praise1_Input::GetPlayer_Position_Y()
	{
		return _player_position_Y;
	}
	double Praise1_Input::GetPlayer_Position_Z()
	{
		return _player_position_Z;
	}

	void Praise1_Input::SetPlayer_Positiion_X(double value)
	{
		_player_position_X = value;
	}
	void Praise1_Input::SetPlayer_Positiion_Y(double value)
	{
		_player_position_Y = value;
	}
	void Praise1_Input::SetPlayer_Positiion_Z(double value)
	{
		_player_position_Z = value;
	}
}