#pragma once

namespace Server_Library
{
	class Praise0_Output
	{
	public:
		Praise0_Output();
		virtual ~Praise0_Output();

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