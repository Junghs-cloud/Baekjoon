#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int length = (signed) str.length();
	string* strArr = new string[length];
	for (int i = 0; i < length; i++)
	{
		strArr[i] = str.substr(i);
	}
	sort(strArr, strArr + length);
	for (int i = 0; i < length; i++)
	{
		cout << strArr[i] << "\n";
	}
	return 0;
}