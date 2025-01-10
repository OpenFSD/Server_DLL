#pragma once

namespace Server_Library
{
	class Praise1_Input
	{
	public:
		Praise1_Input();
		virtual ~Praise1_Input();

		double GetPlayer_Position_X();
		double GetPlayer_Position_Y();
		double GetPlayer_Position_Z();

		void SetPlayer_Positiion_X(double value);
		void SetPlayer_Positiion_Y(double value);
		void SetPlayer_Positiion_Z(double value);

	protected:

	private:
		static double _player_position_X;
		static double _player_position_Y;
		static double _player_position_Z;
	};
}