#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
long long answer = 0;
long long total = 0;
vector<long long>::iterator it;
vector<long long>::iterator iter;
vector<long long> v;

void binarySearch(long long left, long long right)
{
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long sum = 0;
		it = lower_bound(v.begin(), v.end(), mid);
		for (iter = v.begin(); iter != it; iter++)
		{
			sum += *iter;
		}
		for (iter; iter != v.end(); iter++)
		{
			sum += mid;
		}
		if (sum >= ceil(total / 2.0f))
		{
			answer = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	long long num = 0;
	cin >> N;
	for (int i = 0; i < N * N; i++)
	{
		cin >> num;
		if (num != 0)
		{
			v.push_back(num);
			total += num;
		}
	}
	sort(v.begin(), v.end());
	if (total == 0)
	{
		cout << 0 << "\n";
	}
	else
	{
		binarySearch(1, 10000001);
		cout << answer << "\n";
	}

	return 0;
}