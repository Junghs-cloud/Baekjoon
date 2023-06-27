#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, a, present;
	priority_queue<int> pq;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		if (a == 0)
		{
			if (pq.empty()==true)
			{
				cout << "-1"<<"\n";
			}
			else
			{
				cout<<pq.top()<<"\n";
				pq.pop();
			}
		}
		else
		{
			for (int j = 0; j < a; j++)
			{
				cin >> present;
				pq.push(present);
			}
		}
	}
	return 0;
}