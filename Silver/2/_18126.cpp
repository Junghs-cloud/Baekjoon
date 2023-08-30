#include <iostream>
#include <utility>
#include <vector>
using namespace std;
vector<pair<int, long long>>* arr;
bool* isVisited;
long long dist = 0;
long long answer = 0;
int N;

void find(int x)
{
	if (dist >= answer)
	{
		answer = dist;
		isVisited[x] = true;
	}
	for (int i = 0; i < arr[x].size(); i++)
	{
		if (isVisited[arr[x].at(i).first] == false)
		{
			isVisited[arr[x].at(i).first] = true;
			dist += arr[x].at(i).second;
			find(arr[x].at(i).first);
			dist -= arr[x].at(i).second;
			isVisited[arr[x].at(i).first] = false;
		}

	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c;
	cin >> N;
	arr = new vector<pair<int, long long>>[N + 1];
	isVisited = new bool[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		isVisited[i] = false;
	}
	for (int i = 0; i < N-1; i++)
	{
		cin >> a >> b >> c;
		arr[a].push_back(make_pair(b, c));
		arr[b].push_back(make_pair(a, c));
	}
	isVisited[1] = true;
	find(1);
	cout << answer<< "\n";
	return 0;
}