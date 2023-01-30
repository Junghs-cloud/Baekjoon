import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	int position[][];
	
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		Main m = new Main();
		m._11650();
	}
	
	public void _11650() throws NumberFormatException, IOException
	{
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int N = Integer.parseInt(br.readLine());
		position = new int[N][2];
		
		for (int i=0; i<N; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			position[i][0] = x;
			position[i][1] = y;
		}
		Arrays.sort(position, (pos1, pos2)->
		{
			if (pos1[0] == pos2[0])
			{
				return pos1[1] - pos2[1];
			}
			else
			{
				return pos1[0] - pos2[0];
			}
		}
		);
		for (int i=0;i<N;i++)
		{
			bw.write(position[i][0]+" "+position[i][1]+"\n");
		}
		bw.flush();
		bw.close();
	}
	
}
