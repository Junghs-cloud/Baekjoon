#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int* arr;
int* maxSegTree;
int* minSegTree;

int initMin(int start, int end, int nodeNum)
{
	if (start == end)
	{
		return minSegTree[nodeNum] = arr[start];
	}
	else
	{
		int mid = (start + end) / 2;
		return minSegTree[nodeNum] = min(initMin(start, mid, nodeNum * 2), initMin(mid + 1, end, nodeNum * 2 + 1));
	}
}

int initMax(int start, int end, int nodeNum)
{
	if (start == end)
	{
		return maxSegTree[nodeNum] = arr[start];
	}
	else
	{
		int mid = (start + end) / 2;
		return maxSegTree[nodeNum] = max(initMax(start, mid, nodeNum * 2), initMax(mid + 1, end, nodeNum*2 + 1));
	}
}

int getMin(int left, int right, int start, int end, int nodeNum)
{
	if (left > end || right < start)
	{
		return 1000000000;
	}
	else if (left <= start && end <= right)
	{
		return minSegTree[nodeNum];
	}
	else
	{
		int mid = (start + end) / 2;
		return min(getMin(left, right, start, mid, nodeNum * 2), getMin(left, right, mid + 1, end, nodeNum * 2 + 1));
	}
}

int getMax(int left, int right, int start, int end, int nodeNum)
{
	if (left > end || right < start)
	{
		return 0;
	}
	else if (left <= start && end <=right)
	{
		return maxSegTree[nodeNum];
	}
	else
	{
		int mid = (start + end) / 2;
		return max(getMax(left, right, start, mid, nodeNum * 2), getMax(left, right, mid + 1, end, nodeNum * 2+1));
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> N >> M;
	arr = new int[N];
	maxSegTree = new int[4 * N];
	minSegTree = new int[4 * N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	initMin(0, N - 1, 1);
	initMax(0, N - 1, 1);
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		cout << getMin(a-1, b-1, 0, N-1, 1) << " " << getMax(a - 1, b - 1, 0, N - 1, 1) << "\n";
	}
	return 0;
}