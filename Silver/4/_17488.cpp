#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
int classNum;
int* leftNum;
vector<int>* registeredNum;
vector<int>* results;

void enroll()
{
	for (int i = 1; i < N+1; i++)
	{
		while (true)
		{
			cin >> classNum;
			if (classNum == -1)
			{
				break;
			}
			else
			{
				registeredNum[classNum].push_back(i);
			}
		}
	}
	for (int i = 1; i < M + 1; i++)
	{
		if (registeredNum[i].size() <= leftNum[i])
		{
			leftNum[i] -= registeredNum[i].size();
			for (int j = 0; j < registeredNum[i].size(); j++)
			{
				int studentNum = registeredNum[i].at(j);
				results[studentNum].push_back(i);
			}
			registeredNum[i].clear();
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	leftNum = new int[M + 1];
	registeredNum = new vector<int>[M + 1];
	results = new vector<int>[N + 1];
	for (int i = 1; i < M + 1; i++)
	{
		cin >> leftNum[i];
	}
	enroll();
	enroll();
	for (int i = 1; i < N + 1; i++)
	{
		if (results[i].size() == 0)
		{
			cout << "¸ÁÇß¾î¿ä" << "\n";
		}
		else
		{
			sort(results[i].begin(), results[i].end());
			for (int j = 0; j < results[i].size(); j++)
			{
				cout << results[i].at(j) << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}