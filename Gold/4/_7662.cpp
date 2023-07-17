#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		priority_queue<int, vector<int>, less<int>> pq1;
		priority_queue<int, vector<int>, greater<int>> pq2;
		priority_queue<int, vector<int>, less<int>> erasedFromPq2;
		priority_queue<int, vector<int>, greater<int>> erasedFromPq1;
		int N;
		char command;
		int num;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> command >> num;
			if (command == 'I')
			{
				pq1.push(num);
				pq2.push(num);
			}
			else if (command == 'D' && num == 1)
			{
				if (!erasedFromPq2.empty())
				{
					while (!pq1.empty() && !erasedFromPq2.empty())
					{
						if (pq1.top() == erasedFromPq2.top())
						{
							erasedFromPq2.pop();
							pq1.pop();
						}
						else
						{
							break;
						}
					}
				}
				if (!pq1.empty())
				{
					erasedFromPq1.push(pq1.top());
					pq1.pop();
				}

			}
			else
			{
				if (!erasedFromPq1.empty())
				{
					while (!pq2.empty() && !erasedFromPq1.empty())
					{
						if (pq2.top() == erasedFromPq1.top())
						{
							erasedFromPq1.pop();
							pq2.pop();
						}
						else
						{
							break;
						}
					}
				}
				if (!pq2.empty())
				{
					erasedFromPq2.push(pq2.top());
					pq2.pop();
				}
			}
		}
		if (!erasedFromPq2.empty())
		{
			while (!pq1.empty() && !erasedFromPq2.empty())
			{
				if (pq1.top() == erasedFromPq2.top())
				{
					erasedFromPq2.pop();
					pq1.pop();
				}
				else
				{
					break;
				}
			}
		}
		if (!erasedFromPq1.empty())
		{
			while (!pq2.empty() && !erasedFromPq1.empty())
			{
				if (pq2.top() == erasedFromPq1.top())
				{
					erasedFromPq1.pop();
					pq2.pop();
				}
				else
				{
					break;
				}
			}
		}
		if (pq1.size() == 0 && pq2.size() == 0)
		{
			cout << "EMPTY" << "\n";
		}
		else
		{
			cout << pq1.top() << " " << pq2.top() << "\n";
		}
	}
	
	return 0;
}