#include <iostream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{

	int N;
	int currentResult = 0;
	int operatorCount = 0;
	int cCount = 0;
	bool isInNumber = false;
	int numberLength = 0;
	vector<int>::iterator nextPos;
	vector<int> operandVec;
	vector<char> operatorVec;
	string str;
	cin >> N;
	cin >> str;
	string tempOperand = "\0";
	for (int i = 0; i < (signed) str.length(); i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			tempOperand.append(1, str[i]);
		}
		else
		{
			if (str[i] == 'C')
			{
				cCount++;
			}
			if (tempOperand.length() != 0)
			{
				int operand = stoi(tempOperand);
				operandVec.push_back(operand);
				operatorCount++;
				tempOperand = "\0";
			}
			operatorVec.push_back(str[i]);
		}
	}
	
	if (cCount == 0)
	{
		cout << "NO OUTPUT";
	}
	else
	{
		nextPos = operandVec.begin();
		currentResult = *nextPos;
		nextPos++;
		int tempCCount = 0;
		for (int i = 0; i < (signed) operatorVec.size(); i++)
		{
			char currentOperator = operatorVec.at(i);
			if (currentOperator == 'C')
			{
				cout << currentResult << " ";
				tempCCount++;
				if (cCount == tempCCount)
				{
					break;
				}
			}
			else
			{
				if (nextPos != operandVec.end())
				{
					if (currentOperator == 'S')
					{
						currentResult -= (*nextPos);
					}
					else if (currentOperator == 'M')
					{
						currentResult *= (*nextPos);
					}
					else if (currentOperator == 'U')
					{
						currentResult /= (*nextPos);
					}
					else if (currentOperator == 'P')
					{
						currentResult += (*nextPos);
					}
					nextPos++;
				}
			}

		}
	}
	cout << "\n";
	
	return 0;
}