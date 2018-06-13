#include <iostream>
#include "Job_System.h"

void func1()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << std::endl;
	}
}

int main()
{

	Job_System jobSystem;

	jobSystem.Execute(func1);

	system("pause");
	return 0;
}