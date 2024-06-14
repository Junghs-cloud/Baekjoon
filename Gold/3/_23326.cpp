#include <iostream>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, Q;
	int tf, query, num;
	int currentPos = 0;
	set<int> landmarks;
	set<int>::iterator it;
	cin >> N >> Q;
	for (int i = 0; i < N; i++)
	{
		cin >> tf;
		if (tf == 1)
		{
			landmarks.insert(i);
		}
	}
	for (int i = 0; i < Q; i++)
	{
		cin >> query;
		if (query == 1)
		{
			cin >> num;
			it = landmarks.find(num - 1);
			if (it == landmarks.end())
			{
				landmarks.insert(num - 1);
			}
			else
			{
				landmarks.erase(it);
			}
		}
		else if (query == 2)
		{
			cin >> num;
			currentPos = ((currentPos + num) % N);
		}
		else
		{
			if (landmarks.size() == 0)
			{
				cout << -1 << "\n";
			}
			else
			{
				it = landmarks.lower_bound(currentPos);
				if (it == landmarks.end())
				{
					int moveCountToBegin = N - currentPos;
					cout << *landmarks.begin() + moveCountToBegin << "\n";
				}
				else
				{
					cout << *it - currentPos << "\n";
				}
			}
		}
	}
	return 0;
}