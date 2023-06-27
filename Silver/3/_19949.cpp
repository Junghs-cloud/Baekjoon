#include <iostream>
using namespace std;
int* answer;
int* pr;
int caseCount = 0;
void dfs(int depth)
{
	if (depth == 10)
	{
		int correct = 0;
		for (int i = 0; i < 10; i++)
		{
			if (answer[i] == pr[i])
			{
				correct++;
			}
		}
		if (correct >= 5)
		{
			caseCount++;
		}
		return;
	}
	else
	{
		for (int i = 1; i <= 5; i++)
		{
			pr[depth] = i;
			if (depth >= 2)
			{
				if (pr[depth - 2] == pr[depth - 1] && pr[depth - 1] == pr[depth])
				{
					continue;
				}
			}
			dfs(depth + 1);
		}
	}
}

int main()
{
	answer = new int[10];
	pr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> answer[i];
	}
	dfs(0);
	cout << caseCount << "\n";
	return 0;
}