import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
 
public class d {

	static FastScanner fs = new FastScanner ();
	static int ar[][] = new int[105][105];
	public static int get_Sun () {
		int sum = 0;
		for ( int i = 0 ; i < 105 ; ++i )
			for ( int j = 0 ; j < 105 ; ++j )
				sum += ar[i][j];
		return sum;
	}
	public static void solve () {
		int n = fs.nextInt();
		for ( int i = 0 ; i < 105 ; ++i )
			for ( int j = 0 ; j < 105 ; ++j )
				ar[i][j] = 0;
		while ( true ) {
			int x = fs.nextInt();
			int _x = fs.nextInt();
			int _y = fs.nextInt();
			for ( int i = x ; i < _x ; ++i )
				for ( int j = 0 ; j < _y ; ++j )
					ar[i][j] = 1;
			--n;
			if ( n == 0 ) break;
		}
		System.out.println(get_Sun());
	}
 
	public static void main(String[] args) {
		int t = fs.nextInt();
		while ( true ) {
			--t;
			solve ();
			if ( t == 0 ) break;
		}
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}

	}

}

