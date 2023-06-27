import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
	ArrayList<Integer> intList;
	
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		Main m = new Main();
		m._2751();
	}
	
	public void _2751() throws NumberFormatException, IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		intList = new ArrayList<Integer>();
		
		int N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++)
		{
			int nextInt = Integer.parseInt(br.readLine());
			intList.add(nextInt);
		}
		Collections.sort(intList);
		for (int i = 0; i < intList.size(); i++)
		{
			bw.write(intList.get(i)+"\n");
		}
		bw.flush();
		bw.close();
	}
}
