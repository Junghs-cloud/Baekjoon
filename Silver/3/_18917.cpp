#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long sum = 0;
	long long xOR = 0;
	int num;
	int M, x;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		if (num == 1)
		{
			cin >> x;
			sum += x;
			xOR = xOR ^ x;
		}
		else if (num == 2)
		{
			cin >> x;
			sum -= x;
			xOR = xOR ^ x;
		}
		else if (num == 3)
		{
			cout << sum << "\n";
		}
		else
		{

			cout << xOR << "\n";
		}
	}
	return 0;
}