#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	stack<int> s;
	cin >> N;
	int* buildings = new int[N];
	int* nearBuilding = new int[N];
	int* canSeeBuildingCount = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> buildings[i];
		nearBuilding[i] = 1000000;
		canSeeBuildingCount[i] = 0;
	}
	for (int i = N - 1; i >= 0; i--)
	{
		if (s.empty())
		{
			s.push(i);
		}
		else
		{
			while (!s.empty())
			{
				if (buildings[i] < buildings[s.top()])
				{
					nearBuilding[i] = s.top();
					canSeeBuildingCount[i] = s.size();
					break;
				}
				else
				{
					s.pop();
				}
			}
			s.push(i);
		}
	}
	while (!s.empty())
	{
		s.pop();
	}
	for (int i = 0; i < N; i++)
	{
		if (s.empty())
		{
			s.push(i);
		}
		else
		{
			while (!s.empty())
			{
				if (buildings[i] < buildings[s.top()])
				{
					if (abs(nearBuilding[i]- i ) >= abs(s.top() - i))
					{
						nearBuilding[i] = s.top();
					}
					canSeeBuildingCount[i] += s.size();
					break;
				}
				else
				{
					s.pop();
				}
			}
			s.push(i);
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << canSeeBuildingCount[i];
		if (canSeeBuildingCount[i] != 0)
		{
			cout << " " << nearBuilding[i] + 1;
		}	
		cout << "\n";
	}
	return 0;
}