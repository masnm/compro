import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;
 
public class e {

	public static FastScanner fs = new FastScanner ();

	public static void solve () {
		String _a = fs.next(), _b = fs.next();
		BigInteger n = new BigInteger(_a), k = new BigInteger(_b);
		BigInteger low = n.add(BigInteger.valueOf(1));
		BigInteger high = n.multiply(k);
		BigInteger x = n.sqrt();
		BigInteger itr = new BigInteger("2");
		BigInteger one = new BigInteger("1");
		BigInteger zero = new BigInteger("0");
		HashSet<BigInteger> hs = new HashSet<BigInteger>();
		while ( itr.compareTo(x) < 1 ) {
			if ( n.mod(itr).equals(zero) ) {
				BigInteger div = n.divide(itr);
				while ( true ) {
					BigInteger ml = div.multiply(itr);
					if ( ml.compareTo(high) > 0 ) break;
					if ( ml.compareTo(low) > 0 ) hs.add(ml);
					div = div.add(one);
				}
			}
			itr = itr.add(one);
		}
		BigInteger sz = BigInteger.valueOf(hs.size());
		high = high.subtract(low);
		System.out.println(high.subtract(sz));
	}
 
	public static void main(String[] args) {
		int t = fs.nextInt();
		for ( int i = 0 ; i < t ; ++i )
			solve();
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

