#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int query;
	int x, w;
	map<long long, long long> m;
	map<long long, long long>::iterator it;
	for (int i = 0; i < N; i++)
	{
		cin >> query;
		if (query == 1)
		{
			cin >> x >> w;
			m.insert({ w, x });
		}
		else
		{
			cin >> w;
			it = m.find(w);
			cout << it->second << "\n";
		}
	}
	return 0;
}