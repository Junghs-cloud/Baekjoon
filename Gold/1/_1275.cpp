#include <iostream>
using namespace std;
long long* segTree;
long long* arr;

long long init(int left, int right, int nodeNum)
{
	if (left == right)
	{
		return segTree[nodeNum] = arr[left];
	}
	else
	{
		int mid = (left + right) / 2;
		segTree[nodeNum] = init(left, mid, nodeNum * 2) + init(mid + 1, right, nodeNum * 2 + 1);
		return segTree[nodeNum];
	}
}

void update(int left, int right, int nodeNum, int targetNodeNum, long long diff)
{
	if (right < targetNodeNum || left > targetNodeNum)
	{
		return;
	}
	if (left == right)
	{
		segTree[nodeNum] += diff;
		return;
	}
	segTree[nodeNum] += diff;
	int mid = (left + right) / 2;
	update(left, mid, nodeNum * 2, targetNodeNum, diff);
	update(mid + 1, right, nodeNum * 2 + 1, targetNodeNum, diff);
}

long long calc(int left, int right, int start, int end, int nodeNum)
{
	if (right < start || left > end)
	{
		return 0;
	}
	if (left >= start && right <= end)
	{
		return segTree[nodeNum];
	}
	int mid = (left + right) / 2;
	return calc(left, mid, start, end, nodeNum * 2) + calc(mid + 1, right, start, end, nodeNum * 2 + 1);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int x, y;
	long long a, b;
	cin >> N >> M;
	segTree = new long long[4 * N];
	arr = new long long[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	init(0, N - 1, 1);
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y >> a >> b;
		if (x <= y)
		{
			cout<<calc(0, N-1, x-1, y-1, 1)<<"\n";
		}
		else
		{
			cout<<calc(0, N-1, y-1, x-1, 1)<<"\n";
		}
		long long diff = b - arr[a - 1];
		arr[a - 1] = b;
		update(0, N - 1, 1, a - 1, diff);
	}
	return 0;
}