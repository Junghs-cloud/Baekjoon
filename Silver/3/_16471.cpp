#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* A = new int[N];
	int* B = new int[N];
	int answer = 0;
	int next = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}
	sort(A, A + N);
	sort(B, B + N);
	for (int i = 0; i < N; i++)
	{
		if (A[i] >= B[N-1])
		{
			break;
		}
		int index = upper_bound(B + next, B + N, A[i]) - B;
		if (index < N)
		{
			answer++;
		}
		next = index + 1;
		if (next >= N)
		{
			break;
		}
	}
	if (answer >= (N + 1) / 2)
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO" << "\n";
	}
	return 0;
}