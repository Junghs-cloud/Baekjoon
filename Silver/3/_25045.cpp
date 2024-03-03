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
	long long* products = new long long[N];
	long long* companies = new long long[M];
	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> products[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> companies[i];
	}
	sort(products, products + N);
	sort(companies, companies + M);
	for (int i = 0; i < min(M , N) ; i++)
	{
		if (products[N - 1 - i] - companies[i] >= 0)
		{
			answer += products[N - 1 - i] - companies[i];
		}
	}
	cout << answer << "\n";
	return 0;
}