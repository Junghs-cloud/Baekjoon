#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long N, X;
	cin >> N >> X;
	if (X < N || X > 26 * N)
	{
		cout << "!" << "\n";
	}
	else
	{
		string str = "";
		long long leftLetter = N - 1;
		long long leftMoney = X;
		for (int i = 0; i < N; i++)
		{
			long long maxMoneyOfLeft = leftLetter * 26;
			if (leftMoney - maxMoneyOfLeft > 0)
			{
				int index = leftMoney - maxMoneyOfLeft - 1;
				str += 'A' + index;
				leftMoney -= leftMoney - maxMoneyOfLeft;
			}
			else
			{
				str += 'A';
				leftMoney--;
			}
			leftLetter--;
		}
		cout << str << "\n";
	}
	return 0;
}