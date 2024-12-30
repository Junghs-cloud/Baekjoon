#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

int* makeArr;
int* arr;
int N;
bool* isVisited;
bool* isPrime;
set<int> answers;

void find(int depth, int maxDepth)
{
	if (depth == maxDepth)
	{
		int num = 0;
		for (int i = 0; i < maxDepth; i++)
		{
			num = num * 10 + makeArr[i];
		}
		if (isPrime[num] == true)
		{
			answers.insert(num);
		}
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (isVisited[i] == false)
			{
				isVisited[i] = true;
				makeArr[depth] = arr[i];
				find(depth + 1, maxDepth);
				isVisited[i] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	isPrime = new bool[10000001];
	for (int i = 0; i < 10000001; i++)
	{
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i <= sqrt(10000000); i++)
	{
		for (int j = 2 * i; j <= 10000000; j += i)
		{
			isPrime[j] = false;
		}
	}
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		answers.clear();
		string str;
		cin >> str;
		N = str.length();
		arr = new int[N];
		makeArr = new int[N];
		isVisited = new bool[N];
		for (int i = 0; i < N; i++)
		{
			isVisited[i] = false;
			arr[i] = str.at(i) - 48;
		}
		for (int i = 1; i <= N; i++)
		{
			find(0, i);
		}
		cout << answers.size() << "\n";
	}
	return 0;
}