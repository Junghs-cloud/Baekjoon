#include <iostream>
#include <algorithm>
using namespace std;
int* numbers;
int N, M;

void getHaveCards()
{
	cin >> N;
	numbers = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}
	sort(numbers, numbers + N);
}

void getFindCardsAndPrintCardNum()
{
	int findCardNum;
	cin >> M;
	int* cardNumCount = new int[M];
	for (int i = 0; i < M; i++)
	{
		cin >> findCardNum;
		int start = lower_bound(numbers, numbers + N, findCardNum) - numbers;
		int end = upper_bound(numbers, numbers + N, findCardNum) - numbers;
		cout << end - start << " ";
	}
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	getHaveCards();
	getFindCardsAndPrintCardNum();

	return 0;
}