#include <iostream>
#include <stack>
using namespace std;
string str;
stack<int> multiply;
stack<int> length;
int N;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;
	N = str.length();
	length.push(0);
	for (int i = 0; i < N; i++)
	{
		if (i != N-1 && str.at(i+1) == '(')
		{
			multiply.push(str.at(i)-48);
			length.push(0);
		}
		else if (str.at(i) >= 47 && str.at(i) <= 58)
		{
			int prevLength = length.top();
			length.pop();
			length.push(prevLength + 1);
		}
		else if (str.at(i) == ')')
		{
			int a = multiply.top();
			int b = length.top();
			multiply.pop();
			length.pop();
			if (!length.empty())
			{
				int prevLength = length.top();
				length.pop();
				length.push(prevLength + a * b);
			}
			else
			{
				length.push(a * b);
			}
		}
	}
	cout << length.top() << "\n";
	return 0;
}