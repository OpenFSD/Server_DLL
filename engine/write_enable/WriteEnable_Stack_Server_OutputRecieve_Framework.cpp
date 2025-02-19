#include "WriteEnable_Stack_Server_OutputRecieve_Framework.h"
#include <cstddef>

namespace WaitEnableWrite
{
	class WaitEnableWrite::WriteEnable_Stack_Server_OutputRecieve* WriteEnable_Stack_Server_OutputRecieve_Framework::ptr_WriteEnable = NULL;

	WriteEnable_Stack_Server_OutputRecieve_Framework::WriteEnable_Stack_Server_OutputRecieve_Framework()
	{
		ptr_WriteEnable = NULL;
	}

	WriteEnable_Stack_Server_OutputRecieve_Framework::~WriteEnable_Stack_Server_OutputRecieve_Framework()
	{

	}

	void WriteEnable_Stack_Server_OutputRecieve_Framework::Create_WriteEnable()
	{
		ptr_WriteEnable = new class WaitEnableWrite::WriteEnable_Stack_Server_OutputRecieve();
		while (ptr_WriteEnable == NULL) { /* wait untill created */ }
	}

	void WriteEnable_Stack_Server_OutputRecieve_Framework::Write_End(__int8 coreId)
	{
		ptr_WriteEnable->Write_End(coreId);
	}

	void WriteEnable_Stack_Server_OutputRecieve_Framework::Write_Start(__int8 coreId)
	{
		ptr_WriteEnable->Write_Start(coreId);
	}

	WaitEnableWrite::WriteEnable_Stack_Server_OutputRecieve* WriteEnable_Stack_Server_OutputRecieve_Framework::Get_WriteEnable()
	{
		return ptr_WriteEnable;
	}
}