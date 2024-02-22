#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string str;
	cin >> N;
	vector<long long> v;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		reverse(str.begin(), str.end());
		long long num = 0;
		for (int i = 0; i < str.length(); i++)
		{
			num = num * 10+(str.at(i) - 48);
		}
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++)
	{
		cout << v.at(i) << "\n";
	}
	return 0;
}