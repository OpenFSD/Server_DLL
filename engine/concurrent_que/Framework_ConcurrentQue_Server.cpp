#include "Framework_ConcurrentQue_Server.h"
#include <cstddef>

namespace ConcurrentQue
{
	class LaunchConcurrency_Server* Framework_ConcurrentQue_Server::ptr_LaunchConcurrency = NULL;

	Framework_ConcurrentQue_Server::Framework_ConcurrentQue_Server()
	{
		
	}

	Framework_ConcurrentQue_Server::~Framework_ConcurrentQue_Server()
	{

	}

	void Framework_ConcurrentQue_Server::Request_Wait_Launch_ConcurrentThread()
	{
		ConcurrentQue::Framework_ConcurrentQue_Server::Get_LaunchConcurrency()->Thread_Start();
	}
	void Framework_ConcurrentQue_Server::Concurrent_Thread_End(unsigned char concurrent_CoreId)
	{
		ConcurrentQue::Framework_ConcurrentQue_Server::Get_LaunchConcurrency()->Thread_End(concurrent_CoreId);
	}

	void Framework_ConcurrentQue_Server::Create_ConcurrentQue()
	{
		ptr_LaunchConcurrency = new class ConcurrentQue::LaunchConcurrency_Server();
		while (ptr_LaunchConcurrency == NULL) { /* wait untill created */ }
		ptr_LaunchConcurrency->Initialise_Control(
			ConcurrentQue::Framework_ConcurrentQue_Server::Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency(),
			ConcurrentQue::Framework_ConcurrentQue_Server::Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency()->Get_NumCores()
		);
	}

	LaunchConcurrency_Server* Framework_ConcurrentQue_Server::Get_LaunchConcurrency()
	{
		return ptr_LaunchConcurrency;
	}
	__int16 Framework_ConcurrentQue_Server::Get_coreId_To_Launch()
	{
		return ConcurrentQue::Framework_ConcurrentQue_Server::Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->Get_coreId_To_Launch();
	}

	bool Framework_ConcurrentQue_Server::Get_Flag_Active()
	{
		return ConcurrentQue::Framework_ConcurrentQue_Server::Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency()->GetConst_Core_ACTIVE();
	}

	bool Framework_ConcurrentQue_Server::Get_Flag_Idle()
	{
		return ConcurrentQue::Framework_ConcurrentQue_Server::Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency()->GetConst_Core_IDLE();
	}

	bool Framework_ConcurrentQue_Server::Get_State_LaunchBit()
	{
		return ConcurrentQue::Framework_ConcurrentQue_Server::Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->Get_State_ConcurrentCore(0);
	}

}