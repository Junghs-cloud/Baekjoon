#include <iostream>
#include <regex>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	regex r("(100+1+|01)+");
	string str;
	cin >> str;
	if (regex_match(str, r))
	{
		cout << "SUBMARINE" << "\n";
	}
	else
	{
		cout << "NOISE" << "\n";
	}
	return 0;
}