#include <iostream>
using namespace std;

double pow(double a)
{
	return a * a;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int w, h, x, y, p;
	int px, py;
	cin >> w >> h >> x >> y >> p;
	int answer = 0;
	double r = h / 2;
	for (int i = 0; i < p; i++)
	{
		cin >> px >> py;
		if (x <= px && px<= x + w && y <= py && py <= y + h)
		{
			answer++;
		}
		else if (pow(px-x) + pow(py-(y+r)) <= pow(r))
		{
			answer++;
		}
		else if ( pow(px-(x+w)) + pow(py-(y+r)) <= pow(r))
		{
			answer++;
		}
	}
	cout << answer << "\n";
	return 0;
}