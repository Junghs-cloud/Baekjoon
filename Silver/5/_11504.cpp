#include <iostream>
#include <string>
using namespace std;
int answer = 0;

void checkInRange(int X, int Y, string str)
{
	if (X <= stoi(str) && stoi(str) <= Y)
	{
		answer++;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		answer = 0;
		int N, M, num;
		cin >> N >> M;
		int X = 0;
		int Y = 0;
		for (int i = 0; i < M; i++)
		{
			cin >> num;
			X = X * 10 + num;
		}
		for (int i = 0; i < M; i++)
		{
			cin >> num;
			Y = Y * 10 + num;
		}
		char* wheel = new char[2 * N];
		for (int i = 0; i < N; i++)
		{
			cin >> wheel[i];
			wheel[N + i] = wheel[i];
		}
		string str = "";
		for (int i = 0; i < M; i++)
		{
			str += wheel[i];
		}
		checkInRange(X, Y, str);
		for (int i = 1; i < N; i++)
		{
			str = str.substr(1);
			str += wheel[i + M - 1];
			checkInRange(X, Y, str);
		}
		cout << answer << "\n";
	}
	return 0;
}