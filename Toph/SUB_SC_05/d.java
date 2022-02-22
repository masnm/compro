import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.HashMap;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

import java.math.BigInteger;
 
public class d {

	static BigInteger ar[] = new BigInteger[1024];
	static BigInteger one = new BigInteger("1");
	static BigInteger two = new BigInteger("2");
	static BigInteger md = new BigInteger ( "18446744073709551616" );
	static HashMap<BigInteger, BigInteger> mp = new HashMap<BigInteger, BigInteger>();

	static BigInteger calculate ( BigInteger i ) {
		if ( i.equals(one) )
			return one;
		else if ( mp.containsKey(i) ) {
			return mp.get(i);
		} else if ( i.mod(two).equals(one) ) {
			BigInteger dv = i.divide(two);
			BigInteger reca = calculate(dv);
			BigInteger recb = calculate(dv.add(one));
			BigInteger ans = reca.multiply(recb);
			ans = ans.add(new BigInteger("2"));
			ans = ans.mod(md);
			mp.put(i,ans);
			return ans;
		} else {
			BigInteger dv = i.divide(two);
			BigInteger reca = calculate(dv);
			BigInteger ans = reca.multiply(reca);
			ans = ans.add(new BigInteger("1"));
			ans = ans.mod(md);
			mp.put(i,ans);
			return ans;
		}
	}
 
	public static void main(String[] args) {
		FastScanner fs = new FastScanner ();
		int t = fs.nextInt();
		for ( int i = 0 ; i < t ; ++i ) {
			System.out.print ( "Case " + (i+1) + ": " );
			String n = fs.next();
			System.out.println ( calculate(new BigInteger(n)) );
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

