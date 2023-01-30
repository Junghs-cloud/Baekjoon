import java.util.Scanner;

public class Main {
	int paper[][];
	int white;
	int blue;
	
	public static void main(String[] args)
	{
		Main m = new Main();
		m._2630();
	}
	
	public void _2630()
	{
		Scanner scanner=new Scanner(System.in);
		int N = scanner.nextInt();
		paper = new int[N][N];
		white = 0;
		blue = 0;
		for (int i = 0 ; i < N ; i++)
		{
			for (int j = 0 ; j < N ; j++)
			{
				paper[i][j] = scanner.nextInt();
			}
		}
		divide(0, 0, N);
		System.out.println(white);
		System.out.println(blue);
		scanner.close();
	}
	
	public void divide(int posX, int posY, int length)
	{
		int nextLength=length/2;
		int testNumber=paper[posX][posY];
		boolean isAllSame=true;
		
		for (int i = posX ; i < posX + length ; i++)
		{
			for (int j=posY ; j < posY + length; j++)
			{
				if (paper[i][j]!=testNumber)
				{
					isAllSame=false;
				}
			}
		}
		if (isAllSame == true)
		{
			if (testNumber==0)
			{
				white++;
			}
			else
			{
				blue++;
			}
		}
		else
		{
			divide(posX, posY, nextLength);
			divide(posX, posY+nextLength, nextLength);
			divide(posX+nextLength, posY, nextLength);
			divide(posX+nextLength, posY+nextLength, nextLength);
		}
	}

}
