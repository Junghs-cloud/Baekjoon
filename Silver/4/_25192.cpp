#include <iostream>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int answer = 0;
	string chatting;
	set<string> s;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> chatting;
		if (chatting == "ENTER")
		{
			s.clear();
		}
		else
		{
			if (s.find(chatting) == s.end())
			{
				s.insert(chatting);
				answer++;
			}
		}
	}
	cout << answer << "\n";
	return 0;
}