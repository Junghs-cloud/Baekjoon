#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, query, num;
	int answer = 0;
	cin >> N >> M;
	bool* isDirty = new bool[N+1];
	for (int i = 1; i < N+1; i++)
	{
		cin >> num;
		if (num == 0)
		{
			isDirty[i] = false;
		}
		else
		{
			isDirty[i] = true;
			if (i == 1 || isDirty[i - 1] == false)
			{
				answer++;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> query;
		if (query == 0)
		{
			cout << answer << "\n";
		}
		else
		{
			cin >> num;
			if (isDirty[num] == true)
			{
				continue;
			}
			isDirty[num] = true;
			if (num == 1 && isDirty[2] == false)
			{
				answer++;
			}
			else if (num == N&& isDirty[N - 1] == false)
			{
				answer++;
			}
			else
			{
				if (isDirty[num - 1] == true && isDirty[num + 1] == true)
				{
					answer--;
				}
				else if (isDirty[num - 1] == false && isDirty[num + 1] == false)
				{
					answer++;
				}
			}
		}
	}
	return 0;
}