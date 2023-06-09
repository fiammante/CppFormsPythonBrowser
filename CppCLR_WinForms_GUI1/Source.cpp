#include <iostream>
#include <vector>
#include <windows.h>
#include "Python.h"
#include "Header.h"
#include <stdio.h>  // defines FILENAME_MAX
#define BUFSIZE MAX_PATH


SomeClass::SomeClass()
{
	

}

SomeClass::~SomeClass()
{
	if (Py_IsInitialized())
	{
		Py_Finalize();
	}
}
std::wstring GetCurrentWorkingDir()
{
	TCHAR Buffer[BUFSIZE];
	DWORD dwRet;
	


	dwRet = GetCurrentDirectory(BUFSIZE, Buffer);
	std::wstring test(&Buffer[0]);
	return test;
}

const char * SomeClass::callScript()
{
	const char* returned = "";
	try {
		if (!Py_IsInitialized())
		{
			Py_Initialize();
		}
		PyObject* pModule = NULL;
		PyObject* pFunc = NULL;

		PyObject* args = NULL;
		std::string code = "";
		PyRun_SimpleString("import sys");
		PyRun_SimpleString("sys.argv = ['python.py']");
		PyRun_SimpleString("import os;sys.path.append(os.getcwd());print(sys.path)");

		pModule = PyImport_ImportModule("script");
		if (!pModule) {
			PyErr_Print(); 
			throw "The python script cannot be opened.";
		}

		pFunc = PyObject_GetAttrString(pModule, "run");
		if (!pFunc || !PyCallable_Check(pFunc)) {
			throw "The python function cannot be called.";
		}

		PyObject* returnValue = PyObject_CallObject(pFunc, 0);

		if (!returnValue)
		{
			throw("Python script return value does not exist.");
		}
		std::cout << "Before Python script returned " <<  std::endl;
		returned = PyUnicode_AsUTF8(returnValue);
		std::cout << "Python script returned " << returned << std::endl;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const char* c)
	{
		std::cout << "Exception: " << c << std::endl;
	}
	return returned;
}