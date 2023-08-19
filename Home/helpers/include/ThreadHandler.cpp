#include "ThreadHandler.h"


template<typename FuncType>
std::vector<threadHolder> ThreadHandler<FuncType>::allThreads;


template<typename FuncType>
int ThreadHandler<FuncType>::activeThreads{};



template<typename FuncType>
std::thread ThreadHandler<FuncType>::createThreadForNewWindow(FuncType func,std::string threadName)
{
	std::thread thread(func);
	
	try {
		
		ThreadHandler::activeThreads++;
		allThreads.push_back(threadHolder(&thread));
		thread.detach();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	return thread;
}



template<typename FuncType>
void ThreadHandler<FuncType>::destroyThread(int ind)
{
	try {
		threadHolder thread = allThreads[ind];
		std::swap(allThreads[ind], allThreads.back());
		allThreads.pop_back();
		activeThreads--;
		thread.thread->join();
	}
	catch (std::exception& e) {
		std::cout <<"Couldn't join the thread "<<ind<<" "<< e.what() << std::endl;
		return;
	}
	
	return;
}

template<typename FuncType>
std::vector<threadHolder> ThreadHandler<FuncType>::getAllThreads()
{
	return allThreads;
}



template <typename FuncType>
void ThreadHandler<FuncType>::joinAllThreads() {
	try {
		for (auto& pair : allThreads) {
			try {
				pair.thread->join();
			}
			catch (std::exception& e) {
 				std::cout << e.what() << std::endl;
			}
			
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	allThreads.clear();
	activeThreads = 0;
}

