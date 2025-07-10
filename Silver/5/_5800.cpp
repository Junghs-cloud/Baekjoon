#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int K, N;
	cin >> K;
	for (int i = 1; i <= K; i++)
	{
		cin >> N;
		int* scores = new int[N];
		int largestGap = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> scores[j];
		}
		sort(scores, scores + N, greater<>());
		for (int j = 1; j < N; j++)
		{
			largestGap = max(largestGap, scores[j-1] - scores[j]);
		}
		cout << "Class " << i << "\n";
		cout << "Max " << scores[0] << ", Min " << scores[N-1] << ", Largest gap " << largestGap << "\n";
	}
	return 0;
}