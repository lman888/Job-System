#include <iostream>
#include "Job_System.h"
#include "Job.h"
#include <chrono>	//Allows the use of time intervals
using namespace std::chrono_literals;	//Allows the use of string after the number

class TestJob : public Job
{
public:
	std::string m_fileName;	//Used to control job executing
	char* m_data;			//Holds the processed results

	void Execute() override
	{
		//Test
		std::cout << "Starting File " << m_fileName.c_str() << '\n';
		std::this_thread::sleep_for(2s);
		m_data = new char[1024];
		std::cout << "FILE SIZE";
	}
};

int main()
{

	Job_System jobSystem;

	jobSystem.AddThreads(4);

	while (true)
	{
		for (int i = 0; i < 10; i++)
		{
			TestJob* job = new TestJob();
			job->m_fileName = "FileToLoad.txt";
			jobSystem.AddJob(job);
			job->Execute();
		}
	}

	std::this_thread::sleep_for(5s);	//puts the main thread to sleep for 5 seconds

	jobSystem.StopThread();

	system("pause");
	return 0;
}