#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct domino
{
	int pos;
	int length;
	domino(int a, int b)
	{
		pos = a;
		length = b;
	}
};

bool compare(const domino& d1, const domino& d2)
{
	if (d1.pos < d2.pos)
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
	int dominoCount = 0;
	int N;
	int a, l;
	vector<domino> v;
	bool isContinuous = false;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> l;
		v.push_back(domino(a, l));
	}
	sort(v.begin(), v.end(), compare);
	int i = 0;
	while (true)
	{
		int currentDominoPos = v.at(i).pos;
		int currentDominoLength = v.at(i).length;
		if (isContinuous == false)
		{
			dominoCount++;
		}
		if (i >= N-1)
		{
			break;
		}
		else
		{
			if (v.at(i + 1).pos <= currentDominoPos + currentDominoLength)
			{
				isContinuous = true;
			}
			else
			{
				isContinuous = false;
			}
			i++;
		}
		
	}
	cout << dominoCount << "\n";
	return 0;
}