import java.util.*;
public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Vector<String> car=new Vector<String>();
		Scanner scan=new Scanner(System.in);
		int N;
		int overtake=0;
		N=scan.nextInt();
		for (int i=0;i<N;i++)
		{
			String carName=scan.next();
			car.add(carName);
		}
		for (int i=0;i<N;i++)
		{
			String outCar=scan.next();
			int index=car.indexOf(outCar);
			if (index!=0)
			{
				overtake++;
			}
			car.remove(outCar);
		}
		System.out.println(overtake);
		scan.close();
	}

}