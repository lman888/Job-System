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
	for (auto& thread : m_threads)
	{
		thread.join();	//Joins the thread into the main thread
	}
}

void Job_System::AddJob(Job* job)
{
	m_mutex.lock();
	m_jobs.push(job);
	m_mutex.unlock();
}

void Job_System::ExecuteJobs(Job_System* system)
{

	Job* jobToComplete = nullptr;
	while (system->m_isRunning == true)
	{
		bool getLock = system->m_mutex.try_lock();	//attempts to lock the mutex
		if (getLock)
		{
			if (!system->m_jobs.empty())
			{
				system->m_mutex.lock();
				jobToComplete = system->m_jobs.front();	//Grabs from the front of the jobs queue
				system->m_jobs.pop();
			}

			system->m_mutex.unlock();

			if (jobToComplete)
			{
				jobToComplete->Execute();
			}
			system->m_isComplete = true;
		}
	}

}

//bool Job_System::JobCompleted(Job& completedJob)
//{
//	while (m_isRunning == true)
//	{
//		m_completedjobM.lock();
//		if (m_isComplete == true)
//		{
//			m_completedJobs.begin();
//			break;
//		}
//		m_completedjobM.unlock();
//	}
//
//	return false;
//}

void Job_System::CheckJob(Job& check)
{

}

//void Job_System::Execute()
//{
//
//	//for (int i = 0; i < 4; i++)
//	//{
//	//	myThreads.push_back(std::thread(i));	//Pushes 4 Threads into the vector array
//	//}
//
//	while (!addFuncs.empty())
//	{
//
//		for (auto &thread : myThreads)
//		{
//			thread = std::thread([&]() 
//			{
//				myMutex.lock();
//
//				for (int i = 0; i < addFuncs.size(); i++)
//				{
//					((jobFunction)addFuncs[i]);
//				}
//
//				addFuncs.pop_back();
//
//				myMutex.unlock();
//			});
//
//			thread.join();				//Joins the array of completed threads onto the main thread
//		}
//	}
//}


////Creation of a Lambda Function
//myThread = std::thread([&]()			//Takes in the entire class
//{
//	myMutex.lock();						//Locks the mutex so no other data can acess it

//	for (int i = 0; i < addFuncs.size(); i++)
//	{
//		((jobFunction)addFuncs[i])();
//	}

//	std::cout << "Thread is in the Lambda" << std::endl;

//	addFuncs.pop_back();

//	myMutex.unlock();					//Unlocks the mutex so other data may enter to be processed
//});

//myThread2 = std::thread([&]()
//{
//	myMutex2.lock();

//	for (int i = 0; i < addFuncs.size(); i++)
//	{
//		((jobFunction)addFuncs[i])();
//	}

//	addFuncs.pop_back();

//	myMutex2.unlock();
//});

//myThread.join();						//Joins the thread back into the Main thread
//myThread2.join();