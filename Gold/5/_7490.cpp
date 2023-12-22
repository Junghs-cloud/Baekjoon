#include <iostream>
using namespace std;
char* c;
int N;
void backTracking(int depth)
{
	if (depth == N-1)
	{
		char current=c[0];
		int prevNum, answer;
		if (current == ' ')
		{
			prevNum = 12;
			answer = 0;
		}
		else
		{
			prevNum = 2;
			answer = 1;
		}
		for (int i = 1; i < N-1; i++)
		{
			if (c[i] == '+' || c[i]=='-')
			{
				if (current == '+')
				{
					answer +=prevNum;
				}
				else if (current == '-')
				{
					answer -= prevNum;
				}
				else
				{
					answer = prevNum;
				}
				current = c[i];
				prevNum = (i + 2);
			}
			else
			{
				prevNum = prevNum * 10 + (i + 2);
			}
		}
		if (current == '+')
		{
			answer += prevNum;
		}
		else
		{
			answer -= prevNum;
		}
		if (answer == 0)
		{
			for (int i = 0; i < N - 1; i++)
			{
				cout << i + 1 << c[i];
			}
			cout << N << "\n";
		}
		return;
	}
	else
	{
		c[depth] = ' ';
		backTracking(depth + 1);
		c[depth] = '+';
		backTracking(depth + 1);
		c[depth] = '-';
		backTracking(depth + 1);
	}

}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		c = new char[N - 1];
		backTracking(0);
		cout << "\n";
	}
	return 0;
}