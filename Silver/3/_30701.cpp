#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long D, N;
	long long A, X;
	long long answer = 0;
	cin >> N >> D;
	priority_queue<long long, vector<long long>, greater<>> monster;
	priority_queue<long long, vector<long long>, greater<>> eqip;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> X;
		if (A == 1)
		{
			monster.push(X);
		}
		else
		{
			eqip.push(X);
		}
	}
	while (!monster.empty() || !eqip.empty())
	{
		if (!monster.empty())
		{
			long long top = monster.top();
			if (D <= top)
			{
				if (eqip.empty())
				{
					break;
				}
				else
				{
					D *= eqip.top();
					eqip.pop();
					answer++;
				}
			}
			else
			{
				D += top;
				monster.pop();
				answer++;
			}
		}
		else
		{
			answer += eqip.size();
			break;
		}
	}
	cout << answer << "\n";
	return 0;
}