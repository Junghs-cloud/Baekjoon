#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct comp
{
	bool operator()(int a, int b)
	{
		if (abs(a) > abs(b))
		{
			return true;
		}
		else if (abs(a) == abs(b))
		{
			return a > b;
		}
		else
		{
			return false;
		}
	}
};


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	priority_queue<int, vector<int>, comp> PQ;
	int N, x;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x == 0)
		{
			if (PQ.size() == 0)
			{
				cout << "0" << "\n";
			}
			else
			{
				cout << PQ.top() << "\n";
				PQ.pop();
			}
		}
		else
		{
			PQ.push(x);
		}
	}

	return 0;
}