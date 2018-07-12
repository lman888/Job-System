#pragma once

//Pure virtual class in which its children will derive off of
class Job
{
public:

	virtual void Execute() = 0;
};

