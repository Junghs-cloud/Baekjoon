#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* counts = new int[N + 1];
	int* prev = new int[N + 1];
	int current = N;
	counts[0] = 0;
	counts[1] = 0;
	prev[1] = 0;
	for (int i = 2; i < N + 1; i++)
	{
		counts[i] = counts[i - 1] + 1;
		prev[i] = i - 1;
		if (i % 3 == 0 && i % 2 == 0)
		{
			counts[i] = min({ counts[i / 3]+1, counts[i / 2]+1, counts[i] });
			if (min({ counts[i / 3] + 1, counts[i / 2] + 1, counts[i] }) == counts[i / 3] + 1)
			{
				prev[i] = i / 3;
			}
			else if (min({ counts[i / 3] + 1, counts[i / 2] + 1, counts[i] }) == counts[i / 2] + 1)
			{
				prev[i] = i / 2;
			}
		}
		else if (i % 3 == 0)
		{
			counts[i] = min(counts[i / 3] + 1, counts[i]);
			if (min(counts[i / 3] + 1 , counts[i]) == counts[i / 3] + 1)
			{
				prev[i] = i / 3;
			}
		}
		else if (i % 2 == 0)
		{
			counts[i] = min(counts[i / 2]+ 1 , counts[i]);
			if ( min(counts[i / 2] + 1, counts[i]) == counts[i / 2]+1 )
			{
				prev[i] = i / 2;
			}
		}
	}
	cout << counts[N] << "\n";
	while (current != 0)
	{
		cout << current << " ";
		current = prev[current];
	}
	return 0;
}