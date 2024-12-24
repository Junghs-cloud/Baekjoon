#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c;
	while (true)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}
		int longgest = max({ a, b, c });
		if (longgest >= a + b + c - longgest)
		{
			cout << "Invalid" << "\n";
		}
		else if (a == b && a== c)
		{
			cout << "Equilateral" << "\n";
		}
		else if (a == b || a == c || b == c)
		{
			cout << "Isosceles" << "\n";
		}
		else
		{
			cout << "Scalene" << "\n";
		}
	}
	return 0;
}