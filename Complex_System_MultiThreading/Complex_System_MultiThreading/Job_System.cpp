#include "Job_System.h"



Job_System::Job_System()
{
}


Job_System::~Job_System()
{
}

void Job_System::Execute()
{

	//Creation of a Lambda Function
	myThread = std::thread([&]()		//Takes in the entire class
	{
		myMutex.lock();						//Locks the mutex so no other data can acess it
	
		for (int i = 0; i < addFuncs.size(); i++)
		{
			((jobFunction)addFuncs[i])();
		}

		std::cout << "Thread is in the Lambda" << std::endl;

		addFuncs.pop_back();

		myMutex.unlock();					//Unlocks the mutex so other data may enter to be processed
	});

	myThread2 = std::thread([&]()
	{
		myMutex2.lock();

		for (int i = 0; i < addFuncs.size(); i++)
		{
			((jobFunction)addFuncs[i])();
		}

		addFuncs.pop_back();

		myMutex2.unlock();
	});

	myThread.join();						//Joins the thread back into the Main thread
	myThread2.join();
}

void Job_System::AddFunction(void(*FuncPtr)())
{
	addFuncs.push_back(FuncPtr);
}