#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

void reverseString(string& s)
{
	reverse(s.begin(), s.end());
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	set<string> strings;
	cin >> str;
	int N = str.length();
	for (int i = 1; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			string first = str.substr(0, i);
			string second = str.substr(i, j - i);
			string third = str.substr(j);
			reverseString(first);
			reverseString(second);
			reverseString(third);
			string newWord = first + second + third;
			strings.insert(newWord);
		}
	}
	cout << *strings.begin() << "\n";
	return 0;
}