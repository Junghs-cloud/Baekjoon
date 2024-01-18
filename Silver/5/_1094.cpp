#include <iostream>
using namespace std;

int main()
{
	int x;
	int answer = 0;
	cin >> x;
	while (x != 0)
	{
		if ((x & 1) == 1)
		{
			answer++;
		}
		x = x >> 1;
	}
	cout << answer << "\n";
	return 0;
}