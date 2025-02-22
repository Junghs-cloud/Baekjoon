#include <iostream>
using namespace std;
long long A, B, C;
long long X, Y, Z;
long long answer = 0;

void firstChange(long long& a, long long& b)
{
	long long first = min(a, b);
	a -= first;
	b -= first;
	answer += first;
}

void secondChange(long long& a, long long& b)
{
	long long second = min(a, b / 3);
	a -= second;
	b -= second * 3;
	answer += second;
}

void thirdChange(long long& a, long long& b)
{
	long long third = min(a, b / 9);
	a -= third;
	b -= third * 9;
	answer += third;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B >> C;
	cin >> X >> Y >> Z;
	firstChange(A, X);
	firstChange(B, Y);
	firstChange(C, Z);
	secondChange(C, Y);
	secondChange(B, X);
	secondChange(A, Z);
	thirdChange(A, Y);
	thirdChange(B, Z);
	thirdChange(C, X);
	cout << answer << "\n";
	return 0;
}