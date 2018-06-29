#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <list>
#include <queue>
#include "Job.h"
#include <set>

class Job_System
{
public:
	Job_System();
	~Job_System();

	void AddThreads(int value);					//We add in threads based on the input
	void StopThread();

	void AddJob(Job* job);						//Adds user functions into the array		
	bool CheckJob(Job* check);					//Checks the jobs status


protected:
	static void ExecuteJobs(Job_System* system);		//Checks if the job is completed

	//Variables
	std::queue<Job*>		  m_jobs;					//Creates an array of job pointers
	std::set<Job*>		      m_finishedJobs;			//Creates an array of finished job pointers
	std::vector<std::thread>  m_threads;				//Creates an array of threads
	std::mutex				  m_mutex;					//Creates a mutex

	bool m_isRunning;
	bool m_isComplete;
};