#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, x;
	cin >> N;
	vector<int> v;
	vector<int> datas;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		datas.push_back(x);
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < N; i++)
	{
		int index = lower_bound(v.begin(), v.end(), datas.at(i)) - v.begin();
		cout << index << " ";
	}

	return 0;
}