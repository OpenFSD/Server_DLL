#include "Framework_Server.h"
#include <cstddef>

namespace Server_Library
{
	class Server_Library::Server* Framework_Server::ptr_HostServer;

	Framework_Server::Framework_Server()
	{
		
	}

	Framework_Server::~Framework_Server()
	{

	}

	void Framework_Server::Create_Hosting_Server()
	{
		ptr_HostServer = new class Server_Library::Server();
		while (ptr_HostServer == NULL) { /* wait untill created */ }
		ptr_HostServer->Get_Execute()->Initialise();
		ptr_HostServer->Get_Execute()->Initialise_Threads();
	}

	void Framework_Server::End_Write_Stack_Server_InputAction(__int8 coreId)
	{
		Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_InputPraise()->Write_End(coreId);
	}

	void Framework_Server::End_Write_Stack_Server_OutputAction(__int8 coreId)
	{
		Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_OutputPraise()->Write_End(coreId);
	}

	void Framework_Server::Flip_InBufferToWrite()
	{
	}

	void Framework_Server::Flip_OutBufferToWrite()
	{
	}

	void Framework_Server::Request_Write_Stack_Server_InputAction(__int8 coreId)
	{
		Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_InputPraise()->Write_Start(coreId);
	}

	void Framework_Server::Request_Write_Stack_Server_OutputAction(__int8 coreId)
	{
		Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_OutputPraise()->Write_Start(coreId);
	}

	void Framework_Server::Pop_Stack_InputPraises(__int8 concurrentCoreId)
	{

	}

	void Framework_Server::Pop_Stack_Output()
	{
		

	}

	class Server_Library::Server* Framework_Server::Get_HostServer()
	{
		return ptr_HostServer;
	}

	unsigned char Framework_Server::Get_NumberOfCores()
	{
		return Server_Library::Framework_Server::Get_HostServer()->Get_Global()->Get_NumCores();
	}

	WaitEnableWrite::WriteEnable_Stack_Server_InputAction_Framework* Framework_Server::Get_WriteEnable_Stack_InputPraise()
	{
		return Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_InputPraise();
	}

	WaitEnableWrite::WriteEnable_Stack_Server_OutputRecieve_Framework* Framework_Server::Get_WriteEnable_Stack_OutputPraise()
	{
		return Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_OutputPraise();
	}

	__int16 Framework_Server::Get_PraiseEventId()
	{
		Server_Library::Input* inputSet = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputFrontDouble();
		return inputSet->GetPraiseEventId();
	}
	float Framework_Server::Get_Praise1_pitch()
	{
		Server_Library::Praise1_Output* outputSubset = reinterpret_cast <class Praise1_Output*>(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_OututFrontDouble()->Get_OutputBuffer_Subset());
		return outputSubset->GetPitch();
	}

	float Framework_Server::Get_Praise1_yaw()
	{
		Server_Library::Praise1_Output* outputSubset = reinterpret_cast <class Praise1_Output*>(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_OututFrontDouble()->Get_OutputBuffer_Subset());
		return outputSubset->GetYaw();
	}


	void Framework_Server::Set_PraiseEventId(__int16 value)
	{
		Server_Library::Input* inputSet = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputFrontDouble();
		inputSet->SetPraiseEventId(value);
	}

	void Framework_Server::Set_Praise1_mousePos_X(__int16 value)
	{
		Server_Library::Praise1_Input* inputSubset = reinterpret_cast <class Praise1_Input*>(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputFrontDouble()->Get_InputBufferSubset());
		inputSubset->Set_mouse_X(value);
	}

	void Framework_Server::Set_Praise1_mousePos_Y(__int16 value)
	{
		Server_Library::Praise1_Input* inputSubset = reinterpret_cast <class Praise1_Input*>(Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputFrontDouble()->Get_InputBufferSubset());
		inputSubset->Set_mouse_Y(value);
	}

}