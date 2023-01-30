import java.util.Scanner;
import java.util.*;

public class Main {
	String expression;
	List<Integer> operand;
	List<Integer> mid;
	List<Character> operator;
	
	public static void main(String[] args)
	{
		Main m = new Main();
		m._1541();
	}
	
	public void _1541()
	{
		Scanner scanner = new Scanner(System.in);
		int lastPosition = 0;
		expression = scanner.nextLine();
		operand = new ArrayList<Integer>();
		operator = new ArrayList<Character>();
		mid = new ArrayList<Integer>();
		
		for (int i = 0; i < expression.length() ; i++)
		{
			if (expression.charAt(i)=='-' || expression.charAt(i)=='+')
			{
				makeOperand(lastPosition, i-1);
				operator.add(expression.charAt(i));
				lastPosition = i+1;
			}
		}
		makeOperand(lastPosition, expression.length()-1);
		
		lastPosition = 0;
		for (int i = 0; i < operator.size(); i++)
		{
			if (operator.get(i) == '-')
			{
				makeMidSum(lastPosition, i);
				lastPosition = i + 1;
			}
		}
		makeMidSum(lastPosition, operator.size());
		
		int finalSum = mid.get(0);
		for (int i = 1; i <mid.size(); i++)
		{
			finalSum -= mid.get(i);
		}
		System.out.println(finalSum);
		scanner.close();
	}
	
	public void makeOperand(int biggest, int smallest)
	{
		int j = 1;
		int number = 0;
		for (int i = smallest; i>= biggest; i--)
		{
			number += j*(expression.charAt(i)-48);
			j *= 10;
		}
		operand.add(number);
	}
	
	public void makeMidSum(int position1, int position2)
	{
		int n = 0;
		for (int i = position1; i <= position2; i++)
		{
			n += operand.get(i);
		}
		mid.add(n);
	}
	
}
