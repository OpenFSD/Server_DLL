#include "Praise1_Output.h"
#include <cstddef>

namespace Server_Library
{
	float Praise1_Output::_pitch;
	float Praise1_Output::_yaw;

	Praise1_Output::Praise1_Output()
	{

	}

	Praise1_Output::~Praise1_Output()
	{
	}
	float Praise1_Output::GetPitch()
	{
		return _pitch;
	}
	float Praise1_Output::GetYaw()
	{
		return _yaw;
	}
	void Praise1_Output::SetPitch(float value)
	{
		_pitch = value;
	}
	void Praise1_Output::SetYaw(float value)
	{
		_yaw = value;
	}
}