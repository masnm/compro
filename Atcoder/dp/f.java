import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
 
public class f {
 
	public static void main(String[] args) {
		FastScanner fs = new FastScanner ();
		String s = " " + fs.next ();
		String t = " " + fs.next ();
		int row = s.length(), col = t.length();
		int dp[][] = new int[row][col];
		char dir[][] = new char[row][col];
		for ( int i = 0 ; i < row ; ++i ) dp[i][0] = 0;
		for ( int i = 0 ; i < col ; ++i ) dp[0][i] = 0;
		for ( int i = 1 ; i < row ; ++i ) {
			for ( int j = 1 ; j < col ; ++j ) {
				if ( s.charAt(i) == t.charAt(j) ) {
					dp[i][j] = 1 + dp[i-1][j-1];
					dir[i][j] = 'Q';
				} else {
					dp[i][j] = Math.max ( dp[i-1][j], dp[i][j-1] );
					if ( dp[i-1][j] > dp[i][j-1] ) dir[i][j] = 'U';
					else dir[i][j] = 'L';
				}
			}
		}
		String ans = "";
		int si = row-1, sj = col-1;
		while ( true ) {
			if ( si == 0 || sj == 0 ) break;
			if ( dir[si][sj] == 'Q' ) ans += s.charAt(si);
			if ( dir[si][sj] == 'Q' ) { --si; --sj; }
			else if ( dir[si][sj] == 'U' ) { --si; }
			else --sj;
		}
		String rs = new StringBuffer(ans).reverse().toString();
		System.out.println ( rs );
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

