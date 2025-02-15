#include "Framework_WriteEnable_Server_InputAction.h"
#include <cstddef>

namespace WaitEnableWrite
{
	class WaitEnableWrite::WriteEnable_Server_InputAction* Framework_WriteEnable_Server_InputAction::ptr_WriteEnable = NULL;

	Framework_WriteEnable_Server_InputAction::Framework_WriteEnable_Server_InputAction()
	{
		ptr_WriteEnable = NULL;
	}

	Framework_WriteEnable_Server_InputAction::~Framework_WriteEnable_Server_InputAction()
	{

	}

	void Framework_WriteEnable_Server_InputAction::Create_WriteEnable()
	{
		ptr_WriteEnable = new class WaitEnableWrite::WriteEnable_Server_InputAction();
		while (ptr_WriteEnable == NULL) { /* wait untill created */ }
	}

	void Framework_WriteEnable_Server_InputAction::Write_End(unsigned char coreId)
	{
		ptr_WriteEnable->Write_End(coreId);
	}

	void Framework_WriteEnable_Server_InputAction::Write_Start(unsigned char coreId)
	{
		ptr_WriteEnable->Write_Start(coreId);
	}

	WaitEnableWrite::WriteEnable_Server_InputAction* Framework_WriteEnable_Server_InputAction::Get_WriteEnable()
	{
		return ptr_WriteEnable;
	}
}