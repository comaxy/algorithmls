#include "auxiliary.h"
#include <iostream>

void print_array(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

void stuff_array(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		a[i] = rand();
	}
}