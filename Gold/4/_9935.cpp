#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int* arr;
stack<char> s;
stack<int> index;
stack<char> answerStack;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str, token;
	int currentIndex = 0;
	cin >> str;
	cin >> token;
	int N = (unsigned) str.length();
	int M = (unsigned) token.length();
	for (int i = 0; i < N; i++)
	{
		if (str[i] == token[currentIndex])
		{
			index.push(currentIndex);
			currentIndex++;
		}
		else
		{
			currentIndex = 0;
			if (str[i] == token[currentIndex])
			{
				index.push(currentIndex);
				currentIndex++;
			}
			else
			{
				index.push(-1);
			}
		}
		s.push(str[i]);
		if (currentIndex == M)
		{
			for (int j = 0; j < M; j++)
			{
				s.pop();
				index.pop();
			}
			if (index.empty())
			{
				currentIndex = 0;
			}
			else
			{
				currentIndex = index.top() + 1;
			}
		}
	}
	while (!s.empty())
	{
		answerStack.push(s.top());
		s.pop();
	}
	if (answerStack.empty())
	{
		cout << "FRULA" << "\n";
	}
	else
	{
		while (!answerStack.empty())
		{
			cout << answerStack.top();
			answerStack.pop();
		}
	}
	return 0;
}