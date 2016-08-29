/*
 * 编写一个程序，找出一个数的全部的连续整数固定和。
 * 所谓一个数n的连续整数固定和，就是指存在a(1),a(2),...,a(n)，
 * 其中a(j+1)比a(j)大1，使得a(1)+a(2)+...+a(n)=n。
 * 例如27的全部的连续整数固定和有3组：
 * 2+3+...+7=27; 8+9+10=27;13+14=27;
 */

#include <windows.h>
#include <cstdio>
#include <iostream>

void cntnsIntSum(int n)
{
	int i, sum = 0, j;
	int top = (n >> 1) + 1;
	for (i = 3; i < top; ++i)
	{
		j = i - 1;
		while (sum < n) sum += ++j;
		if (sum == n) printf("%d+...+%d = %d\n", i, j, n);
		sum = 0;
	}
}

int main()
{
	int n = {0};
	while (std::cin >> n)
	{
		DWORD dwStart = GetTickCount();
		cntnsIntSum(n);
		printf("%ums\n", GetTickCount() - dwStart);
	}

	system("pause");

	return 0;
}
