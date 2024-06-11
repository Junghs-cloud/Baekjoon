#include <iostream>
#include <algorithm>
#include <string>
#define INF 987654321
using namespace std;
string str;
char* answerArr;
char* inputArr;
int answer = INF;
bool* isVisited;
int N;

void backTracking(int depth)
{
	if (depth == N)
	{
		string currentStr = "";
		for (int i = 0; i < N; i++)
		{
			currentStr += answerArr[i];
		}
		int currentInt = stoi(currentStr);
		if (currentInt > stoi(str) && currentInt < answer)
		{
			answer = currentInt;
		}
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (isVisited[i] == false)
			{
				answerArr[depth] = inputArr[i];
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

	cin >> str;
	N = str.length();
	isVisited = new bool[N];
	inputArr = new char[N];
	answerArr = new char[N];
	for (int i = 0; i < N; i++)
	{
		inputArr[i] = str.at(i);
		isVisited[i] = false;
	}
	backTracking(0);
	if (answer == INF)
	{
		cout << 0 << "\n";
	}
	else
	{
		cout << answer << "\n";
	}
	return 0;
}