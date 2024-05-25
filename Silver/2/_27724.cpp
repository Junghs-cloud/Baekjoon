#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, K;
	int answer = 0;
	cin >> N >> M >> K;
	while (K != 1)
	{
		if (K % 2 == 1)
		{
			K--;
		}
		K /= 2;
		answer++;
	}
	answer += M;
	int maxCount = log2(N);
	answer = min(answer, maxCount);
	cout << answer << "\n";
	return 0;
}