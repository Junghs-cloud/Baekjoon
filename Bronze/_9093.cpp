#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	int N;
	string str;
	string token;
	stack<char> charStack;
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		getline(cin, str);
		istringstream ss(str);
		while (getline(ss, token, ' '))
		{
			for (int i = 0; i < (signed) token.length(); i++)
			{
				charStack.push(token[i]);
			}
			while (!charStack.empty())
			{
				cout << charStack.top();
				charStack.pop();
			}
			cout << " ";
		}
		cout << "\n";
	}
	return 0;
}