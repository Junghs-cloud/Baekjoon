#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int S, P;
	string DNA;
	int A, C, T, G;
	int strA=0;
	int strC = 0;
	int strT = 0;
	int strG = 0;
	int passwordCount = 0;
	cin >> S >> P;
	cin >> DNA;
	cin >> A >> C >> G >> T;
	for (int i = 0; i < P; i++)
	{
		if (DNA[i] == 'A')
		{
			strA++;
		}
		else if (DNA[i] == 'C')
		{
			strC++;
		}
		else if (DNA[i] == 'T')
		{
			strT++;
		}
		else
		{
			strG++;
		}
	}
	if (strA >= A && strC >= C && strT >= T && strG >= G)
	{
		passwordCount++;
	}
	for (int i = P; i < S; i++)
	{
		if (DNA[i] == 'A')
		{
			strA++;
		}
		else if (DNA[i] == 'C')
		{
			strC++;
		}
		else if (DNA[i] == 'T')
		{
			strT++;
		}
		else
		{
			strG++;
		}
		if (DNA[i - P] == 'A')
		{
			strA--;
		}
		else if (DNA[i - P] == 'C')
		{
			strC--;
		}
		else if (DNA[i - P] == 'T')
		{
			strT--;
		}
		else
		{
			strG--;
		}
		if (strA >= A && strC >= C && strT >= T && strG >= G)
		{
			passwordCount++;
		}
	}
	cout << passwordCount << "\n";
	return 0;
}