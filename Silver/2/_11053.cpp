#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int maxLength = 0;
	cin >> N;
	int* arr = new int[N];
	int* length = new int[N];
	for (int i = 0; i < N; i++)
	{
		length[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	length[0] = 1;
	for (int i = 1; i < N; i++)
	{
		int prevMaxLength = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				if (length[j] > prevMaxLength)
				{
					prevMaxLength = length[j];
				}
			}
		}
		length[i] = prevMaxLength + 1;
	}

	for (int i = 0; i < N; i++)
	{
		if (length[i] > maxLength)
		{
			maxLength = length[i];
		}
	}
	cout << maxLength << "\n";
	return 0;
}