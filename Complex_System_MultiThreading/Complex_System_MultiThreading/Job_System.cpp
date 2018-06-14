#include "Job_System.h"



Job_System::Job_System()
{
}


Job_System::~Job_System()
{
}

void Job_System::Execute()
{

	auto jobFunction = addFuncs;

	//Creation of a Lambda Function
	myThread = std::thread([&]()		//Takes in the entire class
	{
		myMutex.lock();						//Locks the mutex so no other data can acess it

		addFuncs.begin();

		std::cout << "Thread is in the Lambda" << std::endl;

		myMutex.unlock();					//Unlocks the mutex so other data may enter to be processed
	});

	//myThread2 = std::thread([&]()
	//{
	//	myMutex2.lock();

	//	jobFunction;

	//	myMutex2.unlock();
	//});

	myThread.join();						//Joins the thread back into the Main thread
	//myThread2.join();

	jobFunction.pop_back();
}

void Job_System::AddFunction(void(*FuncPtr)())
{
	addFuncs.push_back(FuncPtr);
}
