#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string str;
	int x;
	cin >> N;
	int s[21];
	for (int i = 0; i < 21; i++)
	{
		s[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str == "add")
		{
			cin >> x;
			s[x] = 1;
		}
		else if (str == "remove")
		{
			cin >> x;
			s[x]= 0;
		}
		else if (str == "check")
		{
			cin >> x;
			cout << s[x] << "\n";
		}
		else if (str == "toggle")
		{
			cin >> x;
			s[x] = (s[x] ^ 1);
		}
		else if (str == "all")
		{
			for (int i = 1; i < 21; i++)
			{
				s[i] = 1;
			}
		}
		else
		{
			for (int i = 1; i < 21; i++)
			{
				s[i] = 0;
			}
		}
	}
	return 0;
}