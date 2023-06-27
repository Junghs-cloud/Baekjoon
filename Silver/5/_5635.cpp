#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct person
{
	string name;
	int day;
	int month;
	int year;
	person(string a, int b, int c, int d)
	{
		name = a;
		day = b;
		month = c;
		year = d;
	}
};

bool compare(const person& p1, const person& p2)
{
	if (p1.year < p2.year)
	{
		return true;
	}
	else if (p1.year == p2.year)
	{
		if (p1.month < p2.month)
		{
			return true;

		}
		else if (p1.month == p2.month)
		{
			if (p1.day < p2.day)
			{
				return true;
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
	else
	{
		return false;
	}
}

int main()
{
	int N;
	vector<person> people;
	string name;
	int day;
	int month;
	int year;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> name >> day >> month >> year;
		people.push_back(person(name, day, month, year));
	}
	sort(people.begin(), people.end(), compare);
	cout << people.at(people.size() - 1).name << "\n";
	cout << people.at(0).name << "\n";
	return 0;
}