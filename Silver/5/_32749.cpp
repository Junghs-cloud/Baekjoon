#include <iostream>
#include <string>
using namespace std;

int pow(int x)
{
	int answer = 2;
	for (int i = 1; i < x; i++)
	{
		answer *= 2;
	}
	return answer;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, T;
	string str;
	cin >> N >> T;
	cin >> str;
	int answerLength = str.length() / pow(T);
	string answer = "";
	for (int i = 0; i < str.length(); i += answerLength)
	{
		string current = str.substr(i, answerLength);
		if (current > answer)
		{
			answer = current;
		}
	}
	cout << answer << "\n";
	return 0;
}