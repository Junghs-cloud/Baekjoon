#include <iostream>
#include <string>
using namespace std;

int main()
{
	bool found = false;
	int N;
	cin >> N;
	string str;
	string front;
	string back;
	cin >> str;
	for (int i = 1; i <= N; i++)
	{
		int diff = 0;
		front = str.substr(0, i);
		back = str.substr(str.length() - i);
		for (int j = 0; j < front.length(); j++)
		{
			if (front[j] != back[j])
			{
				diff++;
			}
		}
		if (diff == 1)
		{
			cout << "YES" << "\n";
			found = true;
			break;
		}
	}
	if (found == false)
	{
		cout << "NO" << "\n";
	}
	return 0;
}