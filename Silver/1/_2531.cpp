#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int N, d, k, c;
deque<int>* dq;

int checkSize()
{
	int size = 0;
	bool hasEventSushi = false;
	for (int i = 0; i < d + 1; i++)
	{
		if (i == c)
		{
			if (dq[i].size() != 0)
			{
				hasEventSushi = true;
				size++;
			}
		}
		else
		{
			if (dq[i].size() != 0)
			{
				size++;
			}
		}
	}
	if (hasEventSushi == true)
	{
		return size;
	}
	else
	{
		return size + 1;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> d >> k >> c;
	int* arr = new int[N+k];
	int maxSushi = 0;
	dq = new deque<int>[d + 1];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = N; i < N + k; i++)
	{
		arr[i] = arr[i - N];
	}
	for (int i = 0; i < k; i++)
	{
		dq[arr[i]].push_back(i);
		maxSushi = max(maxSushi, checkSize());
	}
	for (int i = k; i < N+k; i++)
	{
		dq[arr[i - k]].pop_front();
		dq[arr[i]].push_back(i);
		maxSushi = max(maxSushi, checkSize());
	}
	cout << maxSushi << "\n";
	return 0;
}