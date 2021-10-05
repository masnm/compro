import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.Random;
 
public class c {
 
	public static void main(String[] args) {
		FastScanner fs = new FastScanner ();
		int n = fs.nextInt ();
		int inf = 1000000005;
		int dp[][] = new int[n+1][3];
		int ar[][] = new int[n+1][3];
		//for ( int i = 0 ; i < n + 1 ; ++i ) {
		//	dp[i][0] = dp[i][1] = dp[i][2] = inf;
		//}
		for ( int i = 0 ; i < n ; ++i ) {
			for ( int j = 0 ; j < 3 ; ++j ) {
				ar[i][j] = fs.nextInt ();
			}
		}
		for ( int i = 0 ; i < 3 ; ++i ) {
			dp[0][i] = ar[0][i];
		}
		for ( int i = 1 ; i < n + 1 ; ++i ) {
			for ( int j = 0 ; j < 3 ; ++j ) {
				for ( int k = 0 ; k < 3 ; ++k ) {
					if ( j == k ) continue;
					dp[i][j] = Math.max ( dp[i][j], ar[i][j] + dp[i-1][k] );
				}
			}
			// for ( int x = 0 ; x < 3 ; ++x ) {
			// 	System.out.print ( dp[i][x] + " " );
			// }
			// System.out.println ("");
		}
		int x = 0;
		for ( int i = 0 ; i < 3 ; ++i ) x = Math.max ( x, dp[n][i] );
		System.out.println ( x );
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

