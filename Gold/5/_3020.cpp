#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, H, height;
	cin >> N >> H;
	vector<int> ceiling;
	vector<int> bottom;
	long long answer = 100000000001;
	long long count = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> height;
		if (i % 2 == 0)
		{
			bottom.push_back(height);
		}
		else
		{
			ceiling.push_back(H - height);
		}
	}
	sort(bottom.begin(), bottom.end());
	sort(ceiling.begin(), ceiling.end());
	for (int i = 1; i <= H; i++)
	{
		long long bottomIndex = lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin();
		long long ceilingIndex = lower_bound(ceiling.begin(), ceiling.end(), i) - ceiling.begin();
		long long currentBreak = bottom.size() - bottomIndex + ceilingIndex;
		if (currentBreak < answer)
		{
			answer = currentBreak;
			count = 1;
		}
		else if (currentBreak == answer)
		{
			count++;
		}
	}
	cout << answer << " " << count << "\n";
	return 0;
}