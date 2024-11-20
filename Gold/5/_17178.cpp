#include <iostream>
#include <queue>
#include <string>
#include <stack>
using namespace std;

struct cmp
{
	bool operator()(pair<char, int>& p1, pair<char, int>& p2)
	{
		if (p1.first < p2.first)
		{
			return false;
		}
		else if (p1.first == p2.first)
		{
			return p1.second > p2.second;
		}
		else
		{
			return true;
		}
	}
};

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string str;
	cin >> N;
	queue<pair<char, int>> originalLine;
	priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> orders;
	stack<pair<char, int>> waitingLine;
	bool isPossible = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> str;
			char alphabet = str.at(0);
			int num = stoi(str.substr(2));
			originalLine.push(pair(alphabet, num));
			orders.push(pair(alphabet, num));
		}
	}
	while (true)
	{
		if (originalLine.empty())
		{
			while (!waitingLine.empty())
			{
				if (waitingLine.top() == orders.top())
				{
					waitingLine.pop();
					orders.pop();
				}
				else
				{
					isPossible = false;
					break;
				}
			}
			break;
		}
		if (orders.top() == originalLine.front())
		{
			originalLine.pop();
			orders.pop();
		}
		else
		{
			pair<char, int> currentFront = originalLine.front();
			originalLine.pop();
			while (!waitingLine.empty())
			{
				if (waitingLine.top() == orders.top())
				{
					waitingLine.pop();
					orders.pop();
				}
				else
				{
					break;
				}
			}
			if (orders.top() == currentFront)
			{
				orders.pop();
			}
			else
			{
				waitingLine.push(currentFront);
			}
		}
	}
	if (isPossible == true)
	{
		cout << "GOOD" << "\n";
	}
	else
	{
		cout << "BAD" << "\n";
	}
	return 0;
}