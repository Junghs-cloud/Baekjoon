#include <iostream>
using namespace std;
int N;
char* arr;
bool isFound;

void backTracking(int depth)
{
	if (depth == N)
	{
		for (int i = 0; i < N; i++)
		{
			cout << arr[i];
		}
		cout << "\n";
		isFound = true;
	}
	else
	{
		for (int i = 1; i <= 3; i++)
		{
			bool hasSameString = false;
			arr[depth] = i + 48;
			for (int length = 1; length <= ((depth+1) / 2); length++)
			{
				string str1 = "";
				string str2 = "";
				for (int j = 0; j < length; j++)
				{
					str1 += arr[depth-j];
				}
				for (int j = 0; j < length; j++)
				{
					str2 += arr[depth - length - j];
				}
				if (str1 == str2)
				{
					hasSameString = true;
					break;
				}
			}
			if (hasSameString == false && isFound == false)
			{
				backTracking(depth + 1);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	isFound = false;
	arr = new char[N];
	backTracking(0);
	return 0;
}