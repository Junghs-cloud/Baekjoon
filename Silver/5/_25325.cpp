#include <iostream>
#include <utility>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string str, token;
	cin >> N;
	pair<int, string>* students = new pair<int, string>[N];
	map<string, int> index;
	map<string, int>::iterator it;
	for (int i = 0; i < N; i++)
	{
		cin >> students[i].second;
		students[i].first = 0;
		index.insert({ students[i].second, i });
	}
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		getline(cin, str);
		stringstream ss(str);
		while (ss >> token)
		{
			it = index.find(token);
			students[it->second].first--;
		}
	}
	sort(students, students + N);
	for (int i = 0; i < N; i++)
	{
		cout << students[i].second <<" "  <<- students[i].first << "\n";
	}
	return 0;
}