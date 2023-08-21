#pragma once


#include <thread>
#include <vector>
#include <string>
#include <iostream>


class ThreadHolder {
public:
	std::thread* thread;

	ThreadHolder(std::thread* th) {
		this->thread = th;
	};
};




template <typename FuncType>
class ThreadHandler {

public:
	static std::thread create_thread_for_new_window(FuncType func, std::string threadName);
	static void destroy_thread(int ind);
	static std::vector<ThreadHolder>  get_all_threads();
	static void join_all_threads();



private:
	static std::vector<ThreadHolder> m_all_threads;
	static int m_active_threads;

};










 