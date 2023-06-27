#include <iostream>
using namespace std;
int N;
char* arr;
int* minNum;
int* maxNum;
int* currentArr;
bool* isVisited;
int numCount = 0;
void backtracking(int depth)
{
	if (depth == N + 1)
	{
		if (numCount == 0)
		{
			for (int i = 0; i < N + 1; i++)
			{
				minNum[i] = currentArr[i];
			}
			numCount++;
		}
		else
		{
			for (int i = 0; i < N + 1; i++)
			{
				maxNum[i] = currentArr[i];
			}
		}
		return;
	}
	else
	{
		for (int i = 0; i <= 9; i++)
		{
			if (depth >= 1 && arr[depth - 1] == '<')
			{
				if (currentArr[depth - 1] < i && isVisited[i]==false)
				{
					isVisited[i] = true;
					currentArr[depth] = i;
					backtracking(depth + 1);
					isVisited[i] = false;
				}
			}
			else if (depth >= 1 && arr[depth - 1] == '>')
			{
				if (currentArr[depth - 1] > i && isVisited[i] == false)
				{
					isVisited[i] = true;
					currentArr[depth] = i;
					backtracking(depth + 1);
					isVisited[i] = false;
				}
			}
			else
			{
				if (isVisited[i] == false)
				{
					isVisited[i] = true;
					currentArr[depth] = i;
					backtracking(depth + 1);
					isVisited[i] = false;
				}
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	arr = new char[N];
	currentArr = new int [N + 1];
	isVisited = new bool[10];
	minNum = new int[N + 1];
	maxNum = new int[N + 1];
	for (int i = 0; i <= 9; i++)
	{
		isVisited[i] = false;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	backtracking(0);
	for (int i = 0; i < N + 1; i++)
	{
		cout << maxNum[i];
	}
	cout << "\n";
	for (int i = 0; i < N + 1; i++)
	{
		cout << minNum[i];
	}
	cout << "\n";
	return 0;
}