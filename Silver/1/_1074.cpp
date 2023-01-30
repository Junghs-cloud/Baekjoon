#include <iostream>
#include <cmath>

using namespace std;
long int visitCount = 0;
int r, c;

void visit(int startX, int startY, long int arrayLength)
{
	long int nextLength = arrayLength / 2;
	if (nextLength == 1)
	{
		if (r == startX)
		{
			if (c == startY + 1)
			{
				visitCount++;
			}
		}
		else if (r == startX + 1)
		{
			visitCount += 2;
			if (c == startY + 1)
			{
				visitCount++;
			}
		}
		return;
	}
	else
	{
		if (r < startX + nextLength)
		{
			if (c < startY + nextLength)
			{
				visit(startX, startY, nextLength);
			}
			else
			{
				visitCount += nextLength * nextLength;
				visit(startX, startY + nextLength, nextLength);
			}

		}
		else
		{
			if (c < startY + nextLength)
			{
				visitCount += 2 * (nextLength * nextLength);
				visit(startX + nextLength, startY, nextLength);
			}
			else
			{
				visitCount += 3 * (nextLength * nextLength);
				visit(startX + nextLength, startY + nextLength, nextLength);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int N;
	cin >> N >> r >> c;
	long int arrayLength = (long int) pow(2, N);
	visit(0, 0, arrayLength);
	cout << visitCount<<"\n";
	return 0;
}