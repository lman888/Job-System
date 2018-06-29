#include "Job_System.h"




Job_System::Job_System()
{
}

Job_System::~Job_System()
{
}

void Job_System::AddThreads(int value)
{
	m_isRunning = true;
	for (int i = 0; i < value; i++)
	{
		m_threads.push_back(std::thread(ExecuteJobs, this));	//Creates  and sets the number of threads
	}
}

void Job_System::StopThread()
{
	m_isRunning = false;
	for (auto& thread : m_threads)	//Casts the array of threads into a thread
	{
		thread.join();	//Joins the thread into the main thread
	}
}

void Job_System::AddJob(Job* job)
{
	m_mutex.lock();
	m_jobs.push(job);	//Pushes the job pointer into the array of jobs
	m_mutex.unlock();
}

void Job_System::ExecuteJobs(Job_System* system)
{

	
	while (system->m_isRunning == true)
	{
		bool getLock = system->m_mutex.try_lock();	//attempts to lock the mutex
		if (getLock)								//If the thread is able to lock the mutex
		{
			Job* jobToComplete = nullptr;				//Sets the jobToComplete pointer to null to ensure it isnt reused
			if (!system->m_jobs.empty())			
			{
				//system->m_mutex.lock();
				jobToComplete = system->m_jobs.front();	//Grabs the job from the front of the queue and pushes it into the pointer variable
				system->m_jobs.pop(); //Removes the empty spot in the front of the array	
				
			}
			system->m_mutex.unlock();
			if (jobToComplete)
			{
				jobToComplete->Execute();

				system->m_finishedJobs.insert(jobToComplete);	//Push the completed job into the array of completed jobs

				system->m_isComplete = true;
			}
		}
	}

}

bool Job_System::CheckJob(Job* check)
{
	auto it = m_finishedJobs.find(check);	//Attempts to find the completed job in the Set list and pushes the job into the variable it
	if (it != m_finishedJobs.end())
	{
		//Found!
		m_finishedJobs.erase(it);			//Removes the completed job from the array
		return true;						
	}
	else
	{
		return false;
	}

}