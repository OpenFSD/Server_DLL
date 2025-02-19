#include "Concurrent_Control.h"

namespace Server_Library
{

	Concurrent_Control::Concurrent_Control()
	{

	}
	Concurrent_Control::~Concurrent_Control()
	{

	}

	void Concurrent_Control::SelectSet_Algorithm_Subset_For_Given_PraiseEventId(
		__int16 ptr_praiseEventId,
		__int8 concurrent_coreId
	)
	{
		switch (ptr_praiseEventId)
		{
		case 0:
			//class Object* obj_praise0 = (class Object*)Server_Library::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_User_Algorithms()->Get_Praise0_Algorithm();
			break;

		case 1:
			//class Object* obj_praise1 = (class Object*)Server_Library::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_User_Algorithms()->Get_Praise1_Algorithm();
			break;
		}
	}
}