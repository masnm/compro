import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.Arrays;
 
public class e {
 
	public static void main(String[] args) {
		FastScanner fs = new FastScanner ();
		int n = fs.nextInt(), v;
		long W = fs.nextLong(), w;
		long inf = 1000000000000000005L;
		int limit = 1000 * 100 + 5;
		long dp[] = new long[limit];
		for ( int i = 0 ; i < limit ; ++i ) dp[i] = inf;
		dp[0] = 0;
		for ( long i = 0 ; i < n ; ++i ) {
			w = fs.nextLong();
			v = fs.nextInt();
			for ( int j = limit - 1 ; j >= v ; --j ) {
				dp[j] = Math.min ( dp[j], dp[j - v] + w );
			}
		}
		long ans = 0;
		for ( int i = 0 ; i < limit ; ++i ) {
			if ( dp[i] <= W ) {
				ans = Math.max ( ans, i );
			}
		}
		System.out.println ( ans );
		// for ( int i = 0 ; i < 20 ; ++i ) {
		// 	System.out.print ( dp[i] + " " );
		// }
		// System.out.println ( "" );
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

