#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	long long* sums = new long long[N+1];
	map<int, vector<int>> m;
	map<int, vector<int>>::iterator it;
	sums[0] = 0;
	long long maxSum = 0;
	long long maxSumCount = 0;
	for (int i = 1; i < N+1; i++)
	{
		cin >> arr[i-1];
		it = m.find(arr[i - 1]);
		if (it == m.end())
		{
			vector<int> v;
			v.push_back(i - 1);
			m.insert({ arr[i - 1], v });
		}
		else
		{
			it->second.push_back(i - 1);
		}
		sums[i] = sums[i - 1] + arr[i - 1];
	}
	for (map<int, vector<int>>::iterator it = m.begin(); it != m.end(); it++)
	{
		int firstIndex = it->second.front();
		int lastIndex = it->second.back();
		long long partSum = sums[lastIndex + 1] - sums[firstIndex];
		if (partSum > maxSum)
		{
			maxSum = partSum;
			maxSumCount = 1;
		}
		else if (partSum == maxSum)
		{
			maxSumCount++;
		}
	}
	cout << maxSum << " " << maxSumCount << "\n";
	return 0;
}