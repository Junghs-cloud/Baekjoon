#include <iostream>
#include <string>
using namespace std;

void add(string& str1, string& str2)
{
	if (str2.length() == 1)
	{
		str1 += "0" + str2;
	}
	else
	{
		str1 += str2;
	}
}

string convertString(int min, int sec)
{
	string str = "";
	string minStr = to_string(min);
	string secStr = to_string(sec);
	add(str, minStr);
	str += ":";
	add(str, secStr);
	return str;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, team;
	string str;
	cin >> N;
	int APoint = 0;
	int BPoint = 0;
	int ATime = 0;
	int BTime = 0;
	int prevTime = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> team >> str;
		int min = stoi(str.substr(0, 2));
		int sec = stoi(str.substr(3));
		int time = min * 60 + sec;
		if (APoint < BPoint)
		{
			BTime += time - prevTime;
		}
		else if (APoint > BPoint)
		{
			ATime += time - prevTime;
		}
		if (team == 1)
		{
			APoint++;
		}
		else
		{
			BPoint++;
		}
		prevTime = time;
	}
	int time = 2880;
	if (APoint < BPoint)
	{
		BTime += time - prevTime;
	}
	else if (APoint > BPoint)
	{
		ATime += time - prevTime;
	}
	cout <<convertString(ATime / 60, ATime % 60)<<"\n";
	cout << convertString(BTime / 60, BTime % 60)<<"\n";
	return 0;
}