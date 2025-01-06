#include "Execute_Control.h"
#include <cstddef>

namespace Server_Library
{
	bool Execute_Control::flag_SystemInitialised = NULL;
	bool Execute_Control::flag_ThreadInitialised[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CORES

	Execute_Control::Execute_Control(unsigned char* ptr_MyNumImplementedCores)
	{
		flag_SystemInitialised = bool(true);
		bool flag_ThreadInitialised[4] = { bool(true), bool(true), bool(true), bool(true) };//NUMBER OF CORES
		for (unsigned char index = 0; index < *ptr_MyNumImplementedCores; index++) {
			flag_ThreadInitialised[index] = new bool(true);
		}
	}
	
	Execute_Control::~Execute_Control()
	{

	}

	bool Execute_Control::GetFlag_SystemInitialised(unsigned char* ptr_MyNumImplementedCores)
	{
		for (int index = 0; index < *ptr_MyNumImplementedCores; index++)
		{
			flag_SystemInitialised = false;
			if (flag_ThreadInitialised[index] == true)
			{
				flag_SystemInitialised = true;
			}
		}
		return flag_SystemInitialised;
	}

	bool Execute_Control::GetFlag_ThreadInitialised(unsigned char coreId)
	{
		return flag_ThreadInitialised[coreId];
	}

	void Execute_Control::SetConditionCodeOfThisThreadedCore(unsigned char coreId)
	{
		//Todo
		SetFlag_ThreadInitialised(coreId);
	}

	void Execute_Control::SetFlag_ThreadInitialised(unsigned char coreId)
	{
		flag_ThreadInitialised[coreId] = false;
	}
}