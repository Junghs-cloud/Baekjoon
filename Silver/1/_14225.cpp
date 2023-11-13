#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int N;
int sum;
set<int> s;
bool* isVisited;
int* arr;

void backTracking(int length, int depth, int index)
{
	if (depth == length)
	{
		s.insert(sum);
		return;
	}
	else
	{
		for (int i = index; i < N; i++)
		{
			if (isVisited[i] == false)
			{
				isVisited[i] = true;
				sum += arr[i];
				backTracking(length, depth + 1, i+1);
				isVisited[i] = false;
				sum -= arr[i];
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	set<int>::iterator it;
	cin >> N;
	arr = new int[N];
	isVisited = new bool[N];
	sum = 0;
	for (int i = 0; i < N; i++)
	{
		isVisited[i] = false;
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 1; i <= N; i++)
	{
		backTracking(i, 0, 0);
	}
	for (int i = 1; i <= 2000000; i++)
	{
		it = s.find(i);
		if (it == s.end())
		{
			cout << i << "\n";
			break;
		}
	}
	return 0;
}