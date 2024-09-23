#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int a, b;
	cin >> N >> M;
	int* arr = new int[N];
	int* sum = new int[N+1];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	sum[0] = 0;
	for (int i = 0; i < N; i++)
	{
		sum[i + 1] = sum[i] + arr[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		cout<<sum[b] - sum[a-1]<<"\n";
	}
	return 0;
}