#include "Praise0_Output.h"

namespace Server_Library
{
	float Praise0_Output::_pitch = NULL;
	float Praise0_Output::_yaw = NULL;

	Praise0_Output::Praise0_Output()
	{
		_pitch = 0;
		_yaw = -(M_PI / 2);
	}

	Praise0_Output::~Praise0_Output()
	{
	}

	float Praise0_Output::GetPitch()
	{
		return _pitch;
	}
	float Praise0_Output::GetYaw()
	{
		return _yaw;
	}

	void Praise0_Output::SetPitch(float value)
	{
		_pitch = value;
	}

	void Praise0_Output::SetYaw(float value)
	{
		_yaw = value;
	}
}