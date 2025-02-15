#pragma once

namespace Server_Library
{
	class Praise1_Output
	{
	public:
		Praise1_Output();
		virtual ~Praise1_Output();

		float GetPitch();
		float GetYaw();

		void SetPitch(float value);
		void SetYaw(float value);

	protected:

	private:
		static float _pitch;
		static float _yaw;
	};
}