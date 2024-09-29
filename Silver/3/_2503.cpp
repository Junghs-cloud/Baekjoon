#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool* digits;

struct question
{
	string number;
	int strike;
	int ball;
	question(string a, int b, int c)
	{
		number = a;
		strike = b;
		ball = c;
	}
};
vector<question> q;
int answer = 0;

void find(int depth, string possibleAnswer)
{
	if (depth == 3)
	{
		for (int i = 0; i < q.size(); i++)
		{
			int strike = 0;
			int ball = 0;
			for (int j = 0; j < 3; j++)
			{
				for (int k =0; k < 3; k++)
				{
					if (j == k && possibleAnswer[j] == q.at(i).number[k])
					{
						strike++;
					}
					else if (j!=k && possibleAnswer[j] == q.at(i).number[k])
					{
						ball++;
					}
				}
			}
			if (strike != q.at(i).strike || ball != q.at(i).ball)
			{
				return;
			}
		}
		answer++;
		return;
	}
	else
	{
		for (int i = 1; i < 10; i++)
		{
			int nextNum = stoi(possibleAnswer);
			if (digits[i] == false)
			{
				nextNum = nextNum * 10 + i;
				digits[i] = true;
				find(depth + 1, to_string(nextNum));
				digits[i] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int strike, ball;
	string number;
	digits= new bool[10];
	for (int i = 0; i < 10; i++)
	{
		digits[i] = false;
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> number >> strike >> ball;
		q.push_back(question(number, strike, ball));
	}
	find(0, "0");
	cout << answer << "\n";
	return 0;
}