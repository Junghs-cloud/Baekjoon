#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int G;
	cin >> G;
	int prev = 1;
	int current = 1;
	bool canFound = false;
	while ((prev+1) * (prev+1) - prev*prev <= G)
	{
		if (current * current - prev * prev < G)
		{
			current++;
		}
		else if (current * current - prev * prev == G)
		{
			cout << current << "\n";
			current++;
			canFound = true;
		}
		else
		{
			prev++;
		}
	}
	if (canFound == false)
	{
		cout << -1 << "\n";
	}
	return 0;
}