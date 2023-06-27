#include <iostream>
#include <queue>
using namespace std;

struct cmp
{
	bool operator()(int x, int y)
	{
		if (x < y)
		{
			return false;
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
	int N, x;
	cin >> N;
	priority_queue<int, vector<int>, cmp> q;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x == 0)
		{
			if (q.empty())
			{
				cout << "0" << "\n";
			}
			else
			{
				cout<<q.top()<<"\n";
				q.pop();
			}
		}
		else
		{
			q.push(x);
		}
	}
	return 0;
}