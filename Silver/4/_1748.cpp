#include <iostream>
#include <string>
using namespace std;

long long pow(int N)
{
	if (N == 0)
	{
		return 1;
	}
	long long answer = 10;
	for (int i = 1; i < N; i++)
	{
		answer *= 10;
	}
	return answer;
}

long long get(int N)
{
	string s = to_string(N);
	int sLength = s.length();
	long long count = 0;
	for (int i = 1; i < sLength; i++)
	{
		count += i * (pow(i) - pow(i-1));
	}
	count += sLength * (N - pow(sLength-1) + 1);
	return count;
}

int main()
{
	int N;
	cin >> N;
	cout << get(N);
	return 0;
}