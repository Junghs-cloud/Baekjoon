#include <iostream>
using namespace std;
char** arr;
int N;
int maxLength = 0;

void swap(char current, char next)
{
	char temp = current;
	current = next;
	next = temp;
}

void searchRow()
{
	for (int i = 0; i < N; i++)
	{
		char temp = 0;
		int length = 0;
		int j = 0;
		for (j = 0; j < N; j++)
		{
			if (arr[i][j] != arr[i][temp])
			{
				length = j - temp;
				temp = j;
				if (length > maxLength)
				{
					maxLength = length;
				}
			}
		}
		length = j - temp;
		if (length > maxLength)
		{
			maxLength = length;
		}
	}
}

void searchColumn()
{
	for (int i = 0; i < N; i++)
	{
		char temp = 0;
		int length = 0;
		int j = 0;
		for (j = 0; j < N; j++)
		{
			if (arr[j][i] != arr[temp][i])
			{
				length = j - temp;
				temp = j;
				if (length > maxLength)
				{
					maxLength = length;
				}
			}
		}
		length = j - temp;
		if (length > maxLength)
		{
			maxLength = length;
		}
	}

}

int main()
{
	
	string str;
	cin >> N;
	arr = new char*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new char[N];
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = str[j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			char current = arr[i][j];
			char next = arr[i][j + 1];
			if (current != next)
			{
				char temp = current;
				arr[i][j] = next;
				arr[i][j + 1] = temp;
				searchRow();
				searchColumn();
				temp = arr[i][j];
				arr[i][j] = arr[i][j+1];
				arr[i][j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			char current = arr[j][i];
			char next = arr[j+1][i];
			if (current != next)
			{
				char temp = current;
				arr[j][i] = next;
				arr[j + 1][i] = temp;
				searchRow();
				searchColumn();
				temp = arr[j][i];
				arr[j][i] = arr[j + 1][i];
				arr[j + 1][i] = temp;
			}
		}
	}
	cout << maxLength << "\n";
	return 0;
}