#include <iostream>
#include "Job_System.h"
#include "Job.h"
#include <chrono>	//Allows the use of time intervals
#include <string>


using namespace std::chrono_literals;	//Allows the use of string after the number

//We create a class which derives off of the Job class
class TestJob : public Job
{
public:
	std::string m_fileName;	//Used to control job executing
	char* m_data;			//Holds the processed results

	void Execute() override
	{
		//Test
		std::cout << "Starting File " << m_fileName << '\n';	//
		std::this_thread::sleep_for(2s);	//We put the thread to sleep for 2 seconds
		m_data = new char[1024];
		std::cout << "FILE SIZE";
	}
};

int main()
{

	Job_System jobSystem;

	jobSystem.AddThreads(4);	//We create 4 threads 

	std::vector<TestJob*> demoJobs;

	for (int i = 0; i < 20; i++)
	{
		TestJob* job = new TestJob();		//We create a new TestJob pointer on the heap
		job->m_fileName = "FileToLoad.txt";	//Sets the file name
		jobSystem.AddJob(job);				//We add the job to the array
		
		demoJobs.push_back(job);
	}


	while (!demoJobs.empty())
	{
		auto& job = demoJobs.back();
		bool completed = jobSystem.CheckJob(job);
		if (completed)
		{
			std::cout << "Finished the job, awesome!\n";
			char* data = job->m_data; //Use the data for something

			delete data;
			delete job;
			demoJobs.pop_back();
		}
	}

	jobSystem.StopThread();				//We stop the thread

	system("pause");
	return 0;
}