#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string token;
	int count = 0;
	cin >> token;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		str += str;
		int index = str.find(token);
		if (index != string::npos)
		{
			count++;
		}
	}
	cout << count << "\n";
	return 0;
}