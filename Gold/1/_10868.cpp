#include <iostream>
#include <cmath>
using namespace std;
int* arr;
int* segTree;

int init(int left, int right, int nodeNum)
{
	if (left == right)
	{
		return segTree[nodeNum] = arr[left];
	}
	else
	{
		int mid = (left + right) / 2;
		segTree[nodeNum] = min(init(left, mid, nodeNum * 2), init(mid + 1, right, nodeNum * 2 + 1));
		return segTree[nodeNum];
	}
}

int search(int start, int end, int left, int right, int nodeNum)
{
	if (start > right || end < left)
	{
		return 1000000001;
	}
	else if (start <= left && right <= end)
	{
		return segTree[nodeNum];
	}
	else
	{
		int mid = (left + right) / 2;
		return min(search(start, end, left, mid, nodeNum * 2), search(start, end, mid + 1, right, nodeNum * 2 + 1));
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int a, b;
	cin >> N>>M;
	arr = new int[N];
	segTree = new int[4 * N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	init(0, N - 1, 1);
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		cout<<search(a-1, b-1, 0, N - 1, 1)<<"\n";
	}
	return 0;
}