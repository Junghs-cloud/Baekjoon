#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, num;
	int currentPushNum = 1;
	cin >> N;
	queue<int> q;
	queue<char> orders;
	stack<int> s;
	bool canMake = true;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		q.push(num);
	}
	while (!q.empty())
	{
		int currentMakeNum = q.front();
		if (currentPushNum == currentMakeNum)
		{
			orders.push('+');
			orders.push('-');
			currentPushNum++;
			q.pop();
		}
		else if (currentPushNum < currentMakeNum)
		{
			orders.push('+');
			s.push(currentPushNum);
			currentPushNum++;
		}
		else
		{
			int currentTop = s.top();
			if (currentTop == currentMakeNum)
			{
				orders.push('-');
				s.pop();
				q.pop();
			}
			else
			{
				canMake = false;
				break;
			}
		}
		
	}
	if (canMake == true)
	{
		while (!orders.empty())
		{
			cout << orders.front() << "\n";
			orders.pop();
		}
	}
	else
	{
		cout << "NO" << "\n";
	}
	return 0;
}