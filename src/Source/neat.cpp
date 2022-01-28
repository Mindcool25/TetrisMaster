#include <Python.h>
#include ""../Headers/neat.hpp""
#include <stdio.h>
#include <pyhelper.hpp>

void neat::startPython
{
	CPyInstance hInstance;

	CPyObject pName = PyUnicode_FromString("neat");
	CPyObject pModule = PyImport_Import(pName);

	if(pModule)
	{
		CPyObject pFunc = PyObject_GetAttrString(pModule, "getInteger");
		if(pFunc && PyCallable_Check(pFunc))
		{
			CPyObject pValue = PyObject_CallObject(pFunc, NULL);

			printf_s("C: getInteger() = %ld\n", PyLong_AsLong(pValue));
		}
		else
		{
			printf("ERROR: function getInteger()\n");
		}

	}
	else
	{
		printf_s("ERROR: Module not imported\n");
	}

	return 0;
}
