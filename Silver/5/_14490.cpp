#include <iostream>
#include <string>
using namespace std;

int getGCD(int x, int y)
{
	if (y == 0)
	{
		return x;
	}
	else
	{
		return getGCD(y, x % y);
	}
}

int main()
{
	string str;
	cin >> str;
	int index = str.find(":");
	int N = stoi(str.substr(0, index));
	int M = stoi(str.substr(index + 1));
	int gcd = getGCD(N, M);
	cout << N / gcd << ":" << M / gcd << "\n";
	return 0;
}