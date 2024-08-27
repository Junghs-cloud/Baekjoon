#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long sum = 1;
	long long K = 1;
	long long step = 1;
	long long N;
	cin >> N;
	while (true)
	{
		if (N <= sum)
		{
			cout << step << "\n";
			break;
		}
		else
		{
			K = 6 * step;
			sum += K;
			step++;
		}
	}
	return 0;
}