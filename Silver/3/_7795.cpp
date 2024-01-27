#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int A, B;
		cin >> A >> B;
		int* arrA = new int[A];
		int* arrB = new int[B];
		int answer = 0;
		for (int i = 0; i < A; i++)
		{
			cin >> arrA[i];
		}
		for (int i = 0; i < B; i++)
		{
			cin >> arrB[i];
		}
		sort(arrA, arrA + A);
		sort(arrB, arrB + B);
		for (int i = 0; i < A; i++)
		{
			int current = arrA[i];
			if (current <= arrB[0])
			{
				continue;
			}
			else if (current > arrB[B - 1])
			{
				answer += B;
			}
			else
			{
				int index = lower_bound(arrB, arrB + B, current) - arrB;
				if (index == 0)
				{
					continue;
				}
				else
				{
					answer += index;
				}
			}
		}
		cout << answer << "\n";
	}
	return 0;
}