#include <iostream>
using namespace std;
int dir;
int x;
int y;

void move(int t)
{
	if (dir == 1)
	{
		x += t;
	}
	else if (dir == 3)
	{
		x -= t;
	}
	else if (dir == 4)
	{
		y += t;
	}
	else
	{
		y -= t;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, T;
	x = 0;
	y = 0;
	dir = 1; //right=1, down=2, left=3, up=4
	int lastT = 0;
	int t;
	string change;
	cin >> N >> T;
	for (int i = 0; i < N; i++)
	{
		cin >> t >> change;
		move(t-lastT);
		if (change == "left")
		{
			dir--;
			if (dir <= 0)
			{
				dir = 4;
			}
		}
		else
		{
			dir++;
			if (dir >= 5)
			{
				dir = 1;
			}
		}
		lastT = t;
	}
	move(T-lastT);
	cout << x << " " << y << "\n";
	return 0;
}