#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	bool* isPrime = new bool[N + 1];
	for (int i = 0; i < N+1; i++)
	{
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i < N + 1; i++)
	{
		for (int j = 2 * i; j < N + 1; j += i)
		{
			isPrime[j] = false;
		}
	}
	for (int i = 0; i < N + 1; i++)
	{
		if (isPrime[i] == true)
		{
			int num= i;
			bool canMake = true;
			vector<int> v;
			while (true)
			{
				string str = to_string(num);
				int sum = 0;
				for (int j = 0; j < str.length(); j++)
				{
					sum += ((str[j]-48) * (str[j]-48));
				}
				num = sum;
				if (num == 1)
				{
					break;
				}
				if (find(v.begin(), v.end(), num) == v.end())
				{
					v.push_back(num);
				}
				else
				{
					canMake = false;
					break;
				}
			}
			if (canMake == true)
			{
				cout << i << "\n";
			}
		}
	}
	return 0;
}