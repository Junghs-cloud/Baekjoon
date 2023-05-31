#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	priority_queue<int> pq;
	int N, M;
	int present,want;
	bool disappointed = false;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> present;
		pq.push(present);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> want;
		int biggest = pq.top();
		if (want > biggest)
		{
			disappointed = true;
			break;
		}
		else if (want== biggest)
		{
			pq.pop();
		}
		else
		{
			pq.pop();
			pq.push(biggest - want);
		}
	}
	if (disappointed == true)
	{
		cout << "0\n";
	}
	else
	{
		cout << "1\n";
	}
	return 0;
}