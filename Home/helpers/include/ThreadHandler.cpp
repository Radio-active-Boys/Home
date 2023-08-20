#include "ThreadHandler.h"


template<typename FuncType>
std::vector<ThreadHolder> ThreadHandler<FuncType>::m_all_threads;


template<typename FuncType>
int ThreadHandler<FuncType>::m_active_threads{};



template<typename FuncType>
std::thread ThreadHandler<FuncType>::create_thread_for_new_window(FuncType func,std::string threadName)
{
	std::thread thread(func);
	
	try {
		
		ThreadHandler::m_active_threads++;
		m_all_threads.push_back(ThreadHolder(&thread));
		thread.detach();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	return thread;
}



template<typename FuncType>
void ThreadHandler<FuncType>::destroy_thread(int ind)
{
	try {
		ThreadHolder thread = m_all_threads[ind];
		std::swap(m_all_threads[ind], m_all_threads.back());
		m_all_threads.pop_back();
		m_active_threads--;
		thread.thread->join();
	}
	catch (std::exception& e) {
		std::cout <<"Couldn't join the thread "<<ind<<" "<< e.what() << std::endl;
		return;
	}
	
	return;
}

template<typename FuncType>
std::vector<ThreadHolder> ThreadHandler<FuncType>::get_all_threads()
{
	return m_all_threads;
}



template <typename FuncType>
void ThreadHandler<FuncType>::join_all_threads() {
	try {
		for (auto& pair : m_all_threads) {
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
	
	m_all_threads.clear();
	m_active_threads = 0;
}

