#include <iostream>
using namespace std;

int main()
{
	long long x, y;
	long long answer = 0;
	cin >> x >> y;
	if (x > y)
	{
		answer += x;
		answer += y;
		answer += (y / 10);
	}
	else
	{
		answer += y;
		answer += x;
		answer += (x / 10);
	}
	cout << answer << "\n";
	return 0;
}