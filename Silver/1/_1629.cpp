#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long i = 1;
	long long A, B, C;
	long long answer = 1;
	cin >> A >> B >> C;
	long long powA = A % C;
	while (B != 0)
	{
		if ((B & 1)== 1)
		{
			answer *= powA % C;
			answer %= C;
		}
		B = (B >> 1);
		i *= 2;
		powA = powA * powA % C;
	}
	cout << answer << "\n";
	return 0;
}