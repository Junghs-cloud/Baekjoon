#include <iostream>
#include <cmath>
using namespace std;
int N, M;
int* arr;
int answer;

void find(int day, int prevDayIndex, int sum)
{
	if (day == N)
	{
		for (int i = 0; i < 6; i++)
		{
			if (abs(i - prevDayIndex) == 3 || i == prevDayIndex)
			{
				if (sum + arr[i] / 2 >= M)
				{
					answer++;
				}
			}
			else
			{
				if (sum + arr[i] >= M)
				{
					answer++;
				}
			}
		}
		return;
	}
	else if (day == 1)
	{
		for (int i = 0; i < 6; i++)
		{
			find(day + 1, i, arr[i]);
		}
	}
	else
	{
		for (int i = 0; i < 6; i++)
		{
			if (abs(i - prevDayIndex) == 3 || i == prevDayIndex)
			{
				find(day + 1, i, sum + arr[i] / 2);
			}
			else
			{
				find(day + 1, i, sum + arr[i]);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	arr = new int[6];
	cin >> N >> M;
	for (int i = 0; i < 6; i++)
	{
		cin >> arr[i];
	}
	find(1, -999, 0);
	cout << answer << "\n";
	return 0;
}