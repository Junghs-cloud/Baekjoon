#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int* HI = new int[N];
	int* ARC = new int[M];
	long long HIWin = 0;
	long long ARCWin = 0;
	long long draw = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> HI[i];
	}
	sort(HI, HI + N);
	for (int j = 0; j < M; j++)
	{
		cin >> ARC[j];
	}
	sort(ARC, ARC + M);
	for (int i = 0; i < N; i++)
	{
		int upper = upper_bound(ARC, ARC + M, HI[i]) - ARC;
		int lower = lower_bound(ARC, ARC + M, HI[i]) - ARC;
		HIWin += lower;
		draw += upper - lower;
		ARCWin += M - upper;
	}
	cout << HIWin << " " << ARCWin << " " << draw << "\n";
	return 0;
}