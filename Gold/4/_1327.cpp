#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int num;
	bool isFound = false;
	cin >> N >> M;
	vector<int> v;
	vector<int> answerV;
	queue<pair<vector<int>, int>> notUsed;
	set<string> s;
	set<string>::iterator it;
	string str = "";
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
		answerV.push_back(i + 1);
		str += v.at(i)+48;
	}
	notUsed.push(make_pair(v, 0));
	s.insert(str);
	while (!notUsed.empty())
	{
		pair<vector<int>, int> current = notUsed.front();
		if (current.first == answerV)
		{
			cout << current.second << "\n";
			isFound = true;
			break;
		}
		vector<int> nextV = current.first;
		for (int i = 0; i < N - M + 1; i++)
		{
			nextV = current.first;
			str = "";
			reverse(nextV.begin() + i, nextV.begin() + i + M);
			for (int j = 0; j < N; j++)
			{
				str += nextV.at(j)+48;
			}
			it = s.find(str);
			if (it == s.end())
			{
				s.insert(str);
				notUsed.push(make_pair(nextV, current.second + 1));
			}
		}
		notUsed.pop();
	}
	if (isFound == false)
	{
		cout << "-1" << "\n";
	}
	return 0;
}