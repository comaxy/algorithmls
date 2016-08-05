#include <iostream>
#include <Windows.h>
#include <ctime>

void insertion_sort(int* a, int len);
void print_array(int* a, int len);
void stuff_array(int* a, int len);

int main(int argc, char** argv)
{
	srand(static_cast<unsigned int>(time(0)));

	const int ARR_LEN = 500000;
	int* a = new int[ARR_LEN]();
	stuff_array(a, ARR_LEN);

	DWORD dwStartTick = GetTickCount();
	std::cout << "Insertion sort started." << std::endl;
	insertion_sort(a, ARR_LEN);
	DWORD dwEndTick = GetTickCount();
	std::cout << "Insertion sort ended in " << (dwEndTick - dwStartTick) / 1000.0 << " seconds." << std::endl;

	system("pause");
	return 0;
}

void insertion_sort(int* a, int len)
{
	for (int j = 1; j < len; ++j)
	{
		int key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] > key)
		{
			a[i + 1] = a[i];
			--i;
		}
		a[i + 1] = key;
	}
}

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
