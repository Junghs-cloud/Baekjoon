#include <iostream>
#include <deque>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int button;
	char c;
	cin >> N;
	deque<char> d;
	stack<char> frontBack;
	for (int i = 0; i < N; i++)
	{
		cin >> button;
		if (button == 1)
		{
			cin >> c;
			d.push_back(c);
			frontBack.push('b');
		}
		else if (button == 2)
		{
			cin >> c;
			d.push_front(c);
			frontBack.push('f');
		}
		else
		{
			if (d.empty())
			{
				continue;
			}
			else
			{
				if (frontBack.top() == 'f')
				{
					d.pop_front();
				}
				else
				{
					d.pop_back();
				}
				frontBack.pop();
			}
			
		}
	}
	if (d.empty())
	{
		cout << "0" << "\n";
	}
	else
	{
		while (!d.empty())
		{
			cout << d.front();
			d.pop_front();
		}
		cout << "\n";
	}
	return 0;
}