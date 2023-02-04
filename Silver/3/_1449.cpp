#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, L;
	cin >> N >> L;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	double nextStart = arr[0] - 0.5;
	double nextEnd = nextStart + L;
	int tapeCount = 0;
	for (int i = 0; i < N; i++)
	{
		if (nextEnd > arr[i])
		{
			continue;
		}
		else
		{
			tapeCount++;
			nextStart = arr[i] - 0.5;
			nextEnd = nextStart + L;
		}
	}
	tapeCount++;
	cout<<tapeCount<<"\n";
	return 0;
}