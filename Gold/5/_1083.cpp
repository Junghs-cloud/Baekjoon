#include <iostream>
using namespace std;
int* arr;

void swap(int index1, int index2)
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, S;
	int changeCount = 0;
	cin >> N;
	arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	cin >> S;
	for (int i = 0; i < N; i++)
	{
		int biggest = arr[i];
		int biggestIndex = i;
		for (int j = i; (j <= i + S &&  j < N); j++)
		{
			if (arr[j] > biggest)
			{
				biggest = arr[j];
				biggestIndex = j;
			}
		}
		while (biggestIndex != i)
		{
			swap(biggestIndex-1, biggestIndex);
			biggestIndex --;
			S--;
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}