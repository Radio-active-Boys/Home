#pragma once


#include <thread>
#include <map>
#include <string>
#include <iostream>

template <typename FuncType>
class ThreadHandler {

public:
	static std::thread createThreadForNewWindow(FuncType func, std::string threadName);
	static inline void destroyThread(std::string threadName);
	static inline std::map<std::string, std::thread> getAllThreads();

private:
	static inline std::map<std::string, std::thread> allThreads{};
	static inline int activeThreads{};


};







 