#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	int nonChickenCount = 0;
	int chickenCount = 0;
	int min = 10000000;
	cin >> N;
	char* arr = new char[N];
	for (int i = 0; i < N;i++)
	{
		cin >> arr[i];
		if (arr[i] != 'C')
		{
			nonChickenCount++;
		}
		else
		{
			chickenCount++;
		}
	}
	if (chickenCount == 0)
	{
		min = 0;
	}
	for (int i = 1; i <= N; i++)
	{
		int n = i * nonChickenCount;
		if (n > chickenCount)
		{
			break;
		}
		int last = chickenCount - n;
		if (max(i, last) < min)
		{
			min = max(i, last);
		}
	}
	cout << min << "\n";
	return 0;
}