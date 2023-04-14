#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k;

struct record
{
	int teamNum;
	int* quiz = new int[k];
	int submitCount = 0;
	int lastSubmit= 0;
	record(int team, int submit, int last)
	{
		teamNum = team;
		submitCount = submit;
		lastSubmit = last;
	}
};

bool compare(record& r1, record r2)
{
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < k; i++)
	{
		sum1 += r1.quiz[i];
		sum2 += r2.quiz[i];
	}
	if (sum1 > sum2)
	{
		return true;
	}
	else if (sum1 == sum2)
	{
		if (r1.submitCount < r2.submitCount)
		{
			return true;
		}
		else if (r1.submitCount == r2.submitCount)
		{
			return r1.lastSubmit < r2.lastSubmit;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

int main()
{
	int T;
	int n, t, m;
	int team, quizNum, score;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		vector<record> v;
		cin >> n >> k >> t >> m;
		for (int i = 0; i < n; i++)
		{
			v.push_back(record(i + 1, 0, 0));
			for (int j = 0; j < k; j++)
			{
				v.at(i).quiz[j] = 0;
			}
		}
		for (int i = 1; i <= m; i++)
		{
			cin >> team >> quizNum >> score;
			if (v.at(team - 1).quiz[quizNum - 1] < score)
			{
				v.at(team - 1).quiz[quizNum - 1] = score;
			}
			v.at(team - 1).submitCount++;
			v.at(team - 1).lastSubmit = i;
		}
		sort(v.begin(), v.end(), compare);
		for (int i = 0; i < n; i++)
		{
			if (v.at(i).teamNum == t)
			{
				cout << i + 1 << "\n";
			}
		}
	}
	return 0;
}