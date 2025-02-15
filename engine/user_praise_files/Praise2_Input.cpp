#include "Praise2_Input.h"

namespace Server_Library
{
	double Praise2_Input::_player_position_X;
	double Praise2_Input::_player_position_Y;
	double Praise2_Input::_player_position_Z;

	Praise2_Input::Praise2_Input()
	{

	}

	Praise2_Input::~Praise2_Input()
	{

	}

	double Praise2_Input::GetPlayer_Position_X()
	{
		return _player_position_X;
	}
	double Praise2_Input::GetPlayer_Position_Y()
	{
		return _player_position_Y;
	}
	double Praise2_Input::GetPlayer_Position_Z()
	{
		return _player_position_Z;
	}

	void Praise2_Input::SetPlayer_Position_X(double value)
	{
		_player_position_X = value;
	}
	void Praise2_Input::SetPlayer_Position_Y(double value)
	{
		_player_position_Y = value;
	}
	void Praise2_Input::SetPlayer_Position_Z(double value)
	{
		_player_position_Z = value;
	}
}