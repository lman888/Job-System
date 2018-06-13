#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class Job_System
{
public:
	Job_System();
	~Job_System();

	void Execute(void(*FuncPtr)());


	std::thread myThread;			//Thread Creation
	std::mutex myMutex;				//Mutex Creation
	std::condition_variable cv;		//Condition Variable Creation
};

