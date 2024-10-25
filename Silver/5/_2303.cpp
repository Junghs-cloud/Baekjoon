#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
bool* isVisited;
int* arr;
int* sumArr;
int maxSum;

void backTracking(int depth)
{
	if (depth == 3)
	{
		int answer = 0;
		for (int i = 0; i < 3; i++)
		{
			answer += sumArr[i];
		}
		if (answer >= 10)
		{
			answer %= 10;
		}
		maxSum = max(maxSum, answer);
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			if (isVisited[i] == false)
			{
				sumArr[depth] = arr[i];
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

	int N;
	cin >> N;
	vector<pair<int, int>> answer;
	arr = new int[5];
	sumArr = new int[3];
	isVisited = new bool[5];
	for (int i = 0; i < 5; i++)
	{
		isVisited[i] = false;
	}
	for (int i = 0; i < N; i++)
	{
		maxSum = 0;
		for (int j = 0; j < 5; j++)
		{
			cin >> arr[j];
		}
		backTracking(0);
		answer.push_back(pair(maxSum, i+1));
	}
	sort(answer.begin(), answer.end());
	cout << answer.back().second << "\n";
	return 0;
}