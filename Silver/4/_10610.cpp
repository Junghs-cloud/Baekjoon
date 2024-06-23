#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	vector<int> v;
	long long sum = 0;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		int num = str[i] - 48;
		v.push_back(num);
		sum += num;
	}
	if (sum % 3 != 0)
	{
		cout << -1 << "\n";
	}
	else
	{
		sort(v.begin(), v.end(), greater<int>());
		if (v.back() == 0)
		{
			for (int i = 0; i < v.size(); i++)
			{
				cout << v[i];
			}
		}
		else
		{
			cout << -1 << "\n";
		}
	}
	return 0;
}