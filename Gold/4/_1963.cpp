#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <utility>
using namespace std;

bool* isPrime;
queue<pair<string, int>> bfsQueue;
set<string> s;

void bfs(string A, string B)
{
	bfsQueue.push(make_pair(A, 0));
	s.insert(A);
	bool isImpossible = true;
	while (!bfsQueue.empty())
	{
		string currentString = bfsQueue.front().first;
		int currentCount = bfsQueue.front().second;
		if (currentString == B)
		{
			isImpossible = false;
			cout << currentCount << "\n";
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j <= 9; j++)
			{
				string newString = currentString.substr(0, i);
				string k = to_string(j);
				newString += k;
				newString += currentString.substr(i + 1);
				
				int newA = stoi(newString);
				if (newA >=1000 && isPrime[newA] == true && s.find(newString) == s.end())
				{
					s.insert(newString);
					bfsQueue.push(make_pair(newString, currentCount+1));
				}
			}
		}
		bfsQueue.pop();
	}
	if (isImpossible == true)
	{
		cout << "Impossible" << "\n";
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string A, B;
	int T;
	isPrime = new bool[10000];
	int answer = 0;
	for (int i = 0; i < 10000; i++)
	{
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i <= 100; i++)
	{
		for (int j = 2 * i; j < 10000; j += i)
		{
			isPrime[j] = false;
		}
	}
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> A >> B;
		bfs(A, B);
		while (!bfsQueue.empty())
		{
			bfsQueue.pop();
		}
		s.clear();
	}
	return 0;
}