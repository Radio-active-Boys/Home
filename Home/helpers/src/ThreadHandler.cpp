#include "ThreadHandler.h"




template<typename FuncType>
static std::thread ThreadHandler<FuncType>::createThreadForNewWindow(FuncType func,std::string threadName)
{
	std::thread thread(func);
	ThreadHandler::activeThreads++;
	allThreads.emplace(threadName, std::move(thread));
	thread.detach();

	return thread;
}

template<typename FuncType>
static inline void ThreadHandler<FuncType>::destroyThread(std::string threadName)
{
	try {
		std::thread &thread = allThreads[threadName];
		allThreads.erase(threadName);
		activeThreads--;
		thread.join();
	}
	catch (std::exception& e) {
		std::cout <<"Couldn't join the thread "<<threadName<<" "<< e.what() << std::endl;
		return;
	}
	
	return;
}

template<typename FuncType>
static inline std::map<std::string, std::thread> ThreadHandler<FuncType>::getAllThreads()
{
	return allThreads;
}
