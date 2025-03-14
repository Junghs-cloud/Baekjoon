#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long N;
	cin >> N;
	long long answer = 0;
	long long pow = 1;
	while (N != 0)
	{
		if (N % 2 == 1)
		{
			answer += pow;
		}
		pow *= 3;
		N /= 2;
	}
	cout << answer << "\n";
	return 0;
}