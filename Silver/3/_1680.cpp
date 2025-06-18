#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int W, N, x, w;
		cin >> W >> N;
		int currentWeight = 0;
		int distance = 0;
		int prevPos = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> x >> w;
			if (currentWeight + w > W)
			{
				distance += 3 * x - prevPos;
				currentWeight = w;
			}
			else if (currentWeight + w == W)
			{
				distance += 3 * x - prevPos;
				currentWeight = 0;
			}
			else
			{
				distance += (x - prevPos);
				currentWeight += w;
			}
			prevPos = x;
		}
		if (currentWeight != 0)
		{
			distance += prevPos;
		}
		else
		{
			distance -= prevPos;
		}
		cout << distance << "\n";
	}
	return 0;
}