#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <list>
#include <queue>
#include "Job.h"

class Job_System
{
public:
	Job_System();
	~Job_System();

	void AddThreads(int value);
	void StopThread();

	//bool JobCompleted(Job& completedJob);			//Checks if the job is complete

	void AddJob(Job* job);						//Adds user functions into the array		
	void CheckJob(Job& check);

protected:
	static void ExecuteJobs(Job_System* system);					//Checks if the job is completed

	//Variables
	std::queue<Job*>		  m_jobs;
	std::vector<std::thread>  m_threads;
	std::mutex				  m_mutex;

	//std::list<Job*>			  m_completedJobs;
	//std::mutex				  m_completedjobM;

	bool m_isRunning;
	bool m_isComplete;
};