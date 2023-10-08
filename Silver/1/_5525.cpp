#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int j = 0;
	cin >> N;
	cin >> M;
	string str;
	int* PI = new int[2*N+1];
	char* P = new char[2 * N + 1];
	PI[0] = 0;
	for (int i = 0; i < 2*N+1; i++)
	{
		if (i % 2 == 0)
		{
			P[i] = 'I';
		}
		else
		{
			P[i] = 'O';
		}
	}
	cin >> str;
	for (int i = 0; i < 2 * N + 1; i++)
	{
		PI[i] = 0;
	}
	for (int i = 1; i < 2 * N + 1; i++)
	{
		while (j > 0 && P[i] != P[j])
		{
			j = PI[j - 1];
		}
		if (P[i] == P[j])
		{
			PI[i] = ++j;
		}
	}
	int answer = 0;
	j = 0;
	for (int i = 0; i < M; i++)
	{
		while (j > 0 && str[i] != P[j])
		{
			j = PI[j - 1];
		}
		if (str[i] == P[j])
		{
			if (j == 2 * N)
			{
				j = PI[j];
				answer++;
			}
			else
			{
				j++;
			}
		}
	}
	cout << answer << "\n";
	return 0;
}