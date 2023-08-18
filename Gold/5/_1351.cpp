#include <iostream>
#include <map>
using namespace std;
long long P, Q;
map<long long, long long> m;
map<long long, long long>::iterator it;

long long get(long long num)
{
	if (num == 0)
	{
		return 1;
	}
	else
	{
		it = m.find(num / P);
		if (it != m.end())
		{
			long long a = it->second;
			it = m.find(num / Q);
			if (it != m.end())
			{
				long long b = it->second;
				return a + b;
			}
			else
			{
				long long b = get(num / Q);
				m.insert({ num / Q, b});
				return a + b;
			}
		}
		else
		{
			long long a = get(num / P);
			m.insert({ num / P, a });

			it = m.find(num / Q);
			if (it != m.end())
			{
				long long b = it->second;
				return a + b;
			}
			else
			{
				long long b = get(num / Q);
				m.insert({ num / Q, b });
				return a + b;
			}
		}

	}
}

int main()
{
	long long N;
	cin >> N>>P>>Q;
	if (N == 0)
	{
		cout << "1" << "\n";
	}
	else
	{
		cout << get(N) << "\n";
	}
	return 0;
}