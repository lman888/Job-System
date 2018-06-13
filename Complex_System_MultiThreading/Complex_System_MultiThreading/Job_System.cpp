#include "Job_System.h"



Job_System::Job_System()
{
}


Job_System::~Job_System()
{
}

void Job_System::Execute(void(*FuncPtr)())
{

	auto jobFunction = FuncPtr;

	//Creation of a Lambda Function
	myThread = std::thread([&]()			//Takes in the entire class
	{
		myMutex.lock();						//Locks the mutex so no other data can acess it

		jobFunction;

		std::cout << "Thread is in the Lambda" << std::endl;

		myMutex.unlock();					//Unlocks the mutex so other data may enter to be processed
	});

	myThread.join();						//Joins the thread back into the Main thread
}
