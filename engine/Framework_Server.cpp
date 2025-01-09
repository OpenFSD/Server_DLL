#include "Framework_Server.h"
#include <cstddef>

namespace Server_Library
{
	class Server* Framework_Server::ptr_HostServer;

	Framework_Server::Framework_Server()
	{
		
	}

	Framework_Server::~Framework_Server()
	{

	}

	void Framework_Server::CreateHostingServer()
	{
		ptr_HostServer = new class Server_Library::Server();
		while (ptr_HostServer == NULL) { /* wait untill created */ }
		ptr_HostServer->Get_Execute()->Initialise();
		ptr_HostServer->Get_Execute()->Initialise_Threads();
	}

	void Framework_Server::PopFromStackOfOutput(
		class Output* distributeBuffer,
		std::vector<class Output*>* ptr_outputStack
	)
	{

	}

	void Framework_Server::PushToStackOfInputPraises(
		std::vector<class Server_Library::Input*>* ptr_InputStack,
		class Server_Library::Input* ptr_Buffer_Praise)
	{
		Server_Library::Framework_Server::Get_HostServer().Get_Data()->Get_Data_Control()->PushToStackOfInputPraises(
			std::vector<class Server_Library::Input*>*ptr_InputStack,
			class Server_Library::Input * ptr_Buffer_Praise
		)
	}

	bool Framework_Server::Get_Ack_InputAction_Capture()
	{
		return Server_Library::ListenRespond_Control::GetFlag_Acknowledge_Input_Capture();
	}
	

	class Server_Library::Server Framework_Server::Get_HostServer()
	{
		return ptr_HostServer;
	}

	int Get_NumberOfCores()
	{
		return Server_Library::Framework_Server::Get_HostServer()->Get_Global()->Get_NumCores()
	}
	
	bool GetState_Buffer_Input_ToWrite()
	{

	}

	bool Framework_Server::Get_WriteEnable_Stack_InputPraise()
	{
		return Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_InputPraise();
	}

	bool Framework_Server::Get_WriteEnable_Stack_OutputPraise()
	{
		return Server_Library::Framework_Server::Get_HostServer()->Get_Execute()->Get_WriteEnable_Stack_OutputPraise();
	}

	void Framework_Server::Set_Ack_InputAction_Capture(bool value)
	{
		Server_Library::Framework_Server::Get_HostServer()->Get_Algorithms()->Get_ListenRespond()->Get_ListenRespond_Control()->SetFlag_Acknowledge_Input_Capture(true);
	}


	float Framework_Server::Get_PraiseEventId()
	{
		Server_Library::Input inputSet = (Server_Library::Input)Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputFrontDouble();
		return inputSet.GetPraiseEventId();
	}
	float Framework_Server::Get_Praise0_pitch()
	{
		Server_Library::Praise0_Output outputSubset = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_OututFrontDouble()->Get_OutputBuffer_Subset();
		return outputSubset.GetPitch();
	}

	float Framework_Server::Get_Praise0_yaw()
	{
		Server_Library::Praise0_Output outputSubset = Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_OututFrontDouble()->Get_OutputBuffer_Subset();
		return outputSubset.GetYaw();
	}


	void Framework_Server::Set_PraiseEventId(__int16 value)
	{
		Server_Library::Input inputSet = (Server_Library::Input)Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputFrontDouble();
		inputSet.SetPraiseEventId(value);
	}

	void Framework_Server::Set_Praise0_mousePos_X(__int16 value)
	{
		Server_Library::Praise0_Input inputSubset = (Server_Library::Praise0_Input)Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputFrontDouble()->Get_InputBufferSubset();
		inputSubset.Set_mouse_X(value);
	}

	void Framework_Server::Set_Praise0_mousePos_Y(__int16 value)
	{
		Server_Library::Praise0_Input inputSubset = (Server_Library::Praise0_Input)Server_Library::Framework_Server::Get_HostServer()->Get_Data()->GetBuffer_InputFrontDouble()->Get_InputBufferSubset();
		inputSubset.Set_mouse_Y(value);
	}

}