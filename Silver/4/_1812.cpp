#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int* candies = new int[N];
	bool isFound = false;
	for (int i = 0; i < N; i++)
	{
		cin >> candies[i];
	}
	while (true)
	{
		int i = 0;
		for (i = 0; i <= candies[0]; i++)
		{
			int nextCandies = candies[0] - i;
			for (int j = 1; j < N - 1; j++)
			{
				nextCandies = candies[j] - nextCandies;
			}
			if (nextCandies + i == candies[N - 1])
			{
				isFound = true;
				break;
			}
		}
		if (isFound == true)
		{
			cout << i << "\n";
			int nextCandies = candies[0] - i;
			for (int i = 1; i < N; i++)
			{
				cout << nextCandies<<"\n";
				nextCandies = candies[i] - nextCandies;
			}
			break;
		}
	}
	return 0;
}