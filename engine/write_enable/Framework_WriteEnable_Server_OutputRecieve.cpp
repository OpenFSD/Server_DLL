#include "Framework_WriteEnable_Server_OutputRecieve.h"
#include <cstddef>

namespace WaitEnableWrite
{
	class WaitEnableWrite::WriteEnable_Server_OutputRecieve* Framework_WriteEnable_Server_OutputRecieve::ptr_WriteEnable = NULL;

	Framework_WriteEnable_Server_OutputRecieve::Framework_WriteEnable_Server_OutputRecieve()
	{
		ptr_WriteEnable = NULL;
	}

	Framework_WriteEnable_Server_OutputRecieve::~Framework_WriteEnable_Server_OutputRecieve()
	{

	}

	void Framework_WriteEnable_Server_OutputRecieve::Create_WriteEnable()
	{
		ptr_WriteEnable = new class WaitEnableWrite::WriteEnable_Server_OutputRecieve();
		while (ptr_WriteEnable == NULL) { /* wait untill created */ }
	}

	void Framework_WriteEnable_Server_OutputRecieve::Write_End(unsigned char coreId)
	{
		ptr_WriteEnable->Write_End(coreId);
	}

	void Framework_WriteEnable_Server_OutputRecieve::Write_Start(unsigned char coreId)
	{
		ptr_WriteEnable->Write_Start(coreId);
	}

	WaitEnableWrite::WriteEnable_Server_OutputRecieve* Framework_WriteEnable_Server_OutputRecieve::Get_WriteEnable()
	{
		return ptr_WriteEnable;
	}
}