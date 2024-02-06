#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	vector<int> dp;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	dp.push_back(arr[0]);
	for (int i = 1; i < N; i++)
	{
		if (arr[i] > dp.at(dp.size()-1))
		{
			dp.push_back(arr[i]);
		}
		else
		{
			int index = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
			dp.at(index) = arr[i];
		}
	}
	cout << dp.size() << "\n";
	return 0;
}