#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
long long answer;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	cin >> N;
	int* arrA = new int[N];
	int* partSumA = new int[N + 1];
	partSumA[0] = 0;
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < N; i++)
	{
		cin >> arrA[i];
		partSumA[i + 1] = partSumA[i] + arrA[i];
	}
	for (int i = 1; i < N+1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			v1.push_back(partSumA[i] - partSumA[j]);
		}
	}
	cin >> M;
	int* arrB = new int[M];
	int* partSumB = new int[M + 1];
	partSumB[0] = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> arrB[i];
		partSumB[i + 1] = partSumB[i] + arrB[i];
	}
	for (int i = 1; i < M + 1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			v2.push_back(partSumB[i] - partSumB[j]);
		}
	}
	sort(v2.begin(), v2.end());
	for (int i = 0; i < v1.size(); i++)
	{
		answer += upper_bound(v2.begin(), v2.end(), T - v1.at(i)) - lower_bound(v2.begin(), v2.end(), T - v1.at(i));
	}
	cout << answer << "\n";
	return 0;
}