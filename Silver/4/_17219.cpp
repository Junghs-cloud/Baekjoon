#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	map<string, string> passwords;
	int N, M;
	string name, pw;
	string siteName;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> name >> pw;
		passwords.insert({ name, pw });
	}
	for (int j = 0; j < M; j++)
	{
		cin >> siteName;
		map<string, string>::iterator password = passwords.find(siteName);
		cout << password->second<<"\n";
	}
	return 0;
}