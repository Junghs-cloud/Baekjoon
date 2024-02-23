#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N;
	int num;
	int currentSnackNum = 1;
	cin >> N;
	queue<int> q;
	stack<int> s;
	bool canGet = true;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		q.push(num);
	}
	while (!q.empty())
	{
		int currentFront = q.front();
		if (currentFront == currentSnackNum)
		{
			currentSnackNum++;
			q.pop();
		}
		else
		{
			if (!s.empty())
			{
				int currentTop = s.top();
				if (currentTop == currentSnackNum)
				{
					currentSnackNum++;
					s.pop();
				}
				else
				{
					s.push(currentFront);
					q.pop();
				}
			}
			else
			{
				s.push(currentFront);
				q.pop();
			}
		}
	}
	while (!s.empty())
	{
		int currentTop = s.top();
		if (currentTop == currentSnackNum)
		{
			currentSnackNum++;
			s.pop();
		}
		else
		{
			canGet = false;
			break;
		}
	}
	if (canGet == true)
	{
		cout << "Nice" << "\n";
	}
	else
	{
		cout << "Sad" << "\n";
	}
	return 0;
}