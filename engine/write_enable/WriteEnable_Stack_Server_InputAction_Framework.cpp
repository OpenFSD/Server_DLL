#include "WriteEnable_Stack_Server_InputAction_Framework.h"
#include <cstddef>

namespace WaitEnableWrite
{
	class WaitEnableWrite::WriteEnable_Stack_Server_InputAction* WriteEnable_Stack_Server_InputAction_Framework::ptr_WriteEnable = NULL;

	WriteEnable_Stack_Server_InputAction_Framework::WriteEnable_Stack_Server_InputAction_Framework()
	{
		ptr_WriteEnable = NULL;
	}

	WriteEnable_Stack_Server_InputAction_Framework::~WriteEnable_Stack_Server_InputAction_Framework()
	{

	}

	void WriteEnable_Stack_Server_InputAction_Framework::Create_WriteEnable()
	{
		ptr_WriteEnable = new class WaitEnableWrite::WriteEnable_Stack_Server_InputAction();
		while (ptr_WriteEnable == NULL) { /* wait untill created */ }
	}

	void WriteEnable_Stack_Server_InputAction_Framework::Write_End(unsigned char coreId)
	{
		ptr_WriteEnable->Write_End(coreId);
	}

	void WriteEnable_Stack_Server_InputAction_Framework::Write_Start(unsigned char coreId)
	{
		ptr_WriteEnable->Write_Start(coreId);
	}

	WaitEnableWrite::WriteEnable_Stack_Server_InputAction* WriteEnable_Stack_Server_InputAction_Framework::Get_WriteEnable()
	{
		return ptr_WriteEnable;
	}
}