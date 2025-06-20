#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int A, B, num;
	cin >> A >> B;
	vector<int> v;
	for (int i = 0; i < A; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < B; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
	return 0;
}