#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* answer = new int[N];
	int* arr = new int[N];
	stack<pair<int, int>> s;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		answer[i] = -1;
	}
	for (int i = N - 1; i >= 0; i--)
	{
		while (!s.empty())
		{
			if (arr[i] != s.top().first)
			{
				answer[i] = s.top().second;
				break;
			}
			else
			{
				s.pop();
			}
		}
		s.push(pair(arr[i], i + 1));
	}
	for (int i = 0; i < N; i++)
	{
		cout << answer[i] << " ";
	}
	return 0;
}