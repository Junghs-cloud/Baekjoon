#include <iostream>
using namespace std;
long long answer = 0;
int* answerArr;
int* arr;
int N;
long long S;
bool* isVisited;

void backTracking(int depth, int index, int num)
{
	if (depth == num)
	{
		long long sum = 0;
		for (int i = 0; i < num; i++)
		{
			sum += answerArr[i];
		}
		if (sum == S)
		{
			answer++;
		}
	}
	for (int i = index; i < N; i++)
	{
		if (isVisited[i] == false)
		{
			answerArr[depth] = arr[i];
			isVisited[i] = true;
			backTracking(depth + 1, i + 1, num);
			isVisited[i] = false;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> S;
	answerArr = new int[N];
	arr = new int[N];
	isVisited = new bool[N];
	for (int i = 0; i < N; i++)
	{
		isVisited[i] = false;
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++)
	{
		backTracking(0, 0, i);
	}
	cout << answer << "\n";
	return 0;
}