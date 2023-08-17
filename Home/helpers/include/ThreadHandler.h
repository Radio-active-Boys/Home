#pragma once


#include <thread>
#include <map>
#include <string>
#include <iostream>
#include <memory>


class ThreadHandler {

public:
	static std::unique_ptr<std::thread> createThreadForNewWindow(int(func)(), std::string);
	static inline void destroyThread(std::string threadName);
	static inline std::map<std::string, std::unique_ptr<std::thread>> getAllThreads();

private:
	static inline std::map<std::string, std::unique_ptr<std::thread>> allThreads{};
	static inline int activeThreads{};

};







 