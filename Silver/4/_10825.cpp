#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student
{
	string name;
	int kor;
	int eng;
	int math;
	student(string a, int b, int c, int d)
	{
		name = a;
		kor = b;
		eng = c;
		math = d;
	}
};

bool cmp(student& s1, student& s2)
{
	if (s1.kor > s2.kor)
	{
		return true;
	}
	else if (s1.kor==s2.kor)
	{
		if (s1.eng < s2.eng)
		{
			return true;
		}
		else if (s1.eng == s2.eng)
		{
			if (s1.math > s2.math)
			{
				return true;
			}
			else if (s1.math == s2.math)
			{
				return s1.name < s2.name;
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
	return false;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	string name;
	int k, e, m;
	cin >> N;
	vector<student> v;
	for (int i = 0; i < N; i++)
	{
		cin >> name >> k >> e >> m;
		v.push_back(student(name, k, e, m));
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i).name << "\n";
	}
	return 0;
}