#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> charStack;
string reverseStr;

void copyStringFromStack()
{
	if (!charStack.empty())
	{
		while (!charStack.empty())
		{
			reverseStr.append(1, charStack.top());
			charStack.pop();
		}
	}
}

int main()
{
	string str;
	getline(cin, str);
	bool isInTag = false;
	for (int i = 0; i < (signed) str.length(); i++)
	{
		if (str[i] == '<' || str[i]== '>' || str[i]== ' ')
		{
			copyStringFromStack();
			reverseStr.append(1, str[i]);
			if (str[i] == '<')
			{
				isInTag = true;
			}
			if (str[i] == '>')
			{
				isInTag = false;
			}
		}
		else
		{
			if (isInTag == false)
			{
				charStack.push(str[i]);
			}
			else
			{
				reverseStr.append(1, str[i]);
			}
		}
	}
	copyStringFromStack();
	cout << reverseStr << "\n";
	return 0;
}