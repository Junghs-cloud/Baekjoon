#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, j;
	int applePos;
	cin >> N >> M;
	cin >> j;
	int left = 1;
	int right = M;
	int count = 0;
	for (int i = 0; i < j; i++)
	{
		cin >> applePos;
		if (applePos >= left && applePos <= right)
		{
			continue;
		}
		else if (applePos < left)
		{
			count += left - applePos;
			left = applePos;
			right = left + M - 1;
		}
		else
		{
			count += applePos - right;
			right = applePos;
			left = right - M + 1;
		}
	}
	cout << count << "\n";
	return 0;
}