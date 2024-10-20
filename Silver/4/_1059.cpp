#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int L, num, N;
	vector<int> v;
	long long answer = 0;
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	cin >> N;
	if (find(v.begin(), v.end(), N) != v.end())
	{
		cout << 0 << "\n";
	}
	else
	{
		int min, max;
		int maxIndex = lower_bound(v.begin(), v.end(), N) - v.begin() ;
		int minIndex = maxIndex - 1;
		if (minIndex == -1)
		{
			min = 1;
		}
		else
		{
			min = v.at(minIndex) + 1;
		}
		max = v.at(maxIndex) - 1;
		for (int i = min; i <= max; i++)
		{
			answer += v.at(maxIndex) - i - (N - i);
			if (i == N)
			{
				answer--;
				break;
			}
		}
		cout << answer << "\n";
	}
	return 0;
}