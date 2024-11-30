#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N;
	long long answer = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int counts = N / i;
		answer += (long long) i * counts;
	}
	cout << answer << "\n";
	return 0;
}