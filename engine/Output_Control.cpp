#include "Output_Control.h"

namespace ServerLibrary
{
	Output_Control::Output_Control()
	{

	}
	Output_Control::~Output_Control()
	{

	}

	void Output_Control::LoadValuesInToInputSubset(unsigned char concurrent_CoreId, int* praiseEventId)
	{

	}

	void Output_Control::SelectSetOutputSubset(
		int* ptr_praiseEventId,
		unsigned char concurrent_coreId
	)
	{
		switch (*ptr_praiseEventId)
		{
		case 0:
			//ServerLibrary::Framework::Get_Server()->Get_Data()->Get_OutputRefferenceOfCore(concurrent_coreId)->Set_OutputBuffer_Subset(
			//	reinterpret_cast<class Object*>(ServerLibrary::Framework::Get_Server()->Get_Data()->Get_User_O()->Get_Praise0_Output())
			//);
			break;

		case 1:
			//TODO Praise 1
			break;
		}
	}
}