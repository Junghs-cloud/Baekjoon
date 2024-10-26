#include <iostream>
using namespace std;
bool* isBroken;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, B, num;
	cin >> N >> M >> B;
	int answer = 0;
	isBroken = new bool[N+1];
	for (int i = 0; i < N+1; i++)
	{
		isBroken[i] = false;
	}
	for (int i = 0; i < B; i++)
	{
		cin >> num;
		isBroken[num] = true;
	}
	for (int i = 1; i <= M; i++)
	{
		if (isBroken[i] == true)
		{
			answer++;
		}
	}
	int tempAnswer = answer;
	for (int i = M + 1; i <= N; i++)
	{
		if (isBroken[i - M] == true)
		{
			tempAnswer--;
		}
		if (isBroken[i] == true)
		{
			tempAnswer++;
		}
		answer = min(answer, tempAnswer);
	}
	cout << answer << "\n";
	return 0;
}