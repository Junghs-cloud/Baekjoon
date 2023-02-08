#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int* numSet = new int[10];
	for (int i = 0; i < 10; i++)
	{
		numSet[i] = 0;
	}
	for (int i = 0; i < (signed) str.length(); i++)
	{
		int num = str[i] - 48;
		numSet[num]++;
	}
	int sum = numSet[6] + numSet[9];
	if (sum % 2 == 0)
	{
		numSet[6] = sum / 2;
		numSet[9] = sum / 2;
	}
	else
	{
		numSet[6] = sum / 2 + 1;
		numSet[9] = sum / 2 + 1;
	}
	int max = numSet[0];
	for (int i = 1; i < 10; i++)
	{
		if (numSet[i] > max)
		{
			max = numSet[i];
		}
	}
	cout << max<<"\n";
	return 0;
}