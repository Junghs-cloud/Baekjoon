#include <iostream>
using namespace std;
long long* totalLayers;
long long* patty;

long long eatHamburger(int level, long long leftLayer)
{
	long long answer = 0;
	if (leftLayer == totalLayers[level])
	{
		return patty[level];
	}
	if (level == 0)
	{
		if (leftLayer == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		leftLayer--;
		if (leftLayer == 0)
		{
			return answer;
		}
		else if (leftLayer >= totalLayers[level - 1])
		{
			answer += eatHamburger(level - 1, totalLayers[level-1]);
			leftLayer -= totalLayers[level - 1];
			if (leftLayer > 0)
			{
				answer++;
				leftLayer--;
				if (leftLayer == 0)
				{
					return answer;
				}
				else if (leftLayer >= totalLayers[level - 1])
				{
					answer+= eatHamburger(level - 1, totalLayers[level - 1]);
					leftLayer -= totalLayers[level - 1];
					if (leftLayer > 0)
					{
						leftLayer--;
					}
				}
				else
				{
					answer += eatHamburger(level - 1, leftLayer);
				}
			}
			else
			{
				return answer;
			}
		}
		else
		{
			answer += eatHamburger(level - 1, leftLayer);
		}
	}
	return answer;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	long long layer;
	cin >> N >> layer;
	totalLayers = new long long[51];
	patty = new long long[51];
	totalLayers[0] = 1;
	patty[0] = 1;
	for (int i = 1; i < 51; i++)
	{
		totalLayers[i] = 2 * totalLayers[i - 1] + 3;
		patty[i] = patty[i-1]*2 + 1;
	}
	cout << eatHamburger(N, layer) << "\n";
	return 0;
}