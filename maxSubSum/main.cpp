#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

extern int maxSubSum1(const std::vector<int>& a);
extern int maxSubSum2(const std::vector<int>& a);
extern int maxSubSum3(const std::vector<int>& a);
extern int maxSubSum4(const std::vector<int>& a);

int main(void)
{
	std::vector<int> a;

	srand(time(0));

	for (int i = 0; i < 1000000; ++i)
	{
		a.push_back((rand() % 1000000000) * (rand() % 2 ? -1 : 1));
	}
	
	DWORD dwStart = GetTickCount();
	std::cout << "Max sub sum algorithm1 is " << maxSubSum1(a) << std::endl;
	std::cout << "Algorithml1: " << GetTickCount() - dwStart << std::endl;
	dwStart = GetTickCount();
	std::cout << "Max sub sum algorithm2 is " << maxSubSum2(a) << std::endl;
	std::cout << "Algorithml2: " << GetTickCount() - dwStart << std::endl;
	dwStart = GetTickCount();
	std::cout << "Max sub sum algorithm3 is " << maxSubSum3(a) << std::endl;
	std::cout << "Algorithml3: " << GetTickCount() - dwStart << std::endl;
	dwStart = GetTickCount();
	std::cout << "Max sub sum algorithm4 is " << maxSubSum4(a) << std::endl;
	std::cout << "Algorithml4: " << GetTickCount() - dwStart << std::endl;

	system("pause");

	return 0;
}
