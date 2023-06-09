#pragma once
#include <string>
#include <vector>

class SomeClass
{
public:
	SomeClass();
	~SomeClass();
	const char* callScript();
private:

	std::string para_string = "Hello World";
};

