#include <iostream>
#include <string>
using namespace std;

string add(string str1, string str2)
{
	int N = str1.length();
	int M = str2.length();
	int counts = max(N, M);
	bool isOver = false;
	string answer = "";
	if (N < M)
	{
		for (int i = 0; i < (M - N); i++)
		{
			str1.insert(0, "0");
		}
	}
	else if (N > M)
	{
		for (int i = 0; i < (N - M); i++)
		{
			str2.insert(0, "0");
		}
	}
	for (int i = 0; i < counts; i++)
	{
		int a = str1.at(counts - 1 - i) - 48;
		int b = str2.at(counts - 1 - i) - 48;
		int temp = a + b;
		if (isOver)
		{
			temp++;
		}
		isOver = false;
		if (temp >= 10)
		{
			temp -= 10;
			isOver = true;
		}
		answer.insert(0, to_string(temp));
	}
	if (isOver == true)
	{
		answer.insert(0, "1");
	}
	return answer;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str1, str2;
	cin >> str1 >> str2;
	cout << add(str1, str2);
	return 0;
}