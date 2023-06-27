#include <iostream>
#include <list>
#include <cmath>
using namespace std;

list<long long>* v = new list<long long>[11];
list<long long>::iterator it;
int numCount = -1;
int N;
bool isFound = false;

void countNum(int num)
{
	for (it = v[num-1].begin(); it !=v[num-1].end(); it++)
	{
		long long prevNum = *it;
		long long lastNum = prevNum % 10;
		for (int j = 0; j <= lastNum-1; j++)
		{
			long long firstNum = prevNum * 10;
			v[num].push_back(firstNum + j);
			numCount++;
			if (numCount == N)
			{
				isFound = true;
				cout << firstNum + j << "\n";
				break;
			}
			if (((long long)firstNum + (long long)j) == 9876543210)
			{
				isFound = true;
				cout << -1 << "\n";
				break;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> N;

	if (N <= 9)
	{
		cout << N<<"\n";
		isFound = true;
		return 0;
	}
	for (int i = 0; i < 10; i++)
	{
		v[1].push_back(i);
		numCount++;
	}
	for (it = v[1].begin(); it!=v[1].end(); it++)
	{
		long long prevNum = *it;
		for (int j = 0; j <= prevNum-1; j++)
		{
			long long firstNum = prevNum * 10;
			v[2].push_back(firstNum+j);
			numCount++;
			if (numCount == N)
			{
				isFound = true;
				cout << firstNum + j<<"\n";
				return 0;
			}
		}
	}
	for (int i = 3; i <= 10; i++)
	{
		if (isFound == true)
		{
			break;
		}
		countNum(i);
	}
	if (isFound == false)
	{
		cout << -1 << "\n";
	}
	return 0;
}