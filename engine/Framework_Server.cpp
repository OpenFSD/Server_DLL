#include "Framework_Server.h"
#include <cstddef>

namespace Server_Library
{
	class Server_Library::Server* Framework_Server::ptr_Server = NULL;

	Framework_Server::Framework_Server()
	{
		
	}

	Framework_Server::~Framework_Server()
	{

	}

	void Framework_Server::Create_Server()
	{
		ptr_Server = new class Server_Library::Server();
		while (ptr_Server == NULL) { /* wait untill created */ }
		ptr_Server->Get_Execute()->Initialise();
		ptr_Server->Get_Execute()->Initialise_Threads();
	}

	Server_Library::Server* Framework_Server::Get_Server()
	{
		return ptr_Server;
	}

	float Get_Praise0_pitch()
	{
		Server_Library::Praise0_Output outputSubset = Server_Library::Framework_Server::Get_Server()->Get_Data()->GetBuffer_OututFrontDouble()->Get_OutputBuffer_Subset();
		return outputSubset.GetPitch();
	}

	float Get_Praise0_yaw()
	{
		Server_Library::Praise0_Output outputSubset = Server_Library::Framework_Server::Get_Server()->Get_Data()->GetBuffer_OututFrontDouble()->Get_OutputBuffer_Subset();
		return outputSubset.GetYaw();
	}

	void Set_Praise0_mousePos_X(__int16 value)
	{
		Server_Library::Praise0_Input inputSubset = Server_Library::Framework_Server::Get_Server()->Get_Data()->GetBuffer_InputFrontDouble()->Get_InputBufferSubset();
		inputSubset.Set_mouse_X(value);
	}

	void Set_Praise0_mousePos_Y(__int16 value)
	{
		Server_Library::Praise0_Input inputSubset = Server_Library::Framework_Server::Get_Server()->Get_Data()->GetBuffer_InputFrontDouble()->Get_InputBufferSubset();
		inputSubset.Set_mouse_Y(value);
	}

}