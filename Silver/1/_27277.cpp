#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	int* orders = new int[N];
	int index = 0;
	deque<int> dq;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		dq.push_back(arr[i]);
	}
	for (int i = N-1; i >=0 ; i--)
	{
		if (index % 2 == 0)
		{
			orders[i] = dq.back();
			dq.pop_back();
		}
		else
		{
			orders[i] = dq.front();
			dq.pop_front();
		}
		index++;
	}
	int answer = orders[0];
	for (int i = 1; i < N; i++)
	{
		answer += max(0, orders[i] - orders[i - 1]);
	}
	cout << answer << "\n";
	return 0;
}