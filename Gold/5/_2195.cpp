#include <iostream>
#include <string>
using namespace std;

int main()
{
	string S, P;
	cin >> S >> P;
	string str = "";
	int answer = 0;
	for (int i = 0; i < P.length(); i++)
	{
		str += P[i];
		if (S.find(str) == string::npos)
		{
			answer++;
			str = P[i];
		}
	}
	answer++;
	cout << answer << "\n";
	return 0;
}