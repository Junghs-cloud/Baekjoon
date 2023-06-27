#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	int findCardNum = 0;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> findCardNum;
		int lower = lower_bound(arr, arr + N, findCardNum) - arr;
		int upper = upper_bound(arr, arr + N, findCardNum) - arr;
		cout<<upper - lower<<" ";
	}
	cout << "\n";
	return 0;
}