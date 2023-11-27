#include <iostream>
#include <utility>
using namespace std;

int maxEgg;
int N;
pair<int, int>* arr;
bool* isBroken;
int currentEgg;

void backTracking(int depth)
{
	if (depth == N)
	{
		if (currentEgg > maxEgg)
		{
			maxEgg = currentEgg;
		}
		return;
	}
	else
	{
		if (isBroken[depth] == false)
		{
			bool b = false;
			for (int i = 0; i < N; i++)
			{
				if (depth == i)
				{
					continue;
				}
				if (isBroken[i] == false)
				{
					arr[depth].first -= arr[i].second;
					arr[i].first -= arr[depth].second;
					if (arr[i].first <= 0)
					{
						isBroken[i] = true;
						currentEgg++;
					}
					if (arr[depth].first <= 0)
					{
						isBroken[depth] = true;
						currentEgg++;
					}
					backTracking(depth + 1);
					if (arr[i].first <= 0)
					{
						isBroken[i] = false;
						currentEgg--;
					}
					if (arr[depth].first <= 0)
					{
						isBroken[depth] = false;
						currentEgg--;
					}
					arr[depth].first += arr[i].second;
					arr[i].first += arr[depth].second;
					b = true;
				}
			}
			if (b == false)
			{
				backTracking(depth + 1);
			}
		}
		else
		{
			backTracking(depth + 1);
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	arr = new pair<int, int>[N];
	isBroken = new bool[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first >> arr[i].second;
		isBroken[i] = false;
	}
	backTracking(0);
	cout << maxEgg << "\n";
	return 0;
}