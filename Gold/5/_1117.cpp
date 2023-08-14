#include <iostream>
using namespace std;

int main()
{
	long long W, H, f, c, x1, x2, y1, y2;
	cin >> W >> H>>f>>c>>x1>>y1>>x2>>y2;
	long long remakeW=0;
	long long duplicatedLine = 0;
	if (f > W / 2)
	{
		remakeW = f;
		duplicatedLine = W - f;
	}
	else
	{
		remakeW = W - f;
		duplicatedLine = f;
	}
	long long updownCount = c + 1;
	long long remakeH =H / (c + 1);
	long long paintedArea = (x2 - x1) * (y2 - y1);
	long long duplicatedArea = 0;
	if (x1 < duplicatedLine)
	{
		if (x2 <= duplicatedLine)
		{
			duplicatedArea = (y2 - y1) * (x2 - x1);
		}
		else
		{
			duplicatedArea = (y2 - y1) * (duplicatedLine - x1);
		}
	}
	cout << (W*H) - (paintedArea * updownCount)- (duplicatedArea*updownCount);
	return 0;
}