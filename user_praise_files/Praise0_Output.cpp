#include "Praise0_Output.h"

namespace ServerLibrary
{
	double Praise0_Output::_front[3] = {NULL, NULL, NULL};
	double Praise0_Output::_up[3] = { NULL, NULL, NULL };
	double Praise0_Output::_right[3] = { NULL, NULL, NULL };
	float Praise0_Output::_pitch = NULL;
	float Praise0_Output::_yaw = NULL;

	Praise0_Output::Praise0_Output()
	{
		for(int axis = 0; axis < 3; axis++)
		{
			_front[axis] = 0;
			_up[axis] = 0;
			_right[axis] = 0;
		}
		_pitch = 0;
		_yaw = -(M_PI / 2);
	}

	Praise0_Output::~Praise0_Output()
	{
	}

	double Praise0_Output::GetFront(short axis)
	{
		return _front[axis];
	}
	double Praise0_Output::GetUp(short axis)
	{
		return _up[axis];
	}
	double Praise0_Output::GetRight(short axis)
	{
		return _right[axis];
	}
	float Praise0_Output::GetPitch()
	{
		return _pitch;
	}
	float Praise0_Output::GetYaw()
	{
		return _yaw;
	}
	void Praise0_Output::SetFront(double value, short axis)
	{
		_front[axis] = value;
	}
	void Praise0_Output::SetUp(double value, short axis)
	{
		_up[axis] = value;
	}
	void Praise0_Output::SetRight(double value, short axis)
	{
		_right[axis] = value;
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