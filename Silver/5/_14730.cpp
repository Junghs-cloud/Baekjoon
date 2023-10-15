#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int C, K;
	cin >> N;
	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> C >> K;
		answer += C * K;
	}
	cout << answer << "\n";
	return 0;
}