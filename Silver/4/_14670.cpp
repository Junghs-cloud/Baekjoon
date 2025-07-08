#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, R, L, S;
	int M, count;
	map<int, int> m;
	map<int, int>::iterator it;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> M >> count;
		m.insert({ M, count });
	}
	cin >> R;
	for (int i = 0; i < R;i++)
	{
		cin >> L;
		bool canSolve = true;
		vector<int> v;
		for (int j = 0; j < L; j++)
		{
			cin >> S;
			it = m.find(S);
			if (it == m.end())
			{
				canSolve = false;
			}
			else
			{
				v.push_back(it->second);
			}
		}
		if (canSolve == true)
		{
			for (int j = 0; j < v.size(); j++)
			{
				cout << v.at(j) << " ";
			}
		}
		else
		{
			cout << "YOU DIED";
		}
		cout << "\n";
		v.clear();
	}
	return 0;
}