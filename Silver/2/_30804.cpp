#include <iostream>
#include <set>
using namespace std;
int* fruitCounts;

int getCount()
{
	int fruitCount = 0;
	for (int i = 0; i < 10; i++)
	{
		if (fruitCounts[i] != 0)
		{
			fruitCount++;
		}
	}
	return fruitCount;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	fruitCounts = new int[10];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < 10; i++)
	{
		fruitCounts[i] = 0;
	}
	int start = 0;
	int end = 0;
	int answer = 1;
	fruitCounts[arr[end]]++;
	while (start < N)
	{
		while (end<N)
		{
			end++;
			if (end >= N)
			{
				break;
			}
			fruitCounts[arr[end]]++;
			if (getCount() > 2)
			{
				fruitCounts[arr[end]]--;
				end--;
				answer = max(answer, end - start + 1);
				break;
			}
			else
			{
				answer = max(answer, end - start + 1);
			}
		}
		fruitCounts[arr[start]]--;
		start++;
	}
	cout << answer << "\n";
	return 0;
}