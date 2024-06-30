#include <iostream>
#include <regex>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string str;
	regex r("[A, B, C, D, E, F]?A+F+C+[A, B, C, D, E, F]?");
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (regex_match(str, r) == true)
		{
			cout << "Infected!"<<"\n";
		}
		else
		{
			cout << "Good"<<"\n";
		}
	}
	return 0;
}