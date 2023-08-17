#pragma once


#include <thread>
#include <vector>
#include <string>
#include <iostream>


class threadHolder {
public:
	std::thread* thread;

	threadHolder(std::thread* th) {
		this->thread = th;
	};
};




template <typename FuncType>
class ThreadHandler {

public:
	static std::thread createThreadForNewWindow(FuncType func, std::string threadName);
	static void  destroyThread(int ind);
	static std::vector<threadHolder>  getAllThreads();
	static void joinAllThreads();



private:
	static std::vector<threadHolder> allThreads;
	static int activeThreads;

};










 