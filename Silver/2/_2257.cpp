#include <iostream>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;
	stack<char> alphabets;
	stack<int> numbers;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ')')
		{
			int sum = 0;
			while (alphabets.top() != '(')
			{
				sum += numbers.top();
				numbers.pop();
				alphabets.pop();
			}
			alphabets.pop();
			alphabets.push('X');
			numbers.push(sum);
		}
		else if (str[i] >= 48 && str[i] <= 57)
		{
			int num = numbers.top();
			numbers.pop();
			num *= str[i] - 48;
			numbers.push(num);
		}
		else
		{
			alphabets.push(str[i]);
			if (alphabets.top() == 'C')
			{
				numbers.push(12);
			}
			else if (alphabets.top() == 'O')
			{
				numbers.push(16);
			}
			else if (alphabets.top() == 'H')
			{
				numbers.push(1);
			}
		}
	}
	int sum = numbers.top();
	numbers.pop();
	while (!numbers.empty())
	{
		sum += numbers.top();
		numbers.pop();
	}
	cout <<sum<< "\n";
	return 0;
}