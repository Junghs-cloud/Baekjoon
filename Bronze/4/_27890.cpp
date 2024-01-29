#include <iostream>
using namespace std;

int main()
{
	int height;
	int currentSecond = 1;
	int wantSecond;
	cin >> height>> wantSecond;
	while (currentSecond <= wantSecond)
	{
		if (height % 2 == 0)
		{
			height = (height / 2) ^ 6;
		}
		else
		{
			height = (2 * height) ^ 6;
		}
		currentSecond++;
	}
	cout << height << "\n";
	return 0;
}