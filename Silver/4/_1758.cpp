#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	long long answer = 0;
	cin >> N;
	int* tips = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> tips[i];
	}
	sort(tips, tips + N, greater());
	for (int i = 0; i < N; i++)
	{
		answer += max(tips[i] - i, 0);
	}
	cout << answer << "\n";
	return 0;
}