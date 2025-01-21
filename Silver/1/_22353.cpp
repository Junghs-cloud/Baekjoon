#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	double a, d, k;
	cin >> a >> d >> k;
	double currentWin = d / 100;
	double currentDefeat = 1;
	double count = 1;
	double answer = (count * a) * currentDefeat * currentWin;
	while (currentWin != 1)
	{
		currentDefeat *= 1 - currentWin;
		currentWin += currentWin * k / 100;
		if (currentWin >= 1)
		{
			currentWin = 1;
		}
		count++;
		answer += (count * a) * currentDefeat * currentWin;
	}
	cout << fixed;
	cout.precision(7);
	cout << answer << "\n";
	return 0;
}