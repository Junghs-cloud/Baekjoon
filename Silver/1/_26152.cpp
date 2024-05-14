#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, Q, B;
	int right = 0;
	cin >> N;
	long long* heights = new long long[N];
	for (int i = 0; i < N; i++)
	{
		cin >> heights[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> B;
		heights[i] -= B;
	}
	cin >> Q;
	pair<int, int>* birds = new pair<int, int>[Q];
	int* points = new int[Q];
	for (int i = 0; i < Q; i++)
	{
		cin >> birds[i].first;
		birds[i].second = i;
		points[i] = 0;
	}
	sort(birds, birds + Q, greater<>());
	for (int i = 0; i < Q; i++)
	{
		while (right < N && heights[right] >= birds[i].first)
		{
			right++;
		}
		int index = birds[i].second;
		points[index] = right;
	}
	for (int i = 0; i < Q; i++)
	{
		cout << points[i] << "\n";
	}
	return 0;
}