#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

class Job_System
{
public:
	Job_System();
	~Job_System();

	void Execute();							//Executes the functions
	void AddFunction(void(*FuncPtr)());						//Adds user functions into the array		

protected:
	typedef void(*jobFunction)(void);

	std::thread myThread;									//Thread Creation
	std::thread myThread2;
	std::thread myThread3;		

	//Variables
	std::vector<void*>				addFuncs;				//Array of Voids
	//std::vector<std::thread>	    myThreads;				//Aray of Threads
	std::mutex						myMutex;				//Mutex Creation
	std::mutex						myMutex2;				//Mutex Creation
	std::condition_variable			cv;						//Condition Variable Creation
};