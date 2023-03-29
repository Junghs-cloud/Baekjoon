#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct person
{
	int document;
	int interview;
	person(int a, int b)
	{
		document = a;
		interview = b;
	}
};

bool compare(const person& p1, const person& p2)
{
	if (p1.document < p2.document)
	{
		return true;
	}
	else if (p1.document == p2.document)
	{
		return p1.interview > p2.interview;
	}
	else
	{
		return false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	int N;
	int currentDocScore;
	int currentInterviewScore;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		vector<person> people;
		int peopleCount = 1;
		for (int j = 0; j < N; j++)
		{
			cin >> currentDocScore >> currentInterviewScore;
			people.push_back(person(currentDocScore, currentInterviewScore));
		}
		sort(people.begin(), people.end(), compare);
		int minInterviewScore = people.at(0).interview;
		for (int i = 1; i < (signed) people.size(); i++)
		{
			if (minInterviewScore >= people.at(i).interview)
			{
				minInterviewScore = people.at(i).interview;
				peopleCount++;
			}
		}
		cout << peopleCount<<"\n";
		peopleCount = 0;
	}
	return 0;
}