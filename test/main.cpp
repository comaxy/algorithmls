/*
 * ��дһ�������ҳ�һ������ȫ�������������̶��͡�
 * ��νһ����n�����������̶��ͣ�����ָ����a(1),a(2),...,a(n)��
 * ����a(j+1)��a(j)��1��ʹ��a(1)+a(2)+...+a(n)=n��
 * ����27��ȫ�������������̶�����3�飺
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
