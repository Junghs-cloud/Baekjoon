#include <iostream>
#include <utility>
using namespace std;

int main()
{
	int N;
	int a, b;
	int correctCount = 0;
	int wrongCount = 0;
	cin >> N;
	pair<int, int>fox1 = make_pair(1, 3);
	pair<int, int> fox2 = make_pair(1, 4);
	pair<int, int> fox3 = make_pair(3, 4);
	for (int i = 0; i < N; i++)
	{
		pair<int, int> p;
		cin >> a >> b;
		if (a < b)
		{
			p = make_pair(a, b);
		}
		else
		{
			p = make_pair(b, a);
		}
		if (p == fox1 || p == fox2 || p == fox3)
		{
			correctCount++;
		}
		else
		{
			wrongCount++;
		}
	}
	if (correctCount == 3 && wrongCount==0)
	{
		cout << "Wa-pa-pa-pa-pa-pa-pow!\n";
	}
	else
	{
		cout << "Woof-meow-tweet-squeek\n";
	}
	return 0;
}