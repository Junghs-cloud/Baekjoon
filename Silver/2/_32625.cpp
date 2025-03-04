#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	set<int> div;
	set<int>::iterator it;
	bool canDivide = false;
	div.insert(1);
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (N % i == 0)
		{
			div.insert(i);
			div.insert(N / i);
		}
	}
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (it = div.begin(); it != div.end() && canDivide == false; it++)
	{
		int count = *it;
		int pos = 0;
		int sum = -1;
		bool check = true;
		while (pos < N)
		{
			int minValue = 100001;
			int maxValue = 0;
			for (int i = pos; i < pos + count; i++)
			{
				minValue = min(minValue, arr[i]);
				maxValue = max(maxValue, arr[i]);
			}
			if (sum == -1)
			{
				sum = minValue + maxValue;
			}
			else if (sum != minValue + maxValue)
			{
				check = false;
				break;
			}
			pos += count;
		}
		if (check == true)
		{
			canDivide = true;
		}
	}
	if (canDivide == true)
	{
		cout << 1 << "\n";
	}
	else
	{
		cout << 0 << "\n";
	}
	return 0;
}