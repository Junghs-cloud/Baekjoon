#include <iostream>
#include <vector>
#include <climits>

using namespace std;
bool* hasParen;
string str;
int* operands;
int answer;

int calc(int prev, int current, char op)
{
	if (op == '+')
	{
		return prev + current;
	}
	if (op == '-')
	{
		return prev - current;
	}
	return prev * current;
}

void backTracking(int depth, int operatorSize)
{
	if (depth == operatorSize)
	{
		vector<int> v;
		int currentResult = calc(str.at(0)-48, str.at(2)-48, str.at(1));
		v.push_back(str.at(0) - 48);
		v.push_back(currentResult);
		for (int i=1;i<operatorSize;i++)
		{
			int originalOperatorIndex = i * 2 + 1;
			if (hasParen[i] == true)
			{
				int prev = str.at(originalOperatorIndex - 1) - 48;
				int current = str.at(originalOperatorIndex + 1) - 48;
				int currentResult = calc(prev, current, str.at(originalOperatorIndex));
				int calcResult = calc(v.at(v.size() - 2), currentResult, str.at(originalOperatorIndex - 2));
				v.push_back(calcResult);
			}
			else
			{
				int calcResult = calc(v.at(v.size() - 1), str.at(originalOperatorIndex + 1) - 48, str.at(originalOperatorIndex));
				v.push_back(calcResult);
			}
		}
		answer = max(answer, v.back());
	}
	else
	{
		if (depth==0 || (depth != 0 && hasParen[depth - 1] == false))
		{
			hasParen[depth] = true;
			backTracking(depth + 1, operatorSize);
		}
		hasParen[depth] = false;
		backTracking(depth + 1, operatorSize);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	cin >> str;
	if (N == 1)
	{
		cout << str << "\n";
	}
	else
	{
		int operandSIze = (N + 1) / 2;
		int operatorSize = N - operandSIze;
		hasParen = new bool[operatorSize];
		for (int i = 0; i < operatorSize; i++)
		{
			hasParen[i] = false;
		}
		answer = INT_MIN;
		backTracking(0, operatorSize);
		cout << answer << "\n";
	}
	return 0;
}