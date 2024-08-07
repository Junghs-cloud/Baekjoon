#include <iostream>
using namespace std;

long long pow(int N)
{
	long long answer = 1;
	for (int i = 1; i <= N; i++)
	{
		answer *= 31;
		answer %= 1234567891;
	}
	return answer;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	string str;
	cin >> str;
	long long hashValue = 0;
	for (int i = 0; i < N; i++)
	{
		int Ai = str[i] - 97 + 1;
		hashValue += Ai * pow(i);
		hashValue %= 1234567891;
	}
	cout << hashValue << "\n";
	return 0;
}