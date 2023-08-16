#include "pch.h"
#include "Log.h"
#include <iostream>


#define _LOG_			//Controlls the logging 

#ifdef _LOG_
	bool Log::log(const char* msg)
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