#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int pow(int A, int B)
{
	int num = A;
	for (int i = 1; i < B; i++)
	{
		num *= A;
	}
	return num;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int maxLength = 0;
	long long answer = 0;
	priority_queue<pair<int, int>> pq;
	cin >> N;
	string* str = new string[N];
	int* calculatedNumbers = new int[N];
	int* prioritys = new int[26];
	int* allocatedNumbers = new int[26];
	for (int i = 0; i < 26; i++)
	{
		allocatedNumbers[i] = -1;
		prioritys[i] = 0;
	}
	int current = 9;
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
		calculatedNumbers[i] = 0;
		maxLength = max(maxLength, (int) str[i].length());
	}
	for (int i = 0; i < N; i++)
	{
		str[i] = str[i].insert(0, maxLength - str[i].length(), '0');
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < maxLength; j++)
		{
			if (str[i].at(j) == '0')
			{
				continue;
			}
			int index = str[i].at(j) - 'A';
			prioritys[index] += pow(10, maxLength - j);
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (prioritys[i] != 0)
		{
			pq.push(pair(prioritys[i], i));
		}
	}

	while (!pq.empty())
	{
		pair<int, int> top = pq.top();
		allocatedNumbers[top.second] = current;
		current--;
		pq.pop();
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < maxLength; j++)
		{
			if (str[i].at(j) == '0')
			{
				continue;
			}
			int index = str[i].at(j) - 'A';
			calculatedNumbers[i] = calculatedNumbers[i]*10 + allocatedNumbers[index];
		}
	}

	for (int i = 0; i < N; i++)
	{
		answer += calculatedNumbers[i];
	}
	cout << answer << "\n";
	return 0;
}