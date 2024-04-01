#include <iostream>
using namespace std;
long long* segTree;
long long* arr;

long long initSegTree(int start, int end, int currentNode)
{
	if (start == end)
	{
		return segTree[currentNode] = arr[start];
	}
	int mid = (start + end) / 2;
	return segTree[currentNode] = initSegTree(start, mid, currentNode * 2) + initSegTree(mid + 1, end, currentNode * 2 + 1);
}

void update(int start, int end, int currentNode, int updatedNode, long long diff)
{
	if (updatedNode < start || updatedNode > end)
	{
		return;
	}
	if (start == end)
	{
		segTree[currentNode] += diff;
		return;
	}
	segTree[currentNode] += diff;
	int mid = (start + end) / 2;
	update(start, mid, currentNode * 2, updatedNode, diff);
	update(mid + 1, end, currentNode * 2 + 1, updatedNode, diff);
}

long long calcSum(int start, int end, int currentNode, int left, int right)
{
	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <=right)
	{
		return segTree[currentNode];
	}
	int mid = (start + end) / 2;
	return calcSum(start, mid, currentNode * 2, left, right) + calcSum(mid + 1, end, currentNode * 2 + 1, left, right);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, K;
	long long query, a, b;
	cin >> N >> M >> K;
	arr = new long long[N];
	segTree = new long long[4 * N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	initSegTree(0, N-1, 1);
	for (int i = 0; i < M + K; i++)
	{
		cin >> query >> a >> b;
		if (query == 1)
		{
			long long diff = b - arr[a-1];
			arr[a - 1] = b;
			update(0, N - 1, 1, a - 1, diff);
		}
		else
		{
			cout<<calcSum(0, N - 1, 1, a - 1, b - 1)<<"\n";
		}
	}
	return 0;
}