#include <iostream>
#include <stack>
#include <queue>
using namespace std;
deque<int> back;
stack<int> front;

void clear()
{
	while (!front.empty())
	{
		front.pop();
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, Q, pageNum;
	char job;
	int current = 0;
	cin >> N >> Q;
	for (int i = 0; i < Q; i++)
	{
		cin >> job;
		if (job == 'B')
		{
			if (!back.empty())
			{
				front.push(current);
				current = back.back();
				back.pop_back();
			}
		}
		else if (job == 'F')
		{
			if (!front.empty())
			{
				back.push_back(current);
				current = front.top();
				front.pop();
			}
		}
		else if (job == 'C')
		{
			if (!back.empty())
			{
				int size = back.size();
				int top = back.back();
				for (int i = 0; i < size; i++)
				{
					if (i == 0)
					{
						back.pop_back();
						back.push_front(top);
					}
					else
					{
						int current = back.back();
						if (top == current)
						{
							back.pop_back();
						}
						else
						{
							top = current;
							back.pop_back();
							back.push_front(top);
						}
					}
				}
			}
		}
		else
		{
			cin >> pageNum;
			clear();
			if (current != 0)
			{
				back.push_back(current);
			}
			current = pageNum;
		}
	}
	cout << current << "\n";
	if (back.empty())
	{
		cout << "-1" << "\n";
	}
	else
	{
		while (!back.empty())
		{
			cout << back.back();
			if (back.size() == 1)
			{
				cout << "\n";
			}
			else
			{
				cout << " ";
			}
			back.pop_back();
		}
	}
	if (front.empty())
	{
		cout << "-1" << "\n";
	}
	else
	{
		while (!front.empty())
		{
			cout << front.top();
			if (front.size() == 1)
			{
				cout << "\n";
			}
			else
			{
				cout << " ";
			}
			front.pop();
		}
	}
	return 0;
}