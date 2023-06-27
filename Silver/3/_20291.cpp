#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct dict
{
	string extentionName;
	int count;
	dict(string name, int num)
	{
		extentionName = name;
		count = num;
	}
};

struct findName
{
	string name;

	findName(string s)
	{
		name = s;
	}
	bool operator()(const dict e1) const
	{
		return (name == e1.extentionName);
	}
};

vector<string> extentionVector;
vector<dict> v;

bool compare(const string& e1, const string& e2)
{
	if (e1 < e2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int N;
	string fileName;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> fileName;
		int point = fileName.find('.');
		string extention = fileName.substr(point + 1);
		extentionVector.push_back(extention);
	}
	sort(extentionVector.begin(), extentionVector.end(), compare);

	string prevString = extentionVector.at(0);
	int count = 1;
	for (int j = 1; j < (signed) extentionVector.size(); j++)
	{
		prevString = extentionVector.at(j - 1);
		if (prevString == extentionVector.at(j))
		{
			count++;
		}
		else
		{
			v.push_back(dict(prevString, count));
			count = 1;
		}
	}
	v.push_back(dict(extentionVector.at(extentionVector.size() - 1), count));

	for (int i = 0; i < (signed) v.size(); i++)
	{
		cout << v.at(i).extentionName << " " << v.at(i).count << "\n";
	}
	return 0;
}