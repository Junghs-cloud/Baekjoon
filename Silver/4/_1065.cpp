#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	bool* arr = new bool[1001];
	int answer = 0;
	for (int i = 0; i < 1001; i++)
	{
		arr[i] = true;
	}
	for (int i = 10; i < 1001; i++)
	{
		string str = to_string(i);
		int d = str[1] - str[0];
		for (int j = 2; j < str.length(); j++)
		{
			if (str[j] - str[j - 1] != d)
			{
				arr[i] = false;
				break;
			}
		}
	}
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		if (arr[i] == true)
		{
			answer++;
		}
	}
	cout << answer << "\n";
	return 0;
}