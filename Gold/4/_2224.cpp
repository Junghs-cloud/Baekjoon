#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string str;
	cin >> N;
	cin.ignore();
	bool** arr = new bool*[52];
	for (int i = 0; i < 52; i++)
	{
		arr[i] = new bool[52];
		for (int j = 0; j < 52; j++)
		{
			arr[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++)
	{
		getline(cin, str);
		char P = str[0];
		char Q = str[5];
		if (P >= 65 && P < 97)
		{
			if (Q >= 65 && Q < 97)
			{
				arr[P - 65][Q-65] = true;
			}
			else
			{
				arr[P - 65][Q - 97+26] = true;
			}
		}
		else
		{
			if (Q >= 65 && Q < 97)
			{
				arr[P - 97+26][Q - 65] = true;
			}
			else
			{
				arr[P - 97+26][Q - 97+26] = true;
			}
		}
	}
	for (int k = 0; k < 52; k++)
	{
		for (int i = 0; i < 52; i++)
		{
			for (int j = 0; j < 52; j++)
			{
				if (arr[i][k] == true && arr[k][j] == true)
				{
					arr[i][j] = true;
				}
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < 52; i++)
	{
		for (int j = 0; j < 52; j++)
		{
			if (i == j)
			{
				arr[i][j] = false;
			}
			if (arr[i][j] == true)
			{
				answer++;
			}
		}
	}
	cout << answer << "\n";
	for (int i = 0; i < 52; i++)
	{
		for (int j = 0; j < 52; j++)
		{
			if (arr[i][j] == true)
			{
				if (i< 26 && j< 26)
				{
					cout << char(65 + i)<<" => "<<char(65 + j)<<"\n";
				}
				else if (i < 26 && j >= 26)
				{
					cout << char(65 + i) << " => " << char(71 + j) << "\n";
				}
				else if (i >=26 && j <26)
				{
					cout << char(71 + i) << " => " << char(65 + j) << "\n";
				}
				else
				{
					cout << char(71 + i) << " => " << char(71 + j) << "\n";
				}
			}

		}
	}
	return 0;
}