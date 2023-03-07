#include <iostream>
#include <deque>
using namespace std;
deque<char> strings;
void print()
{
	for (int k = 0; k < (signed) strings.size(); k++)
	{
		cout << strings[k];
	}
	cout << "\n";
}

int main()
{
	deque<char> firstChars;
	int T;
	int N;
	char alphabet;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> alphabet;
			firstChars.push_back(alphabet);
			if (j == 0)
			{
				strings.push_back(firstChars.front());
				firstChars.pop_front();
			}
		}
		while (!firstChars.empty())
		{
			if (strings.front() < firstChars.front())
			{
				strings.push_back(firstChars.front());
			}
			else
			{
				strings.push_front(firstChars.front());
			}
			firstChars.pop_front();
		}
		print();
		strings.clear();
	}
	return 0;
}