#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int U, N;
	string name;
	int price;
	int lowPrice = 0;
	int lowPeople = 1000000;
	cin >> U >> N;
	vector<string>* arr = new vector<string>[U+1];
	for (int i = 0; i < N; i++)
	{
		cin >> name>>price;
		arr[price].push_back(name);
	}
	for (int i = 1; i < U+1; i++)
	{
		if (arr[i].size() != 0 && arr[i].size() < lowPeople)
		{
			lowPrice = i;
			lowPeople = arr[i].size();
		}
	}
	cout << arr[lowPrice].at(0) << " " << lowPrice << "\n";
	return 0;
}