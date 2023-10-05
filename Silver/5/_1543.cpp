#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str, findWord;
	getline(cin, str);
	getline(cin, findWord);
	int answer = 0;
	int findWordLength = findWord.length();
	while (str.find(findWord) != string::npos)
	{
		answer++;
		int nextIndex = str.find(findWord) + findWordLength;
		str = str.substr(nextIndex);
	}
	cout << answer << "\n";
	return 0;
}