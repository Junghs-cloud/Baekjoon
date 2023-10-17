#include <iostream>
#include <vector>
#include <deque>
using namespace std;
long long** arr;


void moveAndMerge(deque<long long>& currentLine, vector<long long>& newLine)
{
	while (!currentLine.empty())
	{
		long long current = currentLine.front();
		if (currentLine.size() != 1)
		{
			currentLine.pop_front();
			long long next = currentLine.front();
			if (current == next)
			{
				currentLine.pop_front();
				newLine.push_back(current * 2);
			}
			else
			{
				newLine.push_back(current);
			}
		}
		else
		{
			currentLine.pop_front();
			newLine.push_back(current);
		}
	}
}

void printBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	arr = new long long*[8];
	char command;

	for (int i = 0; i < 8; i++)
	{
		arr[i] = new long long[8];
		for (int j = 0; j < 8; j++)
		{
			cin >> arr[i][j];
		}
	}
	cin >> command;
	if (command == 'U')
	{
		for (int i = 0; i < 8; i++)
		{
			deque<long long> currentLine;
			vector<long long> newLine;
			for (int j = 0; j < 8; j++)
			{
				if (arr[j][i] != 0)
				{
					currentLine.push_back(arr[j][i]);
				}
				arr[j][i] = 0;
			}
			moveAndMerge(currentLine, newLine);
			for (int j = 0; j < newLine.size(); j++)
			{
				arr[j][i] = newLine.at(j);
			}
		}
	}
	else if (command == 'L')
	{
		for (int i = 0; i < 8; i++)
		{
			deque<long long> currentLine;
			vector<long long> newLine;
			for (int j = 0; j < 8; j++)
			{
				if (arr[i][j] != 0)
				{
					currentLine.push_back(arr[i][j]);
				}
				arr[i][j] = 0;
			}
			moveAndMerge(currentLine, newLine);
			for (int j = 0; j < newLine.size(); j++)
			{
				arr[i][j] = newLine.at(j);
			}
		}
	}
	else if (command == 'D')
	{
		for (int i = 0; i < 8; i++)
		{
			deque<long long> currentLine;
			vector<long long> newLine;
			for (int j = 7; j >= 0; j--)
			{
				if (arr[j][i] != 0)
				{
					currentLine.push_back(arr[j][i]);
				}
				arr[j][i] = 0;
			}
			moveAndMerge(currentLine, newLine);
			for (int j = 0; j < newLine.size(); j++)
			{
				arr[7 -j][i] = newLine.at(j);
			}
		}
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			deque<long long> currentLine;
			vector<long long> newLine;
			for (int j = 7; j >= 0; j--)
			{
				if (arr[i][j] != 0)
				{
					currentLine.push_back(arr[i][j]);
				}
				arr[i][j] = 0;
			}
			moveAndMerge(currentLine, newLine);
			for (int j = 0; j < newLine.size(); j++)
			{
				arr[i][7 - j] = newLine.at(j);
			}
		}
	}

	printBoard();

	return 0;
}