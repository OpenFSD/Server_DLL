#include "Praise0_Output.h"
#include <cstddef>

namespace Server_Library
{
	const double PI = 3.141592653589793238463;

	float Praise0_Output::_pitch = NULL;
	float Praise0_Output::_yaw = NULL;

	Praise0_Output::Praise0_Output()
	{
		_pitch = 0;
		_yaw = -(PI / 2);
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