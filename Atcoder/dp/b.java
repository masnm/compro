import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
 
public class b {
 
	public static void main(String[] args) {
		FastScanner fs = new FastScanner ();
		int n = fs.nextInt (), k = fs.nextInt ();
		int ar[] = new int[n+3];
		int dp[] = new int[n+3];
		for ( int i = 0 ; i < n ; ++i ) ar[i+1] = fs.nextInt ();
		for ( int i = 0 ; i < n ; ++i ) dp[i+1] = Integer.MAX_VALUE;
		dp[1] = 0;
		for ( int i = 1 ; i <= n ; ++i ) {
			for ( int x = 1 ; x <= k ; ++x ) {
				if ( i + x <= n ) {
					int t = Math.abs ( ar [ i + x ] - ar[i] );
					t += dp [ i ];
					dp[i + x] = Math.min ( dp[i + x], t );
				}
			}
			// for ( int j = 1 ; j <= n ; ++j ) System.out.print ( dp[j] + " " );
			// System.out.println ("");
		}
		System.out.println ( dp[n] );
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

