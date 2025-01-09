#pragma once

namespace Server_Library
{
	class Praise1_Output
	{
	public:
		Praise1_Output();
		virtual ~Praise1_Output();


	protected:

	private:
		static double _position[3];
		static double _front[3];
		static double _up[3];
		static double _right[3];
	};
}