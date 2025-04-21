#include <iostream>
#include <stack>
using namespace std;

double calcValue(double value1, double value2, char op)
{
	if (op == '+')
	{
		return value1 + value2;
	}
	if (op == '-')
	{
		return value1 - value2;
	}
	if (op == '*')
	{
		return value1 * value2;
	}
	return value1 / value2;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string str;
	stack<double> tempStack;
	cin >> N;
	int* num = new int[N];
	cin >> str;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '/')
		{
			double value2 = tempStack.top();
			tempStack.pop();
			double value1 = tempStack.top();
			tempStack.pop();
			tempStack.push(calcValue(value1, value2, str[i]));
		}
		else
		{
			int value = num[str[i] - 65];
			tempStack.push(value);
		}
	}
	cout<<fixed;
	cout.precision(2);
	cout << tempStack.top() << "\n";
	return 0;
}