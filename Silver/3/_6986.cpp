#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	double* scores = new double[N];
	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> scores[i];
	}
	sort(scores, scores + N);
	for (int i = K; i < N - K; i++)
	{
		sum += scores[i];
	}
	double answer1 = sum / (N - 2 * K);
	for (int i = 0; i < K; i++)
	{
		sum += scores[K];
	}
	for (int i = N - K; i < N; i++)
	{
		sum += scores[N - K - 1];
	}
	double answer2 = sum / N;
	answer1 += 0.000000001;
	answer2 += 0.000000001;
	cout << fixed;
	cout.precision(2);
	cout << answer1 << "\n" << answer2 << "\n";
	return 0;
}