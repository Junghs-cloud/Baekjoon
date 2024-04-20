#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, groupMembers, query;
	string groupName, personName, queryContent;
	cin >> N >> M;
	map<string, string> memberToGroup;
	map<string, set<string>> groupToMember;
	for (int i = 0; i < N; i++)
	{
		cin >> groupName;
		cin >> groupMembers;
		set<string> temp;
		for (int j = 0; j < groupMembers; j++)
		{
			cin >> personName;
			memberToGroup.insert({ personName, groupName });
			temp.insert(personName);
		}
		groupToMember.insert({ groupName, temp });
	}
	for (int i = 0; i < M; i++)
	{
		cin >> queryContent;
		cin >> query;
		if (query == 0)
		{
			set<string> members=groupToMember.find(queryContent)->second;
			for (set<string>::iterator it = members.begin(); it != members.end(); it++)
			{
				cout << *it << "\n";
			}
		}
		else
		{
			cout << memberToGroup.find(queryContent)->second << "\n";
		}
	}
	return 0;
}