#include <iostream>
using namespace std;

int main()
{
	string schoolName;
	cin >> schoolName;
	if (schoolName == "NLCS")
	{
		cout << "North London Collegiate School" << "\n";
	}
	else if (schoolName == "BHA")
	{
		cout << "Branksome Hall Asia"<<"\n";
	}
	else if (schoolName == "KIS")
	{
		cout << "Korea International School" << "\n";
	}
	else
	{
		cout << "St. Johnsbury Academy" << "\n";
	}
	return 0;
}