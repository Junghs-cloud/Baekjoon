#include <iostream>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int x, y;
	cin >> N;
	int* arr = new int[N];
	stack<int> s;
	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		arr[i] = y;
	}
	for (int i = 0; i < N; i++)
	{
		while (!s.empty())
		{
			if (arr[i] > s.top())
			{
				s.push(arr[i]);
				break;
			}
			else if (arr[i] == s.top())
			{
				break;
			}
			else
			{
				s.pop();
				answer++;
			}
		}
		if (s.empty())
		{
			s.push(arr[i]);
		}
	}
	while (!s.empty())
	{
		if (0 == s.top())
		{
			break;
		}
		else
		{
			s.pop();
			answer++;
		}
	}
	cout << answer << "\n";
	return 0;
}