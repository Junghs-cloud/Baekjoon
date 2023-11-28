#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(pair<int, int>& p1, pair<int, int>& p2)
{
	if (p1.second > p2.second)
	{
		return true;
	}
	else if (p1.second == p2.second)
	{
		return p1.first > p2.first;
	}
	else
	{
		return false;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int start, end;
	cin >> N;
	vector<pair<int, int>> v;
	vector<pair<int, int>> answerV;
	long long length = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}
	sort(v.begin(), v.end(), cmp);
	start = v.at(0).first;
	end = v.at(0).second;
	for (int i = 1; i < v.size(); i++)
	{
		if (v.at(i).second < start)
		{
			answerV.push_back(make_pair(start, end));
			start = v.at(i).first;
			end = v.at(i).second;
		}
		else if (v.at(i).first < start)
		{
			start = v.at(i).first;
		}
		else
		{
			continue;
		}
	}
	answerV.push_back(make_pair(start, end));
	for (int i = 0; i < answerV.size(); i++)
	{
		length += answerV.at(i).second - answerV.at(i).first;
	}
	cout << length << "\n";
	return 0;
}