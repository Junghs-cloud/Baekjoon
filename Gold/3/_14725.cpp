#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct trie
{
	map<string, trie*> childs;

	void insert(vector<string> v, int index)
	{
		map<string, trie*>::iterator it;
		if (index >= v.size())
		{
			return;
		}
		it = childs.find(v.at(index));
		if (it == childs.end())
		{
			trie* childNode = new trie();
			childs.insert({ v.at(index), childNode });
			childNode->insert(v, ++index);
		}
		else
		{
			it->second->insert(v, ++index);
		}
	}

	void dfs(int depth)
	{
		map<string, trie*>::iterator it;
		for (it = childs.begin(); it != childs.end(); it++)
		{
			for (int i = 0; i < depth; i++)
			{
				cout << "--";
			}
			cout << it->first << "\n";
			it->second->dfs(depth+1);
		}
	}
};


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	trie* root = new trie();
	int N, K;
	string str;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> K;
		vector<string> food;
		for (int j = 0; j < K; j++)
		{
			cin >> str;
			food.push_back(str);
		}
		root->insert(food, 0);
	}
	root->dfs(0);
	return 0;
}