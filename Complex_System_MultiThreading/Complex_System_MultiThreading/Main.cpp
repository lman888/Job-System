#include <iostream>
#include "Job_System.h"

void func1()
{
	std::cout << "Func1 has been entered" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		std::cout << i << std::endl;
	}

}

void func2()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "RA RA RASPUTIN: "<< i << std::endl;
	}
}

int main()
{

	Job_System jobSystem;

	jobSystem.AddFunction(func1);
	jobSystem.AddFunction(func2);

	jobSystem.Execute();

	system("pause");
	return 0;
}