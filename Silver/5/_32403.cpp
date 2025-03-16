#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, T;
	int A;
	cin >> N >> T;
	set<int> s;
	set<int>::iterator it;
	int answer = 0;
	for (int i = 1; i <= sqrt(T); i++)
	{
		if (T % i == 0)
		{
			s.insert(i);
			s.insert(T/i);
		}
	}
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		if (T % A != 0)
		{
			int minValue = 123456789;
			for (it = s.begin(); it != s.end(); it++)
			{
				minValue = min(minValue, abs(*it - A));
			}
			answer += minValue;
		}
	}
	cout << answer << "\n";
	return 0;
}