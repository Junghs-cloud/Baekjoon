#include <iostream>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string name, enterOrLeave;
	cin >> N;
	set<string> s;
	set<string>::reverse_iterator it;
	for (int i = 0; i < N; i++)
	{
		cin >> name>>enterOrLeave;
		if (enterOrLeave == "enter")
		{
			s.insert(name);
		}
		else
		{
			s.erase(name);
		}
	}
	for (it = s.rbegin(); it != s.rend(); it++)
	{
		cout << *it << "\n";
	}
	return 0;
}