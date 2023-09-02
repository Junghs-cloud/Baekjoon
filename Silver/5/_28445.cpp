#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> parents;

int main()
{
	string fatherBody, fatherTail;
	string motherBody, motherTail;
	cin >> fatherBody >> fatherTail;
	cin >> motherBody >> motherTail;
	parents.push_back(fatherBody);
	if (fatherTail != fatherBody)
	{
		parents.push_back(fatherTail);
	}
	if (motherBody != fatherBody && motherBody != fatherTail)
	{
		parents.push_back(motherBody);
	}
	if (motherTail != fatherBody && motherTail != fatherTail && motherTail != motherBody)
	{
		parents.push_back(motherTail);
	}
	sort(parents.begin(), parents.end());
	for (int i = 0; i < parents.size(); i++)
	{
		for (int j = 0; j < parents.size(); j++)
		{
			cout << parents.at(i) << " " << parents.at(j)<<"\n";
		}
	}
	return 0;
}