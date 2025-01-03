#include "Concurrent_Control.h"

namespace ServerLibrary
{

	Concurrent_Control::Concurrent_Control()
	{

	}
	Concurrent_Control::~Concurrent_Control()
	{

	}

	void Concurrent_Control::SelectSet_Algorithm_Subset_For_Given_PraiseEventId(
		int* ptr_praiseEventId,
		unsigned char concurrent_coreId
	)
	{
		switch (*ptr_praiseEventId)
		{
//===
//===	
		case 0:
			ServerLibrary::Framework::Get_Server()->Get_Algorithms()->Get_Concurren_Array(int(concurrent_coreId))->Set_Algorithm_Subset(
				reinterpret_cast<class Object*>(ServerLibrary::Framework::Get_Server()->Get_Algorithms()->Get_User_Algorithms()->Get_Praise0_Algorithm())
			);
			break;

		case 1:
			//TODO for each praise
			break;
//===
//===	
		}
	}
}