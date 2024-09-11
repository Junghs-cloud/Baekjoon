#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int A, B;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		v.push_back(B - A);
	}
	sort(v.begin(), v.end());
	if (N % 2 == 0)
	{
		int mid = N / 2 - 1;
		cout << v.at(mid+1) - v.at(mid) + 1 << "\n";
	}
	else
	{
		cout << 1 << "\n";
	}
	return 0;
}