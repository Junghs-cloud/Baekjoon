#include <iostream>
#include <set>
using namespace std;

long long pow(long long N, int M)
{
	long long temp = N;
	for (int i = 0; i < M; i++)
	{
		temp *= N;
	}
	return temp;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int trainNum, query, seatNum;
	long long powNum = pow(2, 20);
	set<long long> s;
	cin >> N >> M;
	long long* arr = new long long[N+1];
	for (int i = 1; i < N+1; i++)
	{
		arr[i] = 0;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> query >> trainNum;
		if (query == 1)
		{
			cin >> seatNum;
			arr[trainNum] |= (1LL << (seatNum - 1));
		}
		else if (query == 2)
		{
			cin >> seatNum;
			arr[trainNum] &= ~(1LL << (seatNum - 1));
		}
		else if (query == 3)
		{
			arr[trainNum] = arr[trainNum] << 1;
			arr[trainNum] &= ~(1LL << 20);
		}
		else
		{
			arr[trainNum] = arr[trainNum] >> 1;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		s.insert(arr[i]);
	}
	cout << s.size() << "\n";
	return 0;
}