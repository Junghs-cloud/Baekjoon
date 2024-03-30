#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string A, B;
int* arr;
int* answerArr;
bool* isVisited;
int maxAnswer = -1;

void backTracking(int depth, int maxDepth)
{
	if (depth == maxDepth)
	{
		int answer = 0;
		for (int i = 0; i < maxDepth; i++)
		{
			answer = answer * 10 + answerArr[i];
		}
		if (answer > maxAnswer && answer < stoi(B))
		{
			maxAnswer = answer;
		}
	}
	else
	{
		for (int i = 0; i < maxDepth; i++)
		{
			if (depth == 0 && arr[i] == 0)
			{
				continue;
			}
			if (isVisited[i] == false)
			{
				answerArr[depth] = arr[i];
				isVisited[i] = true;
				backTracking(depth + 1, maxDepth);
				isVisited[i] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B;
	int N = A.length();
	arr = new int[N];
	isVisited = new bool[N];
	answerArr = new int[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = A.at(i) - 48;
		isVisited[i] = false;
	}
	backTracking(0, N);
	cout << maxAnswer << "\n";
	return 0;
}