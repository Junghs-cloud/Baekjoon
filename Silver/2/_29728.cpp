#include <iostream>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	bool* isPrime = new bool[5000001];
	for (int i = 0; i < 5000001; i++)
	{
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i <= sqrt(5000000); i++)
	{
		for (int j = 2 * i; j < 5000001; j += i)
		{
			isPrime[j] = false;
		}
	}
	int N;
	deque<char> dq;
	bool isReverse = false;
	int B = 0;
	int S = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		if (isPrime[i] == false)
		{
			if (isReverse == false)
			{
				dq.push_back('B');
				B++;
			}
			else
			{
				dq.push_front('B');
				B++;
			}
		}
		else if (isPrime[i] == true && isReverse == false)
		{
			char last = dq.back();
			if (last == 'B')
			{
				dq.pop_back();
				B--;
				dq.push_back('S');
				S++;
				dq.push_back('S');
				S++;
			}
			else
			{
				dq.push_back('S');
				S++;
				isReverse = true;
			}
		}
		else
		{
			char first = dq.front();
			if (first == 'B')
			{
				dq.pop_front();
				B--;
				dq.push_front('S');
				S++;
				dq.push_front('S');
				S++;
			}
			else
			{
				dq.push_front('S');
				S++;
				isReverse = false;
			}
		}
	}
	cout << B << " " << S << "\n";
	return 0;
}