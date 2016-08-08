#include <Windows.h>
#include <ctime>
#include <iostream>
#include "insertion_sort.h"
#include "merge_sort.h"
#include "auxiliary.h"

void test_insertion_sort()
{
	const int ARR_LEN = 1000000;
	int* a = new int[ARR_LEN]();
	stuff_array(a, ARR_LEN);

	DWORD dwStartTick = GetTickCount();
	std::cout << "Insertion sort started." << std::endl;
	insertion_sort(a, ARR_LEN);
	DWORD dwEndTick = GetTickCount();
	std::cout << "Insertion sort ended in " << (dwEndTick - dwStartTick) / 1000.0 << " seconds." << std::endl;
}

void test_merge_sort()
{
	const int ARR_LEN = 100000000;
	int* a = new int[ARR_LEN]();
	stuff_array(a, ARR_LEN);

	DWORD dwStartTick = GetTickCount();
	std::cout << "Merge sort started." << std::endl;
	merge_sort(a, ARR_LEN);
	DWORD dwEndTick = GetTickCount();
	std::cout << "Merge sort ended in " << (dwEndTick - dwStartTick) / 1000.0 << " seconds." << std::endl;
}

int main(int argc, char** argv)
{
	srand(static_cast<unsigned int>(time(0)));

	test_merge_sort();

	system("pause");
	return 0;
}
