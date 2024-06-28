#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	pair<int, vector<int>> maxValues;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	maxValues.first = arr[0];
	maxValues.second.push_back(0);
	for (int i = 1; i < N; i++)
	{
		if (arr[i] > maxValues.first)
		{
			maxValues.second.clear();
			maxValues.first = arr[i];
			maxValues.second.push_back(i);
		}
		else if (arr[i] == maxValues.first)
		{
			maxValues.second.push_back(i);
		}
	}
	if (maxValues.second.size() == 1)
	{
		if (N % 2 == 0)
		{
			if (maxValues.second[0] + 1 <= N / 2)
			{
				cout << "R";
			}
			else
			{
				cout << "B";
			}
		}
		else
		{
			if (maxValues.second[0] +1 == N / 2 + 1)
			{
				cout << "X";
			}
			else if (maxValues.second[0] + 1 < N / 2 + 1)
			{
				cout << "R";
			}
			else
			{
				cout << "B";
			}
		}
	}
	else
	{
		int leftCount = maxValues.second.front();
		int rightCount = N - 1 - maxValues.second.back();
		if (leftCount == rightCount)
		{
			cout << "X";
		}
		else if (leftCount < rightCount)
		{
			cout << "R";
		}
		else
		{
			cout << "B";
		}
	}
	return 0;
}