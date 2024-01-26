#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string str;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		int start = 0;
		int end = str.length() - 1;
		bool palindrome = true;
		while (start < end)
		{
			if (str[start] != str[end])
			{
				palindrome = false;
				break;
			}
			else
			{
				start++;
				end--;
			}
		}
		if (palindrome == true)
		{
			cout << 0 << "\n";
		}
		else
		{
			bool hasDiff = false;
			bool pseudoPalindrome = true;
			start = 0;
			end = str.length() - 1;
			while (start < end)
			{
				if (str[start] != str[end])
				{
					if (hasDiff == false)
					{
						hasDiff = true;
						start++;
					}
					else
					{
						pseudoPalindrome = false;
						break;
					}
				}
				else
				{
					start++;
					end--;
				}
			}
			if (pseudoPalindrome == true)
			{
				cout << 1 << "\n";
			}
			else
			{
				hasDiff = false;
				pseudoPalindrome = true;
				start = 0;
				end = str.length() - 1;
				while (start < end)
				{
					if (str[start] != str[end])
					{
						if (hasDiff == false)
						{
							hasDiff = true;
							end--;
						}
						else
						{
							pseudoPalindrome = false;
							break;
						}
					}
					else
					{
						start++;
						end--;
					}
				}
				if (pseudoPalindrome == true)
				{
					cout << 1 << "\n";
				}
				else
				{
					cout << 2 << "\n";
				}
			}
		}
	}
	return 0;
}