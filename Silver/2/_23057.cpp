#include <iostream>
#include <set>
using namespace std;
int N;
int* arr;
bool* isUsed;
set<int> s;

void find(int currentDepth, int maxDepth, int index, int currentSum)
{
	if (currentDepth == maxDepth)
	{
		s.insert(currentSum);
	}
	else
	{
		for (int i = index; i < N; i++)
		{
			if (isUsed[i] == false)
			{
				isUsed[i] = true;
				find(currentDepth + 1, maxDepth, i + 1, currentSum + arr[i]);
				isUsed[i] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	arr = new int[N];
	isUsed = new bool[N];
	int M = 0;
	for (int i = 0; i < N; i++)
	{
		isUsed[i] = false;
		cin >> arr[i];
		M += arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		find(i, N, 0, 0);
	}
	int count = s.size();
	cout << M - count << "\n";
	return 0;
}