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
	int* tower = new int[N];
	int* arr = new int[N];
	stack<pair<int, int>> save;
	for (int i = 0; i < N; i++)
	{
		cin >> tower[i];
		arr[i] = 0;
	}
	save.push(make_pair(tower[N - 1], N-1));
	for (int i = N - 2; i >= 0; i--)
	{
		if (tower[i] >= save.top().first)
		{
			while (!save.empty())
			{
				if (tower[i] >= save.top().first)
				{
					arr[save.top().second] = i + 1;
					save.pop();
				}
				else
				{
					break;
				}
			}
			save.push(make_pair(tower[i], i));
		}
		else
		{
			save.push(make_pair(tower[i], i));
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
	return 0;
}