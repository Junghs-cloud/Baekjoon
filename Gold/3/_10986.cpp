#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int num;
	long long answer = 0;
	cin >> N>>M;
	long long* sums = new long long[N + 1];
	vector<int>* v = new vector<int>[M];
	sums[0] = 0;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> num;
		sums[i] = sums[i - 1] % M + num % M;
		sums[i] = sums[i] % M;
		if (sums[i] == 0)
		{
			answer++;
		}
		answer += v[sums[i]].size();
		v[sums[i]].push_back(i);
	}
	cout << answer << "\n";
	return 0;
}