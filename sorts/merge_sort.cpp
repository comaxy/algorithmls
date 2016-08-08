#include "merge_sort.h"
#include <climits>

int *left = nullptr;
int *right = nullptr;

void merge(int* a, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;

	for (int i = 0; i < n1; ++i)
	{
		left[i] = a[p + i];
	}
	for (int j = 0; j < n2; ++j)
	{
		right[j] = a[q + 1 + j];
	}
	left[n1] = INT_MAX;
	right[n2] = INT_MAX;
	int i = 0;
	int j = 0;
	for (int k = p; k <= r; ++k)
	{
		if (left[i] <= right[j])
		{
			a[k] = left[i];
			++i;
		}
		else 
		{
			a[k] = right[j];
			++j;
		}
	}
}

void merge_sort_impl(int* a, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		merge_sort_impl(a, p, q);
		merge_sort_impl(a, q + 1, r);
		merge(a, p, q, r);
	}
}

void merge_sort(int* a, int len)
{
	// 第一个加1为了len为奇数时保证数组长度够长
	// 第二个加1为了给哨兵预留位置
	left = new int[len / 2 + 1 + 1]();
	right = new int [len / 2 + 1 + 1]();

	merge_sort_impl(a, 0, len - 1);

	delete [] left;
	delete [] right;
}
