#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

deque<int> gears[4];
bool isVisited[4];
int rotateGearNum;
int rotateDirection;

void rotate(int gearNum, int rotateDir)
{
	isVisited[gearNum] = true;
	int checkNSLeft = gears[gearNum].at(6);
	int checkNSRight = gears[gearNum].at(2);
	if (rotateDir == 1) //시계방향
	{
		int temp = gears[gearNum].back();
		gears[gearNum].pop_back();
		gears[gearNum].push_front(temp);
		if (gearNum <= 2 && isVisited[gearNum + 1] ==false && checkNSRight != gears[gearNum +1].at(6))
		{
			rotate(gearNum + 1, -1);
		}
		if (gearNum >= 1 && isVisited[gearNum - 1]==false && checkNSLeft != gears[gearNum - 1].at(2))
		{
			rotate(gearNum - 1, -1);
		}
	}
	else //반시계 방향
	{
		int temp = gears[gearNum].front();
		gears[gearNum].pop_front();
		gears[gearNum].push_back(temp);
		if (gearNum <= 2 && isVisited[gearNum + 1] == false&& checkNSRight != gears[gearNum + 1].at(6))
		{
			rotate(gearNum + 1, 1);
		}
		if (gearNum >= 1 && isVisited[gearNum - 1] == false && checkNSLeft != gears[gearNum - 1].at(2))
		{
			rotate(gearNum - 1, 1);
		}
	}
}

int main()
{
	int N;
	int sum = 0;
	string gearInitialState;

	for (int i = 0; i < 4; i++)
	{
		isVisited[i] = false;
		cin >> gearInitialState;
		for (int j = 0; j < 8; j++)
		{
			gears[i].push_back(gearInitialState[j] - 48);
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			isVisited[j] = false;
		}
		cin >> rotateGearNum >> rotateDirection;
		rotate(rotateGearNum-1, rotateDirection);
	}
	for (int i = 0; i < 4; i++)
	{
		if (gears[i].at(0) == 0)
		{
			continue;
		}
		else
		{
			sum += (int)pow(2, i);
		}
	}
	cout << sum << "\n";
	return 0;
}