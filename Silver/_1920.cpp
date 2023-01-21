#include <iostream>
#include <algorithm>
using namespace std;

int N;
int* arrN;

void binarySearch(int target, int start, int end)
{
	while (start <= end)
	{
		int mid = (end + start) / 2;
		if (target == arrN[mid])
		{
			cout << "1" << "\n";
			return;
		}
		else if (target < arrN[mid])
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	cout << "0" << "\n";
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	int M;
	cin >> N;
	arrN = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arrN[i];
	}
	cin >> M;
	int* arrM = new int[M];
	for (int i = 0; i < M; i++)
	{
		cin >> arrM[i];
	}
	sort(arrN, arrN + N);
	for (int i = 0; i < M; i++)
	{
		binarySearch(arrM[i], 0, N - 1);
	}
	return 0;
}