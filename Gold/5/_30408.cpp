#include <iostream>
#include <set>
using namespace std;

long long N, M;
bool canMake;
set<long long> s;
set<long long>::iterator it;

void divide(long long num)
{
	if (num == M)
	{
		canMake = true;
		return;
	}
	if (num == 1)
	{
		return;
	}
	else
	{
		it = s.find(num);
		if (it == s.end())
		{
			s.insert(num);
			if (num % 2 == 0)
			{
				divide(num / 2);
			}
			else
			{
				divide(num / 2);
				divide(num / 2 + 1);
			}
		}
	}
}

int main()
{
	canMake = false;
	cin >> N >> M;
	divide(N);
	if (canMake == true)
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO" << "\n";
	}
	return 0;
}