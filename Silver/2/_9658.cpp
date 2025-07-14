#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	string* arr = new string[1001];
	arr[1] = "CY";
	arr[2] = "SK";
	arr[3] = "CY";
	arr[4] = "SK";
	arr[5] = "SK";
	arr[6] = "SK";
	arr[7] = "SK";
	for (int i = 8; i <= 1000; i++)
	{
		if (arr[i - 1] == "CY" || arr[i - 3] == "CY" || arr[i - 4] == "CY")
		{
			arr[i] = "SK";
		}
		else
		{
			arr[i] = "CY";
		}
	}
	cout << arr[N] << "\n";
	return 0;
}