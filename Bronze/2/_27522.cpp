#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct record
{
	string min;
	string sec;
	string miliSec;
	string team;
	record(string a, string b, string c, string d)
	{
		min = a;
		sec = b;
		miliSec = c;
		team = d;
	}
};

bool compare(const record& r1, const record& r2)
{
	if (r1.min < r2.min)
	{
		return true;
	}
	else if (r1.min == r2.min)
	{
		if (r1.sec < r2.sec)
		{
			return true;
		}
		else if (r1.sec == r2.sec)
		{
			return r1.miliSec < r2.miliSec;
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
	string str;
	string token;
	string min, sec, mm, team;
	vector<record> rank;
	int redTeam = 0;
	int blueTeam = 0;
	int pointBoard[8];
	pointBoard[0] = 10;
	pointBoard[1] = 8;
	pointBoard[2] = 6;
	for (int i = 3; i < 8; i++)
	{
		pointBoard[i] = pointBoard[i-1]- 1;
	}
	for (int i = 1; i <= 8; i++)
	{
		getline(cin, str);
		istringstream ss(str);
		getline(ss, token, ':');
		min = token;
		getline(ss, token, ':');
		sec = token;
		getline(ss, token, ' ');
		mm = token;
		getline(ss, token, ' ');
		team = token;
		rank.push_back(record(min, sec, mm, team));
	}
	sort(rank.begin(), rank.end(), compare);
	for (int i = 0; i < 8; i++)
	{
		if (rank.at(i).team == "R")
		{
			redTeam += pointBoard[i];
		}
		else
		{
			blueTeam += pointBoard[i];
		}
	}
	if (redTeam > blueTeam)
	{
		cout << "Red"<<"\n";
	}
	else if (redTeam< blueTeam)
	{
		cout << "Blue" << "\n";
	}
	else
	{
		string first = rank.at(0).team;
		if (first == "R")
		{
			cout << "Red" << "\n";
		}
		else
		{
			cout << "Blue" << "\n";
		}
	}
	return 0;
}