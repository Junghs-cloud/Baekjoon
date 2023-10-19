#include <iostream>
using namespace std;
bool onWay;
bool consistency;

struct trie
{
	trie* childNode[10];
	bool isEnd;
	trie()
	{
		isEnd = false;
		for (int i = 0; i < 10; i++)
		{
			childNode[i] = NULL;
		}
	}

	void insertString(string str)
	{
		if (str == "\0")
		{
			isEnd = true;
			if (onWay == true)
			{
				consistency = false;
			}
			return;
		}
		if (isEnd == true)
		{
			consistency = false;
		}
		int index = str[0] - 48;
		if (childNode[index] == NULL)
		{
			childNode[index] =new trie();
			onWay = false;
		}
		childNode[index]->insertString(str.substr(1));
	}

	bool findStr(string str)
	{
		if (str == "\0")
		{
			if (isEnd == true)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		int index = str[0] - 48;
		if (childNode[index] == NULL)
		{
			return false;
		}
		else
		{
			return childNode[index] -> findStr(str.substr(1));
		}
	}
};



int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T, N;
	string str;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		trie root = trie();
		consistency = true;
		for (int i = 0; i < N; i++)
		{
			onWay = true;
			cin >> str;
			if (consistency == true)
			{
				root.insertString(str);
			}
		}
		if (consistency == true)
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}
	return 0;
}