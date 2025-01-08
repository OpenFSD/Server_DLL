#include "Framework_Server.h"
#include <cstddef>

namespace Server_Library
{

	Framework_Server::Framework_Server()
	{
		
	}

	Framework_Server::~Framework_Server()
	{

	}

	void Framework_Server::Create_Server()
	{
		ptr_HostServer = new class Server_Library::Server();
		while (ptr_HostServer == NULL) { /* wait untill created */ }
		ptr_HostServer->Get_Execute()->Initialise();
		ptr_HostServer->Get_Execute()->Initialise_Threads();
	}

	Framework_Server Get_HostServer()
	{
		return ptr_HostServer;
	}

	bool Get_Ack_InputAction_Capture()
	{
		Server_Library::Framework_Server::
		return 
	}
	float Framework_Server::Get_PraiseEventId()
	{
		Server_Library::Input inputSet = (Server_Library::Input)Server_Library::Framework_Server::Get_Server()->Get_Data()->GetBuffer_InputFrontDouble();
		return inputSet.GetPraiseEventId();
	}
	float Framework_Server::Get_Praise0_pitch()
	{
		Server_Library::Praise0_Output outputSubset = Server_Library::Framework_Server::Get_Server()->Get_Data()->GetBuffer_OututFrontDouble()->Get_OutputBuffer_Subset();
		return outputSubset.GetPitch();
	}

	float Framework_Server::Get_Praise0_yaw()
	{
		Server_Library::Praise0_Output outputSubset = Server_Library::Framework_Server::Get_Server()->Get_Data()->GetBuffer_OututFrontDouble()->Get_OutputBuffer_Subset();
		return outputSubset.GetYaw();
	}

	void Framework_Server::Set_PraiseEventId(__int16 value)
	{
		Server_Library::Input inputSet = (Server_Library::Input)Server_Library::Framework_Server::Get_Server()->Get_Data()->GetBuffer_InputFrontDouble();
		inputSet.SetPraiseEventId(value);
	}

	void Framework_Server::Set_Praise0_mousePos_X(__int16 value)
	{
		Server_Library::Praise0_Input inputSubset = (Server_Library::Praise0_Input)Server_Library::Framework_Server::Get_Server()->Get_Data()->GetBuffer_InputFrontDouble()->Get_InputBufferSubset();
		inputSubset.Set_mouse_X(value);
	}

	void Framework_Server::Set_Praise0_mousePos_Y(__int16 value)
	{
		Server_Library::Praise0_Input inputSubset = (Server_Library::Praise0_Input)Server_Library::Framework_Server::Get_Server()->Get_Data()->GetBuffer_InputFrontDouble()->Get_InputBufferSubset();
		inputSubset.Set_mouse_Y(value);
	}

}