#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	string str;
	int answer = 0;
	cin >> N >> K;
	cin >> str;
	int length = str.length();
	bool* isEat = new bool[length];
	for (int i = 0; i < length; i++)
	{
		if (str[i] == 'P')
		{
			isEat[i] = true;
		}
		else
		{
			isEat[i] = false;
		}
	}
	for (int i = 0; i < length; i++)
	{
		if (str[i] == 'P')
		{
			for (int j = max(i - K, 0) ; (j <= i + K) && (j< length); j++)
			{
				if (isEat[j] == false)
				{
					isEat[j] = true;
					answer++;
					break;
				}
			}
		}
	}
	cout << answer << "\n";
	return 0;
}