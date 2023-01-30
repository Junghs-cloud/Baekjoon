#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, x;
	priority_queue<int> queue;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x != 0)
		{
			queue.push(x);
		}
		else
		{
			if (queue.empty() == true)
			{
				cout << "0" << "\n";
			}
			else
			{
				cout << queue.top() << "\n";
				queue.pop();
			}

		}
	}
	return 0;
}