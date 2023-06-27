#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, L;
	int alchol;
	int hours=0;
	cin >> N >> L;
	int* sum = new int[N + 1];
	sum[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> alchol;
		sum[i] = sum[i - 1] + alchol;
	}
	for (int i = 1; i < L;i++)
	{
		int alcholSum = sum[i];
		if (alcholSum >= 129 && alcholSum <= 138)
		{
			hours++;
		}
	}
	for (int i = L; i <= N; i++)
	{
		int alcholSum = sum[i] - sum[i - L];
		if (alcholSum >= 129 && alcholSum <= 138)
		{
			hours++;
		}
	}
	cout << hours << "\n";
	return 0;
}