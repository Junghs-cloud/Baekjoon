#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	map<int, int> m;
	map<int, int>::iterator it;
	vector<int> maxCountV;
	double sum = 0;
	int maxCount = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		it = m.find(arr[i]);
		if (it == m.end())
		{
			m.insert({ arr[i], 1 });
		}
		else
		{
			it->second++;
		}
	}
	for (it = m.begin(); it != m.end(); it++)
	{
		if (it->second > maxCount)
		{
			maxCountV.clear();
			maxCountV.push_back(it->first);
			maxCount = it->second;
		}
		else if (it->second == maxCount)
		{
			maxCountV.push_back(it->first);
		}
	}
	sort(maxCountV.begin(), maxCountV.end());
	sort(arr, arr + N);
	int average = round(sum / (double)N);
	int median = arr[N / 2];
	int mode = 0;
	int range = arr[N - 1] - arr[0];
	if (maxCountV.size() == 1)
	{
		mode = maxCountV.at(0);
	}
	else
	{
		mode = maxCountV.at(1);
	}

	cout << average << "\n";
	cout << median << "\n";
	cout << mode << "\n";
	cout << range << "\n";
	return 0;
}