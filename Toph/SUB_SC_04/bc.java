import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
 
public class bc {
 
	public static void main(String[] args) {
		FastScanner fs = new FastScanner ();
		int t;
		while ( t-- ) {
			int n = fs.nextInt(), m = fs.nextInt();
			long ar[] = new long[n];
			for ( int i = 0 ; i < n ; ++i ) {
				ar[i] = fs.nextInt();
			}
			sort(ar);
			Boolean af = false;
			for ( int i = 0 ; i < n ; ++i ) {
				if ( ar[i] * m > sum ) {
					af = true;
					System.out.println(ar[i])
		}
		// System.out.println ( "Hello Stupid!." );
	}

	static void sort(long[] a) {
		ArrayList<Long> l=new ArrayList<>();
		for (long i:a) l.add(i);
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

