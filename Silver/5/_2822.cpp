#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main()
{
	int score;
	int sum = 0;
	vector<pair<int, int>> v;
	vector<int> quizNum;
	for (int i = 1; i <= 8; i++)
	{
		cin >> score;
		v.push_back(pair(-score, i));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < 5; i++)
	{
		sum -= v.at(i).first;
		quizNum.push_back(v.at(i).second);
	}
	sort(quizNum.begin(), quizNum.end());
	cout << sum << "\n";
	for (int i = 0; i < quizNum.size(); i++)
	{
		cout << quizNum.at(i)<<" ";
	}
	return 0;
}