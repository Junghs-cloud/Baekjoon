#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int answer = 0;
	int R, G, B;
	int biggest;
	cin >> R >> G >> B;
	answer += R / 3;
	answer += G / 3;
	answer += B / 3;
	R = R % 3;
	G = G % 3;
	B = B % 3;
	if ((R == 0 && G == 0 && B == 2) || (R == 2 && G == 0 && B == 0) || (R == 0 && G == 2 && B == 0))
	{
		biggest = 1;
	}
	else
	{
		biggest = max(B, max(R, G));
	}
	answer += biggest;
	cout << answer << "\n";
	return 0;
}