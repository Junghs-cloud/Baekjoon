#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
char s[1000001];
int reverseCount;


int reverse()
{

	reverseCount = 0;
	
	if (s[0] == '0')
	{
		for (int i = 0; s[i+1] != '\0'; i++)
		{

			if ((s[i] == '0') && (s[i + 1] == '1'))
			{
				reverseCount++;
			}
		}
	}
	else
	{
		for (int i = 0; s[i+1] != '\0'; i++)
		{
			if ((s[i] == '1') && (s[i + 1] == '0'))
			{
				reverseCount++;
			}
		}

	}


	return reverseCount;
}

int main()
{
	scanf("%s", s);
	reverse();
	printf("%d\n", reverseCount);

	return 0;
}