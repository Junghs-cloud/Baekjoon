#include <iostream>
using namespace std;
long long* segTree;
int* arr;

long long init(int left, int right, int nodeNum)
{
	if (left == right)
	{
		return segTree[nodeNum] = arr[left];
	}
	else
	{
		int mid = (left + right) / 2;
		segTree[nodeNum] = (init(left, mid, nodeNum * 2) % 1000000007 * init(mid + 1, right, nodeNum * 2 + 1) % 1000000007) % 1000000007;
		return segTree[nodeNum];
	}
}

long long update(int left, int right, int nodeNum, int updateNodeNum, int value)
{
	if (updateNodeNum < left || updateNodeNum > right)
	{
		return segTree[nodeNum];
	}
	if (left == right)
	{
		segTree[nodeNum] = value;
		return segTree[nodeNum];
	}
	int mid = (left + right) / 2;
	segTree[nodeNum] = update(left, mid, nodeNum * 2, updateNodeNum, value) % 1000000007 * update(mid + 1, right, nodeNum * 2 + 1, updateNodeNum, value) % 1000000007;
	segTree[nodeNum] %= 1000000007;
	return segTree[nodeNum];
}

long long get(int left, int right, int nodeNum, int wantLeft, int wantRight)
{
	if (wantLeft > right || wantRight < left)
	{
		return 1;
	}
	if (left >= wantLeft && right <= wantRight)
	{
		return segTree[nodeNum];
	}
	int mid = (left + right) / 2;
	return (get(left, mid, nodeNum * 2, wantLeft, wantRight) % 1000000007 * get(mid + 1, right, nodeNum * 2 + 1, wantLeft, wantRight)% 1000000007) % 1000000007;

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, K;
	int a, b, c;
	cin >> N >> M >> K;
	arr = new int[N];
	segTree = new long long[4 * N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	init(0, N - 1, 1);
	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(0, N - 1, 1, b-1, c);
		}
		else
		{
			cout << get(0, N - 1, 1, b - 1, c - 1)<<"\n";
		}
	}
	return 0;
}