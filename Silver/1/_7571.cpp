#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int* arrX = new int[M];
	int* arrY = new int[M];
	for (int i = 0; i < M; i++)
	{
		cin >> arrX[i] >> arrY[i];
	}
	sort(arrX, arrX + M);
	sort(arrY, arrY + M);
	int midX = arrX[M / 2];
	int midY = arrY[M / 2];
	int sum = 0;
	for (int i = 0; i < M; i++)
	{
		sum += abs(arrX[i] - midX);
		sum += abs(arrY[i] - midY);
	}
	cout << sum << "\n";
	return 0;
}