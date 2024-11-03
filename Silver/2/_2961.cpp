#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
int* sour;
int* bitter;
bool* isUsed;
int answer = 2000000000;

void backTracking(int depth, int maxDepth)
{
	if (depth == maxDepth)
	{
		int sourTaste = 1;
		int bitterTaste = 0;
		for (int i = 0; i < N; i++)
		{
			if (isUsed[i] == true)
			{
				sourTaste *= sour[i];
				bitterTaste += bitter[i];
			}
		}
		answer = min(answer, abs(sourTaste - bitterTaste));
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (isUsed[i] == false)
			{
				isUsed[i] = true;
				backTracking(depth + 1, maxDepth);
				isUsed[i] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	sour = new int[N];
	bitter = new int[N];
	isUsed = new bool[N];
	for (int i = 0; i < N; i++)
	{
		cin >> sour[i]>>bitter[i];
		isUsed[i] = false;
	}
	for (int i = 1; i <= N; i++)
	{
		backTracking(0, i);
	}
	cout << answer << "\n";
	return 0;
}