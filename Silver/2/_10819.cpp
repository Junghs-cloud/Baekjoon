#include <iostream>
#include <cmath>
using namespace std;

int* arr;
int* answerArr;
bool* isVisited;
int N;
int answerSum;

void backTracking(int depth)
{
	if (depth == N)
	{
		int sum = 0;
		for (int i = 0; i < N-1; i++)
		{
			sum += abs(answerArr[i] - answerArr[i + 1]);
		}
		if (sum > answerSum)
		{
			answerSum = sum;
		}
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (isVisited[i] == false)
			{
				answerArr[depth] = arr[i];
				isVisited[i] = true;
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

	cin >> N;
	arr = new int[N];
	isVisited = new bool[N];
	answerArr = new int[N];
	for (int i = 0; i < N; i++)
	{
		isVisited[i] = false;
		cin >> arr[i];
	}
	backTracking(0);
	cout << answerSum << "\n";
	return 0;
}