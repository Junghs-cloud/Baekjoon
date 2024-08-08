#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int currentMovieNum = 0;
	long long currentNum = 666;
	while (true)
	{
		string str = to_string(currentNum);
		int index = str.find("666");
		if (index != string::npos)
		{
			currentMovieNum++;
			if (currentMovieNum == N)
			{
				cout << currentNum << "\n";
				break;
			}
		}
		currentNum++;
	}
	return 0;
}