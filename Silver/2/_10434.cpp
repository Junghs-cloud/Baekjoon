#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	int T;
	int testCaseNum;
	string numberString;
	stringstream ss;
	vector<int>:: iterator it;
	bool isPrime[10001];
	for (int i = 0; i < 10001; i++)
	{
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i < 101;i++)
	{
		for (int j = 2 * i; j < 10001; j+= i)
		{
			isPrime[j] = false;
		}
	}
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int initNum;
		int num;
		cin >> testCaseNum >> numberString;
		num = stoi(numberString);
		initNum = num;
		vector<int> v;
		if (isPrime[num] == false)
		{
			cout << testCaseNum << " " << numberString <<" "<< "NO" << "\n";
			continue;
		}
		int sum = 0;
		while (sum != 1)
		{
			sum = 0;
			for (int i = 0; i < (signed) numberString.length(); i++)
			{
				int digit = numberString[i] - 48;
				sum += (int) pow(digit, 2);
			}
			ss << sum;
			numberString = ss.str();
			ss.str("");
			it = find(v.begin(), v.end(), sum);
			if (it != v.end())
			{
				cout << testCaseNum << " " << initNum << " " << "NO" << "\n";
				break;
			}
			v.push_back(sum);
		}
		if (sum == 1)
		{
			cout << testCaseNum << " " << initNum << " " << "YES" << "\n";
		}
	}
	return 0;
}