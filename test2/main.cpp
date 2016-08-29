#include <iostream>
#include <algorithm>
#include <windows.h>

int main(void)
{
	DWORD dwStart = GetTickCount();
	for (int i = 123; i < 330; ++i)
	{
		int a[3] = { i / 100, (i % 100) / 10, (i % 10) };
		if (a[0] == a[1] || a[0] == a[2] || a[1] == a[2])
		{
			continue;
		}

		int j = i * 2;
		int b[3] = { j / 100, (j % 100) / 10, (j % 10) };
		if (b[0] == b[1] || b[0] == b[2] || b[1] == b[2] || b[0] == 0 || b[1] == 0 || b[2] == 0)
		{
			continue;
		}
		if (std::find(a, a + 3, b[0]) != a + 3
			|| std::find(a, a + 3, b[1]) != a + 3
			|| std::find(a, a + 3, b[2]) != a + 3)
		{
			continue;
		}

		int k = i * 3;
		int c[3] = { k / 100, (k % 100) / 10, (k % 10) };
		if (c[0] == c[1] || c[0] == c[2] || c[1] == c[2] || c[0] == 0 || c[1] == 0 || c[2] == 0)
		{
			continue;
		}
		if (std::find(a, a + 3, c[0]) == a + 3
			&& std::find(a, a + 3, c[1]) == a + 3
			&& std::find(a, a + 3, c[2]) == a + 3
			&& std::find(b, b + 3, c[0]) == b + 3
			&& std::find(b, b + 3, c[1]) == b + 3
			&& std::find(b, b + 3, c[2]) == b + 3)
		{
			std::cout << a[0] << a[1] << a[2] << ":" 
				<< b[0] << b[1] << b[2] << ":" 
				<< c[0] << c[1] << c[2] << " = 1:2:3" << std::endl;
		}
	}
	std::cout << "Time: " << GetTickCount() - dwStart << std::endl;

	system("pause");

	return 0;
}
