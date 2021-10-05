import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.Arrays;
 
public class d {
 
	public static void main(String[] args) {
		FastScanner fs = new FastScanner ();
		int n = fs.nextInt (), W = fs.nextInt ();
		long dp[] = new long[W+1];
		int w;
		long v;
		while ( --n > -1 ) {
			w = fs.nextInt (); v = fs.nextLong ();
			for ( int i = W ; i >= w ; --i ) {
				dp[i] = Math.max ( dp[i], v+dp[i-w] );
			}
		}
		long mx = 0;
		for ( int i = 0 ; i <= W ; ++i ) mx = Math.max ( mx, dp[i] );
		System.out.println ( mx );
		// System.out.println ( "Hello Stupid!." );
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

