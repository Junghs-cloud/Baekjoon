#include <iostream>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	stack<int> s;
	cin >> N;
	int* arr = new int[N];
	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i =0; i < N; i++)
	{
		while (!s.empty())
		{
			if (arr[i] >= s.top())
			{
				s.pop();
			}
			else
			{
				break;
			}
		}
		answer += s.size();
		s.push(arr[i]);
	}
	cout << answer << "\n";
	return 0;
}