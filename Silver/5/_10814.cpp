#include <iostream>
#include <algorithm>
using namespace std;

struct person
{
	int age=0;
	string name = "";
	int joinNum = 0;
};

bool compare(const person& p1, const person& p2)
{
	if (p1.age < p2.age)
	{
		return true;
	}
	else if (p1.age == p2.age)
	{
		return p1.joinNum < p2.joinNum;
	}
	else
	{
		return false;
	}
}

int main()
{
	int N;
	cin >> N;
	person* arr = new person[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].age >> arr[i].name;
		arr[i].joinNum = i + 1;
	}
	sort(arr, arr + N, compare);
	for (int i = 0; i < N; i++)
	{
		cout << arr[i].age <<" "<< arr[i].name <<"\n";
	}
	return 0;
}