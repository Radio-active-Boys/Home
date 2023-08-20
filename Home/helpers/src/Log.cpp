#pragma once
#include "Log.h"



#define LOG			//Controlls the logging 

#ifdef LOG
	bool Log::log(const char* msg...)
	{
		std::cout << msg;
		return true;
	}
#else
	bool Log::log(const char* msg)		//passes without doing anything
	{	
		return false;
	}
#endif