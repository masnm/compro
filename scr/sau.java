import java.util.Scanner;
 
public class sau {

	static class stack {
		int tos;
		int stck[];
		int si;
		stack ( int in_id[], int size ) {
			stck = new int[size+1];
			si = -1;
			for ( int i = 0 ; i < size ; ++i )
				this.push ( in_id[i] );
		}
		void push ( int val ) {
			si++;
			stck[si] = val;
		}
		boolean is_empty() {
			return si == -1;
		}
		int pop () {
			--si;
			return stck[si + 1];
		}
		void print_reverse ()
		{
			System.out.print ( "Printing id in reverse : " );
			while ( !this.is_empty () ) {
				System.out.print ( this.pop() + " " );
			}
		}
	}
 
	public static void main(String[] args) {
		Scanner s = new Scanner ( System.in );
		int id = 10839234;
		int size = 1, val = 9;
		while ( val < id ) {
			val *= 10;
			val += 9;
			++size;
		}
		int ar[] = new int[size];
		int ind = size - 1;
		while ( id > 0 ) {
			int tv = id % 10;
			id /= 10;
			ar[ind] = tv;
			--ind;
		}
		stack st = new stack (ar, size );
		st.print_reverse ();
	}

}

