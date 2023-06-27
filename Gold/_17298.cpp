#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int main()
{
	int N;
	int currentInput;
	vector<int> inputVector;
	stack<int> popedStack;
	stack<int> answerStack;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> currentInput;
		inputVector.push_back(currentInput);
	}
	for (int i = inputVector.size() - 1; i >= 0; i--)
	{
		int currentNum = inputVector.at(i);
		if (i == inputVector.size() - 1)
		{
			answerStack.push(-1);
			popedStack.push(currentNum);
		}
		else
		{
			while (!popedStack.empty())
			{
				if (currentNum < popedStack.top())
				{
					answerStack.push(popedStack.top());
					break;
				}
				else
				{
					popedStack.pop();
				}
			}
			if (popedStack.empty())
			{
				answerStack.push(-1);
			}
			popedStack.push(currentNum);
		}
	}
	while (!answerStack.empty())
	{
		cout << answerStack.top()<<" ";
		answerStack.pop();
	}
	cout << "\n";
	return 0;
}