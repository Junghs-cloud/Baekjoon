#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{

		long long sum = 0;
		int N, M;
		cin >> N >> M;
		int* arrA = new int[N];
		int* arrB = new int[M];
		for (int i = 0; i < N; i++)
		{
			cin >> arrA[i];
		}
		for (int j = 0; j < M; j++)
		{
			cin >> arrB[j];
		}
		sort(arrB, arrB + M);
		for (int i = 0; i < N; i++)
		{
			if (arrA[i] < arrB[0])
			{
				sum += arrB[0];
			}
			else if (arrA[i] > arrB[M - 1])
			{
				sum += arrB[M - 1];
			}
			else
			{
				int index = lower_bound(arrB, arrB + M, arrA[i]) - arrB;
				int lowerIndex = 0;
				if (index == 0)
				{
					lowerIndex = 0;
				}
				else
				{
					lowerIndex = index - 1;
				}

				if (lowerIndex == index)
				{
					sum += arrB[index];
				}
				else
				{
					int lowerDist = arrB[lowerIndex] - arrA[i];
					if (lowerDist < 0)
					{
						lowerDist = -lowerDist;
					}
					int dist = arrB[index] - arrA[i];
					if (dist < 0)
					{
						dist = -dist;
					}
					if (lowerDist <= dist)
					{
						sum += arrB[lowerIndex];
					}
					else
					{
						sum += arrB[index];
					}
				}
			}
		}
		cout << sum << "\n";
		delete[] arrA;
		delete[] arrB;
	}
	return 0;
}