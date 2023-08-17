#include "ThreadHandler.h"




std::unique_ptr<std::thread> ThreadHandler::createThreadForNewWindow(int(func)(), std::string threadName) {
	auto newThread = std::make_unique<std::thread>(func);
	allThreads[threadName] = std::move(newThread);
	activeThreads++;
	return allThreads[threadName];
}

inline void ThreadHandler::destroyThread(std::string threadName)
{
	try {
		 std::thread thread = allThreads[threadName];
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

inline std::map<std::string, std::unique_ptr<std::thread>> ThreadHandler::getAllThreads()
{
	return allThreads;
}

