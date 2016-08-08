#include "insertion_sort.h"

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