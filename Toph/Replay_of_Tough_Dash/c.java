import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.util.*;
 
public class c {

    public static int getLastDigit ( String s ) {
        return (int)(s.charAt(s.length()-1)-(int)'0');
    }
 
	public static void main(String[] args) {
		FastScanner fs = new FastScanner ();
        String l = fs.next(), r = fs.next();
        int ll = getLastDigit ( l ), rr = getLastDigit ( r );
        if ( ll % 2 == rr % 2 ) {
            System.out.print ( "Black" );
        } else {
            System.out.print ( "White" );
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

