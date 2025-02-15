#pragma once

namespace Server_Library
{
	class Praise2_Output
	{
	public:
		Praise2_Output();
		virtual ~Praise2_Output();


	protected:

	private:
		static double _position[3];
		static double _front[3];
		static double _up[3];
		static double _right[3];
	};
}