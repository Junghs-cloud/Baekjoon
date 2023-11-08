#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	bool* isPrime = new bool[1050000];
	int endOfI = sqrt(1050000);
	vector<int> v;
	for (int i = 0; i < 1050000; i++)
	{
		isPrime[i] = true;
	}
	isPrime[1] = false;
	for (int i = 2; i <= endOfI; i++)
	{
		for (int j = 2 * i; j < 1050000; j += i)
		{
			isPrime[j] = false;
		}
	}
	for (int i = 2; i < 1050000; i++)
	{
		bool pelindrome = true;
		if (isPrime[i] == true)
		{
			string numStr = to_string(i);
			for (int j = 0; j < numStr.length() / 2; j++)
			{
				if (numStr[j] != numStr[numStr.length() - 1 - j])
				{
					pelindrome = false;
				}
			}
			if (pelindrome == true)
			{
				v.push_back(i);
			}
		}
	}
	cin >> N;
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i) >= N)
		{
			cout << v.at(i)<<"\n";
			break;
		}
	}
	return 0;
}