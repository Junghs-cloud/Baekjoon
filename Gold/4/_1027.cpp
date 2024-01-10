#include <iostream>
#include <utility>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* visible = new int[N];
	long long* buildings = new long long[N];
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		visible[i] = 0;
		cin >> buildings[i];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			pair<long long, long long> ij = make_pair(buildings[i] - buildings[j], i - j);
			bool canSee = true;
			for (int k = j + 1; k < i; k++)
			{
				pair<long long, long long>ik = make_pair(buildings[i] - buildings[k], i - k);
				if (ij.first * ik.second - ij.second * ik.first >= 0)
				{
					canSee = false;
					break;
				}
			}
			if (canSee == true)
			{
				visible[i]++;
			}
		}
		for (int j = i + 1; j < N; j++)
		{
			pair<long long, long long> ij = make_pair(buildings[j] - buildings[i], j - i);
			bool canSee = true;
			for (int k = i+ 1; k < j; k++)
			{
				pair<long long, long long>jk = make_pair(buildings[k] - buildings[j], k - j);
				if (ij.first * jk.second - ij.second * jk.first <= 0)
				{
					canSee = false;
					break;
				}
			}
			if (canSee == true)
			{
				visible[i]++;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (visible[i] > answer)
		{
			answer = visible[i];
		}
	}
	cout << answer << "\n";
	return 0;
}