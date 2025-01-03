#pragma once
#include <cmath>
#include <corecrt_math_defines.h>

namespace ServerLibrary
{
	class Praise0_Output
	{
	public:
		Praise0_Output();
		virtual ~Praise0_Output();

		double GetFront(short axis);
		double GetUp(short axis);
		double GetRight(short axis);
		float GetPitch();
		float GetYaw();

		void SetFront(double value, short x_value);
		void SetUp(double value, short x_value);
		void SetRight(double value, short x_value);
		void SetPitch(float value);
		void SetYaw(float value);

	protected:

	private:
		static double _front[3];
		static double _up[3];
		static double _right[3];
		static float _pitch;
		static float _yaw;
	};
}