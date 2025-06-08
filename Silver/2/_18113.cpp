#include <iostream>
#include <vector>
using namespace std;
long long N, K, M;
vector<long long> v;
long long answer;

void binarySearch(long long left, long long right)
{
	long long start = left;
	long long end = right;
	while (start <= end)
	{
		long long mid = (start + end) / 2;
		long long kimbapCount = 0;
		for (int i = 0; i < v.size(); i++)
		{
			kimbapCount += v.at(i) / mid;
		}
		if (kimbapCount >= M)
		{
			answer = max(answer, mid);
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
}

int main()
{
	long long L;
	cin >> N >> K >> M;
	long long totalLength = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> L;
		if (L >= 2 * K)
		{
			v.push_back(L - 2 * K);
			totalLength += L - 2 * K;
		}
		else if (L > K)
		{
			v.push_back(L - K);
			totalLength += L - K;
		}
	}
	if (totalLength < M)
	{
		cout << -1 << "\n";
	}
	else
	{
		binarySearch(1, 1000000000);
		cout << answer << "\n";
	}
	return 0;
}