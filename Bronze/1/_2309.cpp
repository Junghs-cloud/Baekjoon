#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int* arr = new int[9];
	bool* isTrue = new bool[9];
	bool foundAnswer = false;
	int totalSum = 0;
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		totalSum += arr[i];
		isTrue[i] = true;
	}
	sort(arr, arr + 9);
	for (int i = 0; (i < 9 && foundAnswer==false ) ; i++)
	{
		for (int j = 0; j < i; j++)
		{
			sum = arr[i] + arr[j];
			if (totalSum - sum == 100)
			{
				isTrue[i] = false;
				isTrue[j] = false;
				foundAnswer = true;
				break;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (isTrue[i] == true)
		{
			cout << arr[i] << "\n";
		}
	}
	return 0;
}