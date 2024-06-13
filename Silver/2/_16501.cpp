#include <iostream>
#include <algorithm>
using namespace std;
double* arr;
double*  team;
bool* isVisited;
double answer;

void backTracking(int depth)
{
	if (depth == 8)
	{
		double team1 = (team[0] + team[1]) / 2;
		double team2 = (team[2] + team[3]) / 2;
		double team3 = (team[4] + team[5]) / 2;
		double team4 = (team[6] + team[7]) / 2;
		double happy1 = (double)1 - ((abs(team1 - team2)) / 10);
		double happy2 = (double)1 - ((abs(team3 - team4)) / 10);
		answer = max(min(happy1, happy2), answer);
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			if (isVisited[i] == false)
			{
				isVisited[i] = true;
				team[depth] = arr[i];
				backTracking(depth + 1);
				isVisited[i] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	answer = 0;
	arr = new double[8];
	team = new double[8];
	isVisited = new bool[8];
	for (int i = 0; i < 8; i++)
	{
		cin >> arr[i];
		isVisited[i] = false;
	}
	backTracking(0);
	cout << fixed;
	if (int(answer * 10) == answer * 10)
	{
		cout.precision(1);
	}
	else
	{
		cout.precision(2);
	}
	cout << answer << "\n";
	return 0;
}