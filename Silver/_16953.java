import java.util.Scanner;

public class Main {
	long A, B;
	long tempNum;
	int count = 0;
	
	public static void main(String[] args)
	{
		Main m = new Main();
		m._16945();
	}
	
	public void _16945()
	{
		Scanner scanner = new Scanner(System.in);
		A = scanner.nextInt();
		B = scanner.nextInt();
		divideFromB();
		System.out.println(count);
		scanner.close();
	}
	
	public void divideFromB()
	{
		tempNum = B;
		while (true)
		{
			String tempNumString = Long.toString(tempNum);
			int stringLength = tempNumString.length();
			if (tempNum % 2 == 0)
			{
				tempNum = tempNum / 2;
				count++;
			}
			else if (tempNumString.charAt(stringLength - 1) == '1')
			{
				tempNumString = tempNumString.substring(0, stringLength - 1);
				tempNum = Integer.parseInt(tempNumString);
				count++;
			}
			else
			{
				tempNum = tempNum / 2;
				count = -1;
				break;
			}
			if (tempNum == A)
			{
				count++;
				break;
			}
			if (tempNum < A)
			{
				count = -1;
				break;
			}
		}

	}
}
