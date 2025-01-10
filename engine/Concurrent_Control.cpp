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
		unsigned char concurrent_coreId
	)
	{
		switch (ptr_praiseEventId)
		{
//===
//===	
		case 0:
			class Object* obj = (class Object*)Server_Library::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_User_Algorithms()->Get_Praise0_Algorithm();
			Server_Library::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_Concurren_Array(int(concurrent_coreId))->Set_Algorithm_Subset(obj);
			break;

		case 1:
			//TODO for each praise
			break;
//===
//===	
		}
	}
}