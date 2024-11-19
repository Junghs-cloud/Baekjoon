#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int* arr1;
int* arr2;
bool* isVisited1;
bool* isVisited2;

vector<int> v1;
vector<int> v2;

void dfs(int depth, int maxDepth, int index, vector<int>& v, int* arr, bool* isVisited, int arrSize, int sum)
{
	if (depth == maxDepth)
	{
		v.push_back(sum);
	}
	else
	{
		for (int i = index; i < arrSize; i++)
		{
			if (isVisited[i] == false)
			{
				sum += arr[i];
				isVisited[i] = true;
				dfs(depth + 1, maxDepth, i+1, v, arr, isVisited, arrSize, sum);
				sum -= arr[i];
				isVisited[i] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int size1 = N / 2;
	int size2 = N - size1;
	arr1 = new int[size1];
	isVisited1 = new bool[size1];
	arr2 = new int[size2];
	isVisited2 = new bool[size2];
	long long answer = 0;
	for (int i = 0; i < size1; i++)
	{
		cin >> arr1[i];
		isVisited1[i] = false;
	}
	for (int i = 0; i < size2; i++)
	{
		cin >> arr2[i];
		isVisited2[i] = false;
	}
	for (int i = 1; i <= size1; i++)
	{
		dfs(0, i, 0, v1, arr1, isVisited1, size1, 0);
	}
	for (int i = 1; i <= size2; i++)
	{
		dfs(0, i, 0, v2, arr2, isVisited2, size2, 0);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	answer += upper_bound(v1.begin(), v1.end(), M) - lower_bound(v1.begin(), v1.end(), M);
	for (int i = 0; i < v1.size(); i++)
	{
		int counts = upper_bound(v2.begin(), v2.end(), M - v1.at(i)) - lower_bound(v2.begin(), v2.end(), M - v1.at(i));
		answer += counts;
	}
	answer += upper_bound(v2.begin(), v2.end(), M) - lower_bound(v2.begin(), v2.end(), M);
	cout << answer << "\n";
	return 0;
}